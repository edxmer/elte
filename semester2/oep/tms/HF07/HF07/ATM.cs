using System;
using System.ComponentModel.Design;
using System.Security.Cryptography;

namespace HF07;

public class ATM
{
    private string location;
    private Center center;

    public ATM(string l, Center c)
    {
        location = l;
        center = c;
    }

    public void Process(Customer c)
    {
        Card card = c.GiveCard();
        if (!card.PinCheck(c.GivePin())) throw new Exception("Invalid PIN.");
        int a = c.AskMoney();
        if (!center.Transaction(card.CardNo, -a)) throw new Exception("Invalid transaction.");
    }

}