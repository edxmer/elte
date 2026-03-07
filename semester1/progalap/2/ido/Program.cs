/*
 
https://progalap.elte.hu/specifikacio/v1/?data=H4sIAAAAAAAACp2Sy2rDMBBFf2XQqm0eSOMmxIJ%2BQFftPslCfhQMtWUsZdOQfb6zX9LR1C95U6ix8L3yzNXx4KtwbZlXH1VufGUbocVro8HK7%2Fv9KLdbTM5raAe3S8nVsXVf00YaNkxvEpRSks8WPl%2F4IvKn7tS8XTwhqAhBxQhqiaDmCBajXox7cdmLU284%2Fr0rNWxYWUckQQFdVj7t%2BVZSwoqmMmkaQa94HLCBBxMVZ5PM%2B2fxCC%2F0lXGmmmeqWaYaMUxT%2FINoBX8DBR6ME3GeiLNEDAxhibXwpfNO6ONVFMYb%2BoWs1HAIL1sSSgZVs%2BQuBtKQJkOE0cA1GXWxyDUgi2JoD8sqDXtOJfGc%2FqaS3I2pZA5jqkU6g8tJJD1EkMlQHgzhN6YuCZpUV7rLpxda3c63HxoVYqcZAwAA
https://progalap.elte.hu/stuki/v1/?data=H4sIAAAAAAAAE91Y61PbOBD%2FVzxi7gaoOfzIm8eHNOXVAr1COI6WD4olJym2ZfwAEib%2F%2B61sS1abpnczYqY3eDKTzVr6%2FXZX3s2un9GUoB6y%2FnBbdqPZbjabjZbVcmwHmWjCHmhyDLejPAhMlNKAehkltSZihKao94yGgz%2FZZf%2F9mMsFnlSYKMYJjbJ602RKCI1Qz8dBSk2UzWIKG1J6n9PIo7DBm0wDAnuOCWB%2FRql7F5%2FT7gHcef%2FpdHAVxiMQL%2B3zWf%2Fg3RDEIzy%2FGeXsAsSWddc4mzMMYufhenj2Nz4FceBOyFt6n4DIyIlvXU9nII4dfE7zZABifjX8q2Hb9yC%2BY3jefYzOOUIw%2B%2FB1NjgE8SvLbsKP7gmI%2FauLiyAc8rUn8%2F78xj0k3Jz7g7ybXnC2o8Pj7CO9boMYpYd310dv%2BTY3DJvhWcrDStp9HHluB90uzNo7ETnF3TpyajxXxC%2FDGQ1hOazI6FMGqswyenu%2FR6M03tlNYxwZaTYL6N4X5LGAJT0jGY%2FWLdPgn40d43EyzegWrPNoz4gTuvMF7TNrc3ebb91fCdA1DdttmEanswKjZf0bxM9teA0W2JamCcYbI34VZ%2FESkQhfIhQvYUg6B1MqFLRQypPIZaVe6ebyk24uY%2F2Y%2FfrH59db8BLPzUjfjNcRCO%2F%2FYQb5IcI3iyP2mOAYllc5WCe9bERE0iudiW7S25D0BvyNbxnZE%2BeS7Y3gUvodXS6n4npTccmmSXApXZQm1y6ZPuzz4ln6Zxu%2FGcUxcjWnlk2aoFa6Nk1qINvaKwq3zZlkDyiYlKZQk6nybr30b71lbYKPG8aGsc2dLR8jboLsXoUJSjuraQJn3jOcxiaQl%2FycUDbGglDplHUJnR8Ryu5aECrtti5hcZw81JtGxSYbeMGmdPSabEsnqh6qOOEixGJykCGuRwlNG0qPC4dbVu21HFAEozKxaDIykaXbqs%2BcVI5CglSZjTRJZYkoy5LzfYmQo5egVmYxTWogq0qEU9R3MdnJ%2Bl6PeppMlXfrpX8%2FKRFiopQloh4xNU0oneWGyEdJDq2CTZliNdmW%2FF2VQHJaFjYo47OmDaXHhcNqAsmhXDBKhTYjE8%2FwdwnEp%2F8syb2MjRMc8ncdzyjCIUc5xdMIABKa5Ul0WcLA7wecTPEo4O9c%2BM%2BEsSWr0gl7vKqXVcZx7RHFhCbfqD4p%2BGAJXdyaZeNUvNQpzf%2BM1nzfggvA1%2Fi373PJ9z2pG1lNKfmF1LZcCxeSR7HfaaPbMhp97N2NE5ZHpAIeOSN%2Bpmv8WwBTT%2Bho28NC8guJNDyLOhyOv3tagvPgKljhEnC%2BI3TUJ94qOOUkllD5Vfn8n%2FB9v9st71pWx%2Bs2uUQpbZCWGpHF4h%2BGqHqTfBMAAA%3D%3D


Pontszám: 80/100
-still needs fixing

*/



using System;


namespace ido
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // Deklaráció
            ulong o0, p0, mp0, szmp0, a, b, c, d;
            ulong o1, p1, mp1, szmp1, o2, p2, mp2, szmp2;
            ulong t0, tx, t1, t2;

            // Beolvasás

            string line1 = Console.ReadLine();
            string[] numbers1 = line1.Split(' ');

            ulong.TryParse(numbers1[0], out o0);
            ulong.TryParse(numbers1[1], out p0);
            ulong.TryParse(numbers1[2], out mp0);
            ulong.TryParse(numbers1[3], out szmp0);


            string line2 = Console.ReadLine();
            string[] numbers2 = line2.Split(' ');

            ulong.TryParse(numbers2[0], out a);
            ulong.TryParse(numbers2[1], out b);
            ulong.TryParse(numbers2[2], out c);
            ulong.TryParse(numbers2[3], out d);

            // Feldolgozás
            
            t0 = o0*60*60*100 + p0*60*100 + mp0*100 + szmp0; // Jó
            tx = a*60*60*100 + b*60*100 + c*100 + d; // Jó
            t1 = t0 - tx; // Jó
            t1 %= 24*60*60*100; // Jó
            t2 = t0 + tx; // Jó
            t2 %= 24*60*60*100; // Jó

            szmp1 = t1 % 100;
            t1 -= szmp1;
            mp1 = ( t1 % (60*100) ) / 100;
            t1 -= mp1 * 100;
            p1 = ( t1 % (60*60*100) ) / (60*100);
            t1 -= p1 * 60 * 100;
            o1 = t1 / (60*60*100);
            
            szmp2 = t2 % 100;
            t2 -= szmp2;
            mp2 = ( t2 % (60*100) ) / 100;
            t2 -= mp2 * 100;
            p2 = ( t2 % (60*60*100) ) / (60*100);
            t2 -= p2 * 60 * 100;
            o2 = t2 / (60*60*100);

            // Kiírás

            Console.WriteLine("{0} {1} {2} {3}", o1, p1, mp1, szmp1);
            Console.WriteLine("{0} {1} {2} {3}", o2, p2, mp2, szmp2);


        }
    }
}
