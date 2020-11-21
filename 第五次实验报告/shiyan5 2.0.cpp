#include"iostream"

#include"stdlib.h"

#include"string"

using namespace std;

class Mystring
{
public:
	int Link(char *str1, char *str2);


	int length(char *p);


	int Strcump(char *str1,char *str2);


	int Reverse(char *str1);

private:
	char a, b;
};

int Mystring::Link(char * str1, char * str2)
{
	char *p = str1;

	while (*p != '\0')
		p++;
	while (*str2 != '\0')


		*p++ = *str2++;

	*p = '\0';

	return 0;

}

int Mystring::length(char * p)
{
	int i = 0;

	while(*p!=0)
	{
		i++; p++;

	}
	return i;
}
int Mystring::Strcump(char * str1, char * str2)
{
	char *p = str1;


	char *q = str2;

	while (*p != '\0')
	{

		if (*p!= *q)

			cout << "the two spring is not the same"<<endl;break;
		
	}
	return 0;

}
int Mystring::Reverse(char * str1)
{
	char *p = str1;

	char str2[10];

	for (int i = 0; i < 10; i++)
	{
		int j = 0;

		str2[i] = str1[i-1-j];

		j++;
	}


	cout << str2[10]<< endl;//输出交换后的字符串

	return 0;

}
	
	

int main()
{

	char a[100], b[100];

	cout << "please input your want to link the two spring" << endl;

	cin >> a >> b;

	Mystring one;

	one.Link(a, b);


	cout << a << endl;

	string c;

	cout << "please input your want to search the length of the string"<<endl;	

	cin >> c ;

	 cout << "the string's characters are:" << c.length() << endl;

	 char d[100], e[100];
	 cout << "please input your want to compare the two spring" << endl;
	 cin >> d >>e;
	  Mystring two;
	 two.Strcump (d,e);	


	 char f[100];
	 cout << "please iniput you want to revease spring"<<endl;
	 cin >> f;
	 Mystring three;
	 three.Reverse(f);


	system("pause");



	return 0;
}
