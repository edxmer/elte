using KiralysagBeadando;
using System;
using System.Collections.Generic;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace KiralysagBeadando.Tests;

#pragma warning disable MSTEST0037

[TestClass]
public sealed class Test1
{
    // Konstruktor tesztek:
    [TestMethod]
    public void Kiralysag_Letrehozas_NullaTartomannyal_KiveteltDob()
    {
        List<Lovag> lovagok = [new BatorLovag("Bátor a vakmerő kutya")];
        List<Tartomany> tartomanyok = [];

        Exception e = Assert.Throws<Exception>(() => new Kiralysag(lovagok, tartomanyok));
        Assert.AreEqual("Szükséges legalább 1 tartomány.", e.Message);
    }

    [TestMethod]
    public void Kiralysag_Letrehozas_NemKiralyiElsoTartomannyal_KiveteltDob()
    {
        List<Lovag> lovagok = [new BatorLovag("Bátor a vakmerő kutya kettő")];
        List<Tartomany> tartomanyok = [new SemlegesTartomany("Pacifista Miskolc")];

        Exception e = Assert.Throws<Exception>(() => new Kiralysag(lovagok, tartomanyok));
        Assert.AreEqual("Az első tartománynak királyi tartománynak kell lennie.", e.Message);
    }

    [TestMethod]
    public void Kiralysag_Letrehozas_HelyesAdatokkal_Sikeres()
    {
        List<Lovag> lovagok = [new BatorLovag("Bátor a helyesebb kutya")];
        List<Tartomany> tartomanyok = [new KiralyiTartomany("Királyi Miskolc"), new EllensegesTartomany("Gonosz Miskolc")];

        Kiralysag k = new(lovagok, tartomanyok);

        Assert.AreEqual(1, k.lovagok.Count);
        Assert.AreEqual(2, k.tartomanyok.Count);
    }

    // Állapotok vizsgálata
    [TestMethod]
    public void Kiralysag_Befejezodott_NullaEloLovag_JatekVege()
    {
        List<Lovag> lovagok = [];
        List<Tartomany> tartomanyok = [new KiralyiTartomany("Királyi Miskolc"), new EllensegesTartomany("Gonosz Miskolc")];

        Kiralysag k = new(lovagok, tartomanyok);

        Assert.IsTrue(k.Befejezodott());
    }

    [TestMethod]
    public void Kiralysag_Befejezodott_NullaEllensegesTartomany_JatekVege()
    {
        List<Lovag> lovagok = [new BatorLovag("Bátor bátor bátor ször ször bátor")];
        List<Tartomany> tartomanyok = [new KiralyiTartomany("Királyi Miskolc"), new SemlegesTartomany("Gonosz Miskolc")];

        Kiralysag k = new(lovagok, tartomanyok);

        Assert.IsTrue(k.Befejezodott());
    }

    [TestMethod]
    public void Kiralysag_Befejezodott_VanMinden_Folyamatban()
    {
        List<Lovag> lovagok = [new BatorLovag("Bátor bátor bátor ször ször bátor")];
        List<Tartomany> tartomanyok = [new KiralyiTartomany("Királyi Miskolc"), new EllensegesTartomany("Gonosz Miskolc")];

        Kiralysag k = new(lovagok, tartomanyok);

        Assert.IsFalse(k.Befejezodott());
    }

    [TestMethod]
    public void Kiralysag_EllensegesTartomanyokSzama_EgyEllensegesTartomany()
    {
        List<Lovag> lovagok = [new BatorLovag("Bátor bátor bátor ször ször bátor")];
        List<Tartomany> tartomanyok = [
            new KiralyiTartomany("Királyi Miskolc"),
            new EllensegesTartomany("Gonosz Miskolc"),
        ];

        Kiralysag k = new(lovagok, tartomanyok);

        Assert.AreEqual(1, k.EllensegesTartomanyokSzama());
    }

    [TestMethod]
    public void Kiralysag_EllensegesTartomanyokSzama_TobbEllensegesTartomany()
    {
        List<Lovag> lovagok = [new BatorLovag("Bátor bátor bátor ször ször bátor")];
        List<Tartomany> tartomanyok = [
            new KiralyiTartomany("Királyi Miskolc"),
            new EllensegesTartomany("Gonosz Miskolc"),
            new EllensegesTartomany("Gonoszabb Miskolc")
        ];

        Kiralysag k = new(lovagok, tartomanyok);

        Assert.AreEqual(2, k.EllensegesTartomanyokSzama());
    }

    [TestMethod]
    public void Kiralysag_EloLovagokSzama_EgyEloLovag()
    {
        List<Lovag> lovagok = [
            new BatorLovag("Bátor bátor bátor ször ször bátor")
        ];
        List<Tartomany> tartomanyok = [
            new KiralyiTartomany("Királyi Miskolc"),
            new EllensegesTartomany("Gonosz Miskolc"),
        ];

        Kiralysag k = new(lovagok, tartomanyok);

        Assert.AreEqual(1, k.EloLovagokSzama());
    }

    [TestMethod]
    public void Kiralysag_EloLovagokSzama_TobbEloLovag()
    {
        List<Lovag> lovagok = [
            new BatorLovag("Bátor bátor bátor ször ször bátor"),
            new OvatosLovag("óóóóóóvatos")
        ];
        List<Tartomany> tartomanyok = [
            new KiralyiTartomany("Királyi Miskolc"),
            new EllensegesTartomany("Gonosz Miskolc"),
        ];

        Kiralysag k = new(lovagok, tartomanyok);

        Assert.AreEqual(2, k.EloLovagokSzama());
    }
}
