using System;
using System.Collections.Generic;

namespace HF07
{
    internal class Program
    {
        private static int passed = 0;
        private static int failed = 0;

        static void Main(string[] args)
        {
            TestAccount();
            TestCard();
            TestCustomer();
            TestBank();
            TestCenter();
            TestATM();

            Console.WriteLine($"\nSummary: {passed} passed, {failed} failed.");
        }

        private static void Assert(bool condition, string testName)
        {
            if (condition)
            {
                passed++;
                Console.WriteLine($"[PASS] {testName}");
            }
            else
            {
                failed++;
                Console.WriteLine($"[FAIL] {testName}");
            }
        }

        private static void AssertThrows<TException>(Action action, string testName) where TException : Exception
        {
            try
            {
                action();
                failed++;
                Console.WriteLine($"[FAIL] {testName} - no exception was thrown");
            }
            catch (TException)
            {
                passed++;
                Console.WriteLine($"[PASS] {testName}");
            }
            catch (Exception ex)
            {
                failed++;
                Console.WriteLine($"[FAIL] {testName} - wrong exception: {ex.GetType().Name}");
            }
        }

        private static void TestAccount()
        {
            Console.WriteLine("--- Account tests ---");

            Account account = new Account("ACC-001");
            Card card = new Card("CARD-001", "1234");

            Assert(account.AccountNo == "ACC-001", "Account constructor stores account number");
            Assert(account.Balance == 0, "New account balance is 0");

            account.AddCard(card);
            Assert(account.HasCard("CARD-001"), "Added card can be found in account");
            Assert(!account.HasCard("CARD-XYZ"), "Unknown card is not found in account");

            Assert(account.Modify(1000), "Positive transaction succeeds");
            Assert(account.Balance == 1000, "Deposit changes balance correctly");

            Assert(account.Modify(-300), "Withdrawal within balance succeeds");
            Assert(account.Balance == 700, "Withdrawal decreases balance correctly");

            Assert(!account.Modify(-800), "Withdrawal above balance fails");
            Assert(account.Balance == 700, "Failed withdrawal keeps original balance");

            Console.WriteLine();
        }

        private static void TestCard()
        {
            Console.WriteLine("--- Card tests ---");

            Card card = new Card("CARD-002", "1111");

            Assert(card.CardNo == "CARD-002", "Card constructor stores card number");
            Assert(card.PinCheck("1111"), "PinCheck accepts correct PIN");
            Assert(!card.PinCheck("2222"), "PinCheck rejects incorrect PIN");

            card.SetPin("9999", "3333");
            Assert(!card.PinCheck("3333"), "PIN does not change with wrong old PIN");

            card.SetPin("1111", "3333");
            Assert(card.PinCheck("3333"), "PIN changes with correct old PIN");

            Console.WriteLine();
        }

        private static void TestCustomer()
        {
            Console.WriteLine("--- Customer tests ---");

            Customer customer = new Customer("Alice", "1234");
            Card card = new Card("CARD-003", "1234");

            Assert(customer.GivePin() == "1234", "Customer returns stored PIN");

            customer.NeedMoney(250);
            Assert(customer.AskMoney() == 250, "Customer returns requested amount");

            AssertThrows<Exception>(() =>
            {
                Customer c = new Customer("Bob", "4321");
                c.GiveCard();
            }, "Customer without card throws NoCardException");

            customer.TakeCard(card);
            Assert(ReferenceEquals(customer.GiveCard(), card), "Customer returns the taken card");

            Console.WriteLine();
        }

        private static void TestBank()
        {
            Console.WriteLine("--- Bank tests ---");

            Bank bank = new Bank();
            Customer customer = new Customer("Alice", "1234");

            Account account = bank.CreateAccount(customer, "ACC-002");
            Card card = new Card("CARD-004", "1234");
            account.AddCard(card);
            customer.TakeCard(card);

            Assert(account.AccountNo == "ACC-002", "Bank.CreateAccount creates account with correct number");
            Assert(bank.CheckAccount("ACC-002"), "Bank.CheckAccount finds created account");
            Assert(bank.GetBalance("ACC-002") == 0, "Newly created bank account has 0 balance");

            Assert(bank.Transaction("CARD-004", 500), "Bank transaction can deposit money through card number");
            Assert(bank.GetBalance("ACC-002") == 500, "Bank deposit changes balance correctly");

            Assert(bank.Transaction("CARD-004", -200), "Bank transaction can withdraw within balance");
            Assert(bank.GetBalance("ACC-002") == 300, "Bank withdrawal changes balance correctly");

            Assert(!bank.Transaction("CARD-004", -400), "Bank rejects withdrawal above balance");
            Assert(bank.GetBalance("ACC-002") == 300, "Rejected withdrawal leaves balance unchanged");

            Assert(!bank.Transaction("CARD-NOPE", 100), "Bank transaction fails for non-existing card");
            Assert(bank.GetBalance("NO-ACCOUNT") == -1, "GetBalance returns -1 for missing account");

            Console.WriteLine();
        }

        private static void TestCenter()
        {
            Console.WriteLine("--- Center tests ---");

            Bank bank1 = new Bank();
            Bank bank2 = new Bank();
            Center center = new Center(new List<Bank> { bank1, bank2 });

            Customer customer = new Customer("Carol", "5555");
            Account account = bank2.CreateAccount(customer, "ACC-003");
            Card card = new Card("CARD-005", "5555");
            account.AddCard(card);
            customer.TakeCard(card);

            Assert(center.GetBalance("ACC-003") == 0, "Center.GetBalance finds account in the correct bank");
            Assert(center.Transaction("CARD-005", 1200), "Center.Transaction forwards deposit to correct bank");
            Assert(center.GetBalance("ACC-003") == 1200, "Center deposit changes balance correctly");
            Assert(center.Transaction("CARD-005", -700), "Center.Transaction forwards withdrawal to correct bank");
            Assert(center.GetBalance("ACC-003") == 500, "Center withdrawal changes balance correctly");

            Assert(!center.Transaction("CARD-UNKNOWN", 10), "Center.Transaction fails for unknown card");
            Assert(center.GetBalance("ACC-UNKNOWN") == -1, "Center.GetBalance returns -1 for unknown account");

            Console.WriteLine();
        }

        private static void TestATM()
        {
            Console.WriteLine("--- ATM tests ---");

            Bank bank = new Bank();
            Center center = new Center(new List<Bank> { bank });
            ATM atm = new ATM("Budapest", center);

            Customer customer = new Customer("David", "2468");
            Account account = bank.CreateAccount(customer, "ACC-004");
            Card card = new Card("CARD-006", "2468");
            account.AddCard(card);
            customer.TakeCard(card);
            bank.Transaction("CARD-006", 1000);

            customer.NeedMoney(400);
            atm.Process(customer);
            Assert(bank.GetBalance("ACC-004") == 600, "ATM.Process withdraws money with valid PIN and sufficient balance");

            Customer wrongPinCustomer = new Customer("Eve", "0000");
            wrongPinCustomer.TakeCard(card);
            wrongPinCustomer.NeedMoney(100);
            AssertThrows<Exception>(() => atm.Process(wrongPinCustomer),
                "ATM throws WrongPinCodeException for invalid PIN");

            Customer tooMuchCustomer = new Customer("Frank", "2468");
            tooMuchCustomer.TakeCard(card);
            tooMuchCustomer.NeedMoney(5000);
            AssertThrows<Exception>(() => atm.Process(tooMuchCustomer),
                "ATM throws FewMoneyException when balance is insufficient");

            Assert(bank.GetBalance("ACC-004") == 600, "Failed ATM transactions do not change balance");

            Console.WriteLine();
        }
    }
}
