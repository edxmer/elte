using System;
using System.Runtime.InteropServices;
using System.Security.Principal;

namespace HF07;

public class Center
{
    private List<Bank> banks;

    public Center(List<Bank> b) { banks = b; }

    public bool Transaction(string cardNo, int a)
    {
        Bank? bank = banks.FirstOrDefault(b => b.HasAccount(cardNo));
        
        return (bank != null) && bank.Transaction(cardNo, a);
    }

    public int GetBalance(string accountNum)
    {
        Bank? bank = banks.FirstOrDefault(b => b.CheckAccount(accountNum));

        if (bank != null)   { return bank.GetBalance(accountNum); }
        else                { return -1; }
        
    } 

}