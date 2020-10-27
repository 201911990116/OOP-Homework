#include <iostream>
#include <stdlib.h>
#include"math.h"


using namespace std;

const double eps = 1e-10;

double fx(double x)//定义任意的某个函数f(x)
{
	double f = (x * x )- 10;

	return f;

}



double binarySearch(double &left, double &right)//二分法寻找函数的零点
{
	

	double middle = 0.5*(left + right);



	while (fabs(fx(middle)) > eps)
	{

		if (fx(left)*fx(middle) < 0)

		{
			right = middle;
		}
		else
		{
			left = middle;
		}

		middle = 0.5*(left + right);

	}

	return middle;
}

int main()
{
	double a, b;


	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;

	double c = binarySearch(a, b);

	cout << " x = " <<  c<< endl;




     system("pause");





	return 0;
}