#include"iostream"

#include"stdlib.h"

#include"string.h"

#include"math.h"

using namespace std;

class Triangle
{
private:

	double a, b, c;

public:

	Triangle (double a, double b, double c)

	{
		
		if (a + b > c&&b + c > a&&a + c > b)

		{
			this->a = a;

			this->b = b;

			this->c = c;


		}
		else
		{
			cout << "The three number can't form a triangle!" << endl;


			exit(0);//如果不能构成三角形，就立即退出
		}

	}
	double Primeter()//计算周长的函数

	{
		return a + b + c;
	}
	double Area()//利用海伦公式计算面积的函数
	{
		double p = Primeter()/2;


		return sqrt(p*(p - a)*(p - b)*(p - c));
	}
	
	void show()//将结果输出的函数
	{
		cout << "the area of the triangle is:" << Area() << endl;


		cout << "the perimeter of the triangle is:" << Primeter() << endl;
	}
	void Shape()//判断三角形形状的函数
	{
		if ((a*a) + (b*b) == (c*c))


			cout << "the triangle is right - angled triangle" << endl;


		else if (a*a + b * b > c*c)


			cout << "the triangle is acute triangle" << endl;

		else 

			cout << "the triangle is obtuse triangle" << endl;



	}


};



int main()
{
	double a, b, c;


	cout << "plesse input three number fron small to large" << endl;


	cin >> a >> b >> c;

	Triangle one(a, b, c);


	one.show();

	one.Shape();

	cout << "plesse input three number fron small to large" << endl;
	cin >> a >> b >> c;


	Triangle two(a, b, c);

	two.show();


	two.Shape();



	system("pause");




	return 0;
}
