/*
 
https://progalap.elte.hu/specifikacio/v1/?data=H4sIAAAAAAAACqtWKi5ITc5My0xOLMnMz1OyUnJKtVIoftTREaSjUAKiYopi8rwzrRTKYBzXNJCCzqUGCol5KQoldgYgwVCQoG2ZVgmIo6SjVJJaXFKsZBVdrZSSWJIINLbYSsEQJFcCpUG4DMgGqs1LzE0FqgCyilKLS3NKlKwMa3WQNRoZwHQaIGk1wqE1thYAUQUSC9UAAAA%3D
https://progalap.elte.hu/stuki/v1/?data=H4sIAAAAAAAACo2S30%2FCMBDH%2FxVzvC5SNgZuQR%2BMUXnwxRijITyU9soWR4tdhxCy%2F912Yz8MIbEv%2Fd53d5%2B73XaElEMM5DoakWBCwoBEo5D44Qg8SNQO9dw%2BlkWWeZBjhswg7xypOOYQH2H9wQ5bHQZOV7zW8GBLNUrTFSUp5yghFjTL0QNz2KItyPG7QMnQFrAkzbitmXPLXkBePHw%2B7R8DWJZeFzSNWqPfqN%2F%2BQjtDDW5sus0wuDfWmvF0d7eLb6%2FyoZkNXQCl62h0wYxaa7px4xxB0o0jvNBU2mKNptDyrUbYeEd1SleZW4sLtVJnE%2BWJ%2Bnnv0k6DOfcZKUf9x3rt8e0kWC7tglSmdLX3evQFDIQg9lj4wN1COCUEa70VCVslKjUlAaGVYkjFzRSW9SbuKftaa1VIfgKv%2FJXv0tzdgJE1Hk4ZbZSoFB8zgr7Dud%2FjDMfsqbra0%2BCE33goOLuE632JM6o7p3f%2BF1%2BIKKqfEnLDotApRBzzSX8jZfkLKirQjh8DAAA%3D
 
 */

using System;

namespace utido
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // Deklarálás
            float s, t, v;

            // Beolvasás
            Console.Write("út (m): ");
            float.TryParse(Console.ReadLine(), out s);

            Console.Write("idő (s): ");
            float.TryParse(Console.ReadLine(), out t);

            // Feldolgozás
            v = s / t;

            // Kiírás
            Console.WriteLine("A sebességed: {0} m/s", v);

        }
    }
}
