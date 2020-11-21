#include"iostream"
#include"stdlib.h"
#include"math.h"
using namespace std;
class Pointfriend;

class Point
{

public:
	double x;
	double y;
	Point()//无参构造函数
	{
		x = 0;
		y = 0;
	}
	Point(double x,double y)//设置xy特定值
	{
		this->x = x;
		this->y = y;

	}

	double getx()
	{
		return x;

	}
	double gety()
	{
		return y;

	}
	double Cout(Point a, Point b)
	{
		cout << "tht point of the two  is " <<endl<<"("<< a.getx()  <<","<< a.gety()  <<")"<<"("<< b.getx()  <<","<< b.gety()  <<")"<< endl;
		return 0;
	}
	friend double distance(Point a, Point b)
	{

		return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));

	}

	friend Pointfriend;
	
};
class Pointfriend
{
public:
	

private:

};

int main()
{
	Point one(0, 0);
	double a, b, c, d;
	cout << "please input two point" << endl;
	cin >> a >> b >> c >> d;
	
	Point two(a,b);
	Point three(c,d);	
	one.Cout(two, three);
	   	distance(two, three);
cout << "the distance between the two point is " << distance(two,three) << endl;
	system("pause");
	return 0;

}

