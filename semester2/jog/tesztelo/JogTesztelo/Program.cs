namespace JogTesztelo;

class Program
{
    static void Main()
    {
        Quiz quiz = Quiz.Parse("Resources/questions.txt");
        while (quiz.HasNextQuestion())
        {
            quiz.NextQuestion();
        }

        quiz.DisplayResults();
    }
}