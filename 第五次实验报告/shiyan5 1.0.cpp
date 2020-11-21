#include"iostream"

#include"stdlib.h"

using namespace std;

const int MAXSIZE = 100;


class Stack
{


private:


	int top;


	double data[MAXSIZE];


public:


	Stack();
	~Stack();
	void initial();



	bool isFull();


	bool isEmpty();

	void push(double& val);


	double pop();

	int sizeStack();
	int getTop();


};



Stack::Stack()
{

	top = 0;
	memset(data, 0, sizeof(data));


}



Stack::~Stack()
{


}

void Stack::initial()
{
	top = 0;
	memset(data, 0, sizeof(data));

}


bool Stack::isFull()
{
	if (top == MAXSIZE)


		return true;


	else


		return false;

}


bool Stack::isEmpty()
{
	if (top == 0)


		return true;


	else


		return false;

}




void  Stack::push(double& val)
{

	data[top] = val;


	top++;


}

double Stack::pop()


{

	top--;


	return data[top];

}

int Stack::sizeStack()
{

	return top;

}



int Stack::getTop()
{
	return top;

}




int main()
{
	cout << "******zhanleishejiyuceshi*****" << endl;


	Stack ss;


	cout << "dangqianzhandaxiaowei:" << ss.sizeStack() <<",yunxuruzhan..."<<endl<< endl;


	double temp = 0;


	while (!ss.isFull())
	{
		cout << "yazhanqingshurushuju0zhongzhi";

		cin >> temp;



		if (temp == 0)
		{
			cout << "*****ruzhanwanbi！******" << endl << endl;


			break;

		}

		ss.push(temp);


		cout << "chenggongruzhan!" << endl;
	}



	cout << "congzhaodinyicishuchudangqianzhaonei"<<ss.getTop() << "geshuju:" << endl;

	while (!ss.isEmpty())
	{
		cout << ss.pop() << " ";

	}

	cout << endl;


	system("pause");

	return  0;






}