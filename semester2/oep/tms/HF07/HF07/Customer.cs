using System;

namespace HF07;

public class Customer
{
    private string name;
    private string pin;
    private int needMoney;
    private List<Card> cards = new();

    public Customer(string name, string pin)
    {
        this.name = name;
        this.pin = pin;
    }

    public void Withdraw(ATM atm)   { atm.Process(this); }

    public void TakeCard(Card card) { cards.Add(card); }

    public void NeedMoney(int m)    { needMoney = m; }

    public Card GiveCard()
    {
        if (!(cards.Count > 0)) throw new Exception("Length of cards must be positive.");
        return cards[0];
    }

    public string GivePin() { return pin; }

    public int AskMoney()   { return needMoney; }
}