using System;
using System.Threading.Channels;

namespace HF07;

public class Account
{
    public int Balance { get; private set; }
    public string AccountNo { get; private set; }
    private List<Card> cards = new();

    public Account(string n)
    {
        AccountNo = n;
        Balance = 0;
    }

    public void AddCard(Card card) { cards.Add(card); }

    public bool Modify(int a)
    {
        if (Balance + a < 0) return false;
        Balance += a;
        return true;
    }

    public bool HasCard(string cardNo)
    {
        return cards.Any(c => c.CardNo == cardNo);
    }



}