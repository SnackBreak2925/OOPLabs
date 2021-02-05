using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Lab
{
	class Matrix : IFormattable, ICloneable, IEnumerable<double>
	{
		private double[] Array;
		public int Strings { get; private set; }
		public int Columns { get; private set; }
		public int Id { get; private set; }
		private static int Counter { get; set; }
		public Matrix()
		{
			this.Id = Counter++;
			Console.WriteLine($"Matrix {Id} created");
		}
		public Matrix(int size) : this(size, size) { }      // для квадратных
		public Matrix(int size, params double[] arr) : this(size, size, arr) { }
		public Matrix(int Strings, int Columns) : this()
		{
			if(Strings > 0 && Columns > 0)
			{
				this.Strings = Strings;
				this.Columns = Columns;
				this.Array = new double[Strings * Columns];
			}
			else if(Strings < 0 || Columns < 0)
				throw new ArgumentOutOfRangeException($"Size must => 0 for Matrix {Id}");
		}
		public Matrix(int Strings, int Columns, Func<int, double> fun) : this(Strings, Columns)
		{
			for(int i = 0; i < Strings * Columns; i++)
				this.Array[i] = fun(i);
		}
		public Matrix(int Strings, int Columns, params double[] arr) : this(Strings, Columns)
		{
			for(int i = 0; i < Strings * Columns; i++)
				this.Array[i] = arr[i];
		}
		public Matrix Clone()
		{
			return new Matrix(Strings, Columns, Array);
		}
		object ICloneable.Clone()
		{
			return this.Clone();
		}
		~Matrix()
		{
			Console.WriteLine($"Matrix {Id} deleted");
		}
		public static bool check_sum(in Matrix first, in Matrix second)
		{
			return first.Strings == second.Strings && first.Columns == second.Columns;
		}
		public static bool check_mul(in Matrix first, in Matrix second)
		{
			return first.Strings == second.Columns;
		}
		public IEnumerator<double> GetEnumerator()
		{
			foreach(double i in Array)
				yield return i;
		}
		IEnumerator IEnumerable.GetEnumerator()
		{
			return Array.GetEnumerator();
		}
		public static Matrix operator +(Matrix a, Matrix b)
		{
			if(Matrix.check_sum(a, b))
			{
				Matrix tmp = new Matrix(a.Strings, a.Columns);
				for(int i = 0; i < a.Strings * a.Columns; i++)
					tmp.Array[i] = a.Array[i] + b.Array[i];
				return a;
			}
			throw new ArgumentException($"Can't sum matrices #{a.Id} and #{b.Id}");
		}
		public static Matrix operator -(Matrix a, Matrix b)
		{
			if(Matrix.check_sum(a, b))
			{
				Matrix tmp = new Matrix(a.Strings, a.Columns);
				for(int i = 0; i < a.Strings * a.Columns; i++)
					tmp.Array[i] = a.Array[i] + b.Array[i];
				return a;
			}
			throw new ArgumentException($"Can't div matrices #{a.Id} and #{b.Id}");
		}
		public static Matrix operator *(Matrix a, Matrix b)
		{
			if(check_mul(a, b))
			{
				Matrix tmp = new Matrix(a.Strings, b.Columns);
				for(int i = 0; i < a.Strings; i++)
					for(int j = 0; j < b.Columns; j++)
						for(int k = 0; k < a.Columns; k++)
							tmp.Array[i * tmp.Columns + j] += a.Array[i * a.Columns + k] * b.Array[k * b.Columns + j];
				return tmp;
			}
			throw new ArgumentException($"Can't mul matrices #{a.Id} and #{b.Id}");
		}
		public static Matrix operator *(Matrix matr, double scal)
		{
			for(int i = 0; i < matr.Strings * matr.Columns; i++)
				matr.Array[i] *= scal;
			return matr;
		}
		public double this[int i, int j]
		{
			get
			{
				if(i >= 0 && j >= 0 && i < Strings && j < Columns)
					return Array[i * Columns + j];
				throw new IndexOutOfRangeException($"Incorrect index for Matrix{Id}");
			}
			set
			{
				if(i >= 0 && j >= 0 && i < Strings && j < Columns)
					this.Array[i * Columns + j] = value;
				else
					throw new IndexOutOfRangeException($"Incorrect index for Matrix{Id}");
			}
		}
		public string ToString(string format, IFormatProvider formatProvider = null)
		{
			if(string.IsNullOrEmpty(format))
				format = "G";

			var splitted = format.Split('.');
			string numberFormat = splitted[0];
			int width;

			if(splitted.Length == 1)
				width = 8;
			else
				width = int.Parse(splitted[1]);

			string resultFormat = $"{{0,{width}:{numberFormat}}}";

			var s = new StringBuilder();

			for(int i = 0; i < this.Strings; i++)
			{
				for(int j = 0; j < this.Columns; j++)
					s.AppendFormat(formatProvider, resultFormat, this.Array[j * Columns + i]);
				s.AppendLine();
			}
			return s.ToString();
		}
	}
}
