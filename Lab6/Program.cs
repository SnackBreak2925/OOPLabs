using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab
{
	class Program
	{
		static void Main(string[] args)
		{
			double[] arr = { 1.45513, 2, 3, 4, 5, 6, 7, 8, 9 };
			Matrix a = new Matrix(3, 3, arr);
			Matrix b = a.Clone();
			double k = 1.3;
			a *= k;
			Console.WriteLine(a);//G
			//Console.WriteLine("{0}", a);
			//Console.WriteLine("{0:F.10}", a);//
			//Console.WriteLine("{0:F2}", a);
			//Console.WriteLine("{0:F}", a);
			//Console.WriteLine("{0:F2.10}", b);//
			//Console.WriteLine("{0:F2.10}", a);//
		}
	}
}
