namespace JogTesztelo;

#pragma warning disable IDE0305

public class Quiz
{
    private static readonly string basePath = AppDomain.CurrentDomain.BaseDirectory;
    
    private static readonly string nt = File.ReadAllText(Path.Combine(basePath, "Resources", "nt.txt"));
    private static readonly string nt_closed = File.ReadAllText(Path.Combine(basePath, "Resources", "nt-closed.txt"));

    private static readonly string[] nt_win = [
        File.ReadAllText(Path.Combine(basePath, "Resources", "nt-scared.txt")),
        File.ReadAllText(Path.Combine(basePath, "Resources", "nt-shocked.txt")),
    ];
    private static readonly string[] nt_win_taunts = [
        "AARGHHHH! MY PRECIOUS POLGÁRI SZEMÉLYIJOG",
        "AZ ORSZÁGGYŰLÉSIT NEKI!",
        "AZ ÉDES BÜRÖKRÁCIÁMM!! NEEEE!!!",
        "BÜDÖS INFORMATIKUS! TÁVOZZ A BÜNTETŐJOGI KISKÖNYVEMTŐL!!!",
        "ERRŐL MÉG A TÁRGYALÁSON HALLANI FOGSZ!",
    ];

    private static readonly string[] nt_lose = [
        File.ReadAllText(Path.Combine(basePath, "Resources", "nt-evil.txt")),
        File.ReadAllText(Path.Combine(basePath, "Resources", "nt-gleeful.txt")),
    ];
    private static readonly string[] nt_lose_taunts = [
        "ÉLJEN A BÜROKRÁCIAAA!!!",
        "ENNYIT TUDSZ??!?",
        "AZ ÉDES BÜROKRÁCIÁM ROMMÁ VER TÉGED, JOGTALAN KUTYA!",
        "A 30 KILÓS BÜNTETŐJOGI KÓDEXEMMEL ROMMÁ VERLEK, KUTYAAAA",
        "A BÜNTETŐJOG LESÚJT RÁD, BŰNÖZŐ",
    ];

    private static readonly Random rand = new();


    private List<Question> questions = [];
    private int current = 0;
    private int correct = 0;
    private int incorrect = 0;

    
    public bool HasNextQuestion() { return current < questions.Count; }

    public void NextQuestion()
    {
        Question q = questions[current];
        Console.Clear();
        PrintStatus();

        q.Print();
        bool isCorrect = true;
        bool validResponse;
        do
        {
            try
            {
                isCorrect = q.AwaitResponse();
                validResponse = true;
            }
            catch (FormatException)
            {
                Console.WriteLine("Hibás bemenet!");
                validResponse = false;
            }

        }
        while (!validResponse);

        PrintIntermission();

        if (isCorrect)
        {
            ++correct;
            PrintWinningResponse(q);
        }
        else
        {
            ++incorrect;
            PrintLosingResponse(q);
        }

        ++current;
        Console.ReadLine();
    }

    public void DisplayResults()
    {
        Console.WriteLine($"A végső eredményed: {correct}/{incorrect}");
        Console.WriteLine(nt_win[rand.Next(0, nt_win.Length)]);
    }

    public void Shuffle()
    {
        questions = questions.Shuffle().ToList();
    }

    private void PrintStatus()
    {
        Console.WriteLine($"{correct}/{correct+incorrect}\n");
    }
    
    private static void PrintIntermission()
    {
        Console.Clear();
        Console.WriteLine(nt);

        Thread.Sleep(500);

        Console.Clear();
        Console.WriteLine(nt_closed);

        Thread.Sleep(150);

        Console.Clear();
        Console.WriteLine(nt);

        Thread.Sleep(500);

        Console.Clear();
        Console.WriteLine(nt_closed);

        Thread.Sleep(150);

        Console.Clear();
        Console.WriteLine(nt);

        Thread.Sleep(500);

        Console.Clear();
        Console.WriteLine(nt_closed);

        Thread.Sleep(150);

        Console.Clear();
        Console.WriteLine(nt);

        Thread.Sleep(500);

    }


    private void PrintWinningResponse(Question q)
    {
        Console.Clear();
        PrintStatus();

        Console.WriteLine("HELYES!");
        Console.WriteLine($"{q.question} => {q.answer}");

        Console.WriteLine();
        PrintWinningAscii();

    }

    private static void PrintWinningAscii()
    {
        Console.WriteLine(nt_win_taunts[rand.Next(0, nt_win_taunts.Length)]);
        Console.WriteLine();
        Console.WriteLine(nt_win[rand.Next(0, nt_win.Length)]);
    }

    private void PrintLosingResponse(Question q)
    {
        Console.Clear();
        PrintStatus();

        Console.WriteLine("HELYTELEN!");
        Console.WriteLine($"{q.question} => {q.GetAnswer()}");

        Console.WriteLine();
        PrintLosingAscii();

    }

    private static void PrintLosingAscii()
    {
        Console.WriteLine(nt_lose_taunts[rand.Next(0, nt_lose_taunts.Length)]);
        Console.WriteLine();
        Console.WriteLine(nt_lose[rand.Next(0, nt_lose.Length)]);
    }



    public static Quiz Parse(string filePath)
    {
        Quiz quiz = new();
        
        using (StreamReader reader = new(Path.Combine(basePath, filePath)))
        {
            Question? q;
            while ((q = Question.Parse(reader)) != null)
            {
                quiz.questions.Add(q);
            }
        }
        quiz.Shuffle();
        return quiz;
    }
}