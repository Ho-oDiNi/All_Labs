using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp1
{
    public class RomanNumber : ICloneable, IComparable
    {
        private ushort[] mas1 = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        private string[] mas2 = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
        private string s = "";
        private ushort n;

        public RomanNumber(ushort n) //Конструктор получает число n, которое должен представлять объект класса
        {
            if (n == 0)
                throw new RomanNumberException("Ошибка при вводе: n равняется нулю");
            this.n = n;
        }

        public static RomanNumber Add(RomanNumber? n1, RomanNumber? n2) //Сложение римских чисел
        {
            ushort sum = (ushort)(n1.n + n2.n);
            RomanNumber romanNumber = new RomanNumber(sum);

            return romanNumber;
        }

        public static RomanNumber Sub(RomanNumber? n1, RomanNumber? n2) //Вычитание римских чисел
        {
            if (n2.n > n1.n)
                throw new RomanNumberException("Ошибка при вычитании: результат - отрицательное число");
            if (n2.n == n1.n)
                throw new RomanNumberException("Ошибка при вычитании: результат - ноль");
            ushort dif = (ushort)(n1.n - n2.n);
            RomanNumber romanNumber = new RomanNumber(dif);

            return romanNumber;
        }

        public static RomanNumber Mul(RomanNumber? n1, RomanNumber? n2) //Умножение римских чисел
        {
            ushort prod = (ushort)(n1.n * n2.n);
            RomanNumber romanNumber = new RomanNumber(prod);

            return romanNumber;
        }

        public static RomanNumber Div(RomanNumber? n1, RomanNumber? n2) //Целочисленное деление римских чисел
        {
            if (n2.n > n1.n)
                throw new RomanNumberException("Ошибка при делении: результат меньше единицы");
            if (n1.n % n2.n != 0)
                throw new RomanNumberException("Ошибка при делении: результат не является целочисленным");
            ushort div = (ushort)(n1.n / n2.n);            
            RomanNumber romanNumber = new RomanNumber(div);

            return romanNumber;
        }

        public override string ToString()  //Возвращает строковое представление римского числа
        {
            s = "";
            int N = n;
            int i = 0;
            while (N > 0)
            {
                if (mas1[i] <= N)
                {
                    N = N - mas1[i];
                    s = s + mas2[i];
                }
                else i++;
            }
            return s;
        }

        public object Clone() //Реализация интерфейса IClonable
        {
            return new RomanNumber(n);
        }

        public int CompareTo(object? obj) //Реализация интерфейса IComparable
        {
            RomanNumber romanNumber;
            romanNumber = (RomanNumber)obj;

            return n.CompareTo(romanNumber.n);
        }
    }
}
