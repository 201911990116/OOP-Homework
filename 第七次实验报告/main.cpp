#include<iostream>
#include<cstdlib>
using namespace std;
class Base
{
public:
	int a;
	int print();
	static int statistic();
	Base(int _a = 0,int _b = 0,int _c = 0)
	{
		this->a = _a;
		this->b = _b;
		this->c =_c;
		cout << "the Base is called" << endl;


	}
	~Base()
	{
		cout << "the ~Base() is called " << endl;
		getchar();
	}
    protected:
	   int b;
	private:
		int c;
		static int count;
	
};
int Base::count = 0;
class Derived1:public Base
{
   public:
	   int a;
	   Derived1()
	   {
		   cout << "Derived1() is called " << endl;

	   }
	   ~Derived1()
	   {
		   cout << "~Derived1() is called" << endl;
		   getchar();
	   }
};
class Derived2 :public Base
{
public:
	int a;
	Derived2()
	{
		cout << "Derived2() is called " << endl;

	}
	~Derived2()
	{
		cout << "~Derived2() is called" << endl;
		getchar();
	}
};
class Derived3 :public Base
{
public:
	int a;
	Derived3()
	{
		cout << "Derived3() is called " << endl;

	}
	~Derived3()
	{
		cout << "~Derived3() is called" << endl;
		getchar();
	}
};
int main()
{
	cout << "sizeof(Base)=" << sizeof(Base) << endl;
	cout << "sizeof(Derived1)=" << sizeof(Derived1) << endl;
	cout << "sizeof(Derived2)=" << sizeof(Derived2) << endl;
	cout << "sizeof(Derived3)=" << sizeof(Derived3) << endl;
	cout << "---------------" << endl;
	Derived1 one; 
	cout << "---------------" << endl;

	Derived2 two; 
	cout << "---------------" << endl;

	Derived3 three; 
	cout << "---------------" << endl;

	one.a = 1;
	
	two.a = 2;
	three.a = 3;
	system("pause");
	return 0;


}














