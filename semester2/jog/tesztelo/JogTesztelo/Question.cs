namespace JogTesztelo;

#pragma warning disable IDE1006

public record Question(string id, string question, string[] choices, int answer)
{

    public static Question? Parse(StreamReader r)
    {
        string? id = r.ReadLine()!,
                question = r.ReadLine()!,
                choiceA = r.ReadLine()!,
                choiceB = r.ReadLine()!,
                choiceC = r.ReadLine()!,
                choiceD = r.ReadLine()!,
                answer = r.ReadLine();

        if (answer == null) return null;

        return new Question(id, question, [choiceA, choiceB, choiceC, choiceD], answer switch
        {
            "A" => 0,
            "B" => 1,
            "C" => 2,
            "D" => 3,
            _ => throw new FormatException($"A fájlnak egy válasz rossz formátumban van: {answer}")
        });
    }

    public void Print()
    {
        Console.WriteLine($"{id} {question}");
        foreach (string c in choices)
        {
            Console.WriteLine(c);
        }
    }

    public bool AwaitResponse()
    {
        string guess = Console.ReadLine()!;

        return answer == (guess switch
        {
            "A" => 0,
            "B" => 1,
            "C" => 2,
            "D" => 3,
            _ => throw new FormatException("A válasznak A, B, C vagy D-nek kell lennie.")
        });
    }

    public string GetAnswer()
    {
        return choices[answer];
    }

}