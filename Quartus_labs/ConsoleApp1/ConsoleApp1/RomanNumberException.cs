using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp1
{
    class RomanNumberException : Exception 
    {
        public RomanNumberException(string aMessage)
            : base(aMessage) { }
    }
}
