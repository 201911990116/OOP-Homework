#include<iostream>
#include<cstdlib>
using namespace std;
class Location
{
public:
	double x;
	double y;
	Location(int _x=0,int _y=0):x(_x),y(_y)
	{
		
		cout << "Location() is called" << endl;
	}
	~Location()
	{
		cout << "~Location() is called " << endl;
		getchar();
	}
	int move()
	{
		x = x * -1;
		y = y * -1;
		return 0;
	}
	int show()
	{
		cout << "x=" << x << endl;
		cout << "y=" << y << endl;
		cout << "----------" << endl;
		return 0;

	}
};
class Point :public Location
{
public:
	double x;
	double y;
	double z;
	Point(int _x = 0, int _y = 0, int _z = 0): x(_x), y(_y), z(_z)
	{
		
		cout << "Point() is called " << endl;
	}
	~Point()
	{
		cout << "~Point() is called " << endl;
		getchar();
	}
};
class Sphere :public Point
{
public:
	double x;
	double y;
	double z;
	double r;
	Sphere(int _x = 0, int _y = 0, int _z = 0,int _r=0) : x(_x), y(_y), z(_z),r(_r)
	{
		cout << "Sphere() is called" << endl;

	}
	~Sphere()
	{
		cout << "~Sphere() is called" << endl;
		getchar();
	}
	int move()
	{
		x = x * -1 + 5;
		y = y * -1 + 5;
		z = z * -1 + 5;

		return 0;

	}
	int show()
	{
		cout << "x= " << x ;
		cout << ",y= " <<y ;
		cout << ",z= " << z << endl;
		cout << "r= " <<r << endl;

		return 0;

	}
};
int main()
{

	Location one(3,4);
	
	Sphere two(3, 4, 6,3);
	Point three;
	one.move();
	one.show();
	two.move();
	two.show();
	

}