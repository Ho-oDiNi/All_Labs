using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            RomanNumber[] romanNumber = new RomanNumber[3];
            for(int i = 0; i < 3; i++)
                romanNumber[i] = new RomanNumber((ushort)(10*(i+1)));

            string s0 = romanNumber[0].ToString(), s1 = romanNumber[1].ToString(), s2 = "";
            Console.WriteLine("Первое число " + s0);
            Console.WriteLine("Второе число " + s1);

            romanNumber[2] = RomanNumber.Add(romanNumber[1], romanNumber[0]);
            s2 = romanNumber[2].ToString();
            Console.WriteLine("Сумма " + s2);

            romanNumber[2] = RomanNumber.Sub(romanNumber[1], romanNumber[0]);
            s2 = romanNumber[2].ToString();
            Console.WriteLine("Разница " + s2);

            romanNumber[2] = RomanNumber.Mul(romanNumber[1], romanNumber[0]);
            s2 = romanNumber[2].ToString();
            Console.WriteLine("Произведение " + s2);

            romanNumber[2] = RomanNumber.Div(romanNumber[1], romanNumber[0]);
            s2 = romanNumber[2].ToString();
            Console.WriteLine("Частное " + s2);

            Array.Sort(romanNumber);

            Console.WriteLine("Сортированный массив");
            for (int i = 0; i < 3; i++)
            {
                s0 = romanNumber[i].ToString();
                Console.Write(s0 + " ");
            }
            Console.WriteLine("");
        }
    }
}
