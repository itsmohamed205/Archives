using System; // my first c# advanced system!
namespace Project
{
    class program
    {
        static void Main()
        {
            Console.ForegroundColor = ConsoleColor.Magenta;
            Console.WriteLine("---------------------------------");

            Console.ForegroundColor = ConsoleColor.Blue;
            Console.WriteLine("Welcome to the calculating machine!");
            var datel = DateTime.Now;
            Console.ForegroundColor = ConsoleColor.White;
            Console.Write("Current Date: ");
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine(datel + ".");

            Console.ForegroundColor = ConsoleColor.Magenta;
            Console.WriteLine("---------------------------------");
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine("Type your problem! Maths only! No Sadness please ;)");
            Console.ForegroundColor = ConsoleColor.White;
            var response = Console.ReadLine();
            if (response == null) response = " ";
            try
            {
                if (response != null && response != " " && response != "")
                {
                    string[] idk = response.Split(" ", 3);

                    Decimal value1 = Decimal.Parse(idk[0]);


                    string process = idk[1];
                    if (process == null || process == "" || process == " ") return;

                    decimal value2 = 0;

                    if (idk[2].ToString().Contains("/") == true && idk[0].ToString().Contains("/") == true)

                    {
                        char[] valuefix = idk[2].ToCharArray();

                        value2 = (Decimal.Parse(valuefix[0].ToString()) / Decimal.Parse(valuefix[2].ToString()));

                        char[] valuefix2 = idk[0].ToCharArray();

                        value1 = (Decimal.Parse(valuefix2[0].ToString()) / Decimal.Parse(valuefix2[2].ToString()));

                    }
                    else if (idk[2].ToString().Contains("/") == true && idk[0].ToString().Contains("/") != true)

                    {
                        char[] valuefix = idk[2].ToCharArray();

                        value2 = (Decimal.Parse(valuefix[0].ToString()) / Decimal.Parse(valuefix[2].ToString()));
                    }
                    else if (idk[0].ToString().Contains("/") == true && idk[2].ToString().Contains("/") != true)

                    {
                        char[] valuefix = idk[0].ToCharArray();

                        value1 = (Decimal.Parse(valuefix[0].ToString()) / Decimal.Parse(valuefix[2].ToString()));

                    }
                    else
                    {
                        value2 = Decimal.Parse(idk[2].ToString());
                        value1 = Decimal.Parse(idk[0].ToString());
                    }
                    

                    if (process.ToLower() == "x" || process.ToLower() == "multiply") process = "*";

                    if (process.ToLower() == "power" || process.ToLower().Contains("raised") == true) process = "^";

                    if (process.ToLower() == "divide") process = "/";

                    if (process.ToLower() == "add" || process.ToLower() == "sum" || process.ToLower() == "plus") process = "+";

                    if (process.ToLower() == "minus" || process.ToLower() == "substract" || process.ToLower() == "remove") process = "-";


                    if (process.ToString() == "-")
                    {
                        Decimal result = (Decimal.Parse((value1).ToString()) - Decimal.Parse((value2).ToString()));
                        Console.ForegroundColor = ConsoleColor.Magenta;
                        Console.WriteLine("---------------------------------");
                        Console.ForegroundColor = ConsoleColor.White;
                        Console.Write("Result is : ");
                        Console.ForegroundColor = ConsoleColor.Cyan;
                        Console.Write(result);
                        Console.ForegroundColor = ConsoleColor.White;
                        Console.WriteLine(" !");

                    }
                    else if (process.ToString() == "+")
                    {
                        Decimal result = (Decimal.Parse((value1).ToString()) + Decimal.Parse((value2).ToString()));
                        Console.ForegroundColor = ConsoleColor.Magenta;
                        Console.WriteLine("---------------------------------");
                        Console.ForegroundColor = ConsoleColor.White;
                        Console.Write("Result is : ");
                        Console.ForegroundColor = ConsoleColor.Cyan;
                        Console.Write(result);
                        Console.ForegroundColor = ConsoleColor.White;
                        Console.WriteLine(" !");
                    }
                    else if (process.ToString() == "/")
                    {
                        Decimal result = (Decimal.Parse((value1).ToString()) / Decimal.Parse((value2).ToString()));
                        Console.ForegroundColor = ConsoleColor.Magenta;
                        Console.WriteLine("---------------------------------");
                        Console.ForegroundColor = ConsoleColor.White;
                        Console.Write("Result is : ");
                        Console.ForegroundColor = ConsoleColor.Cyan;
                        Console.Write(result);
                        Console.ForegroundColor = ConsoleColor.White;
                        Console.WriteLine(" !");
                    }
                    else if (process.ToString() == "*")
                    {
                        Decimal result = (Decimal.Parse((value1).ToString()) * Decimal.Parse((value2).ToString()));
                        Console.ForegroundColor = ConsoleColor.Magenta;
                        Console.WriteLine("---------------------------------");
                        Console.ForegroundColor = ConsoleColor.White;
                        Console.Write("Result is : ");
                        Console.ForegroundColor = ConsoleColor.Cyan;
                        Console.Write(result);
                        Console.ForegroundColor = ConsoleColor.White;
                        Console.WriteLine(" !");

                    }
                    else if (process.ToLower() == "^")
                    {
                        Double value4 = Double.Parse(value2.ToString());
                        Double value3 = Double.Parse(value1.ToString());
                        Double result = Math.Pow(value3, value4);
                        Console.ForegroundColor = ConsoleColor.Magenta;
                        Console.WriteLine("---------------------------------");
                        Console.ForegroundColor = ConsoleColor.White;
                        Console.Write("Result is : ");
                        Console.ForegroundColor = ConsoleColor.Cyan;
                        Console.Write(result);
                        Console.ForegroundColor = ConsoleColor.White;
                        Console.WriteLine(" !");
                    }
                    else
                    {
                        Console.ForegroundColor = ConsoleColor.Magenta;
                        Console.WriteLine("---------------------------------");
                        Console.BackgroundColor = ConsoleColor.Red;
                        Console.ForegroundColor = ConsoleColor.Blue;
                        Console.WriteLine("Sorry, No Valid Operation was provided!");
                        Console.BackgroundColor = ConsoleColor.DarkGray;
                        return;
                    }

                }
                else
                {
                    Console.ForegroundColor = ConsoleColor.Magenta;
                    Console.WriteLine("---------------------------------");
                    Console.BackgroundColor = ConsoleColor.Red;
                    Console.ForegroundColor = ConsoleColor.Blue;
                    Console.WriteLine("Sorry unexpected error has occured, check your input and try again!\n Supported operations: [Addition - Substraction - Multiplication - Division - Power]");
                    Console.BackgroundColor = ConsoleColor.DarkGray;
                    return;
                }

            }
            catch (SystemException)
            {
                Console.ForegroundColor = ConsoleColor.Magenta;
                Console.WriteLine("---------------------------------");
                Console.BackgroundColor = ConsoleColor.Red;
                Console.ForegroundColor = ConsoleColor.Blue;
                Console.WriteLine("Syntax Error, Please Check Your Input.");
                Console.BackgroundColor = ConsoleColor.DarkGray;
                return;
            }
        }
    }

};
