using System;

namespace HF07;

public class Card
{
    public string CardNo { get; private set; }
    private string pinCode;

    public Card(string cardNo, string pinCode)
    {
        CardNo = cardNo;
        this.pinCode = pinCode;
    }

    public bool PinCheck(string pin)                    { return pin == pinCode; }
    public void SetPin(string oldPin, string newPin)    { if (oldPin == pinCode) pinCode = newPin; }

}