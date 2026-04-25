using System;

namespace HF07;

public class Bank
{
    private List<Customer> customers = new();
    private List<Account> accounts = new();

    public Account CreateAccount(Customer c, string accountNo)
    {
        Account acc = new(accountNo);
        customers.Add(c);
        accounts.Add(acc);
        return acc;
    }

    public Card CreateCard(Customer c, Account a, string cardNo, string pin)
    {
        if (a == null) throw new Exception("Account is null.");
        if (!customers.Contains(c) || !accounts.Contains(a)) throw new Exception("Customers or accounts list does not contain the requested element.");
        
        Card card = new(cardNo, pin);
        a.AddCard(card);
        return card;
    }

    public bool HasAccount(string cardNo) { return accounts.Any(a => a.HasCard(cardNo)); }
    public int GetBalance(string accNum)
    {
        Account? acc = accounts.FirstOrDefault(a => a.AccountNo == accNum);

        if (acc != null)    { return acc.Balance; }
        else                { return -1; }
    }

    public bool CheckAccount(string accNum) { return accounts.Any(a => a.AccountNo == accNum); }

    public bool Transaction(string cardNo, int a)
    {
        Account? acc = accounts.FirstOrDefault(a => a.HasCard(cardNo));
        return (acc != null) && acc.Modify(a);
    }
}