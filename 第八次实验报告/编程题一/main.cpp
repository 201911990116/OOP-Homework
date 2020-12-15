#include <iostream>
#include <cstdlib>


using namespace std;

/*----------------------------------*
          Main Function
*-----------------------------------*/
class MyArray
{

private:
	int *ps;
	int size;

public:

	MyArray(int _size=20);
	MyArray(const MyArray &r);
	~MyArray();

	void show();
	MyArray& modifyArray();

	MyArray& operator=( const MyArray &r);
	MyArray operator+( const MyArray &r);

	friend MyArray operator-(MyArray &r1, MyArray &r2);

};
MyArray::MyArray(int _size)
{
	cout << "+��ͨ���캯��+" << endl;

	this->size = _size;

	this->ps = new int[_size];

	//��ʼ��Ϊ[0,10]�ڵ��������
	for (int i = 0; i < _size; i++)
	{
		this->ps[i] = rand() % 11;

	}


}

//�������캯��(�϶����ʼ����ǰ�¶���)
MyArray::MyArray(const MyArray & r)
{
	cout << "+�������캯��+" << endl;

	if (r.ps)
	{
		//Ϊ�¶������ռ�
		this->ps = new int[r.size];


		//�϶������ݳ�ʼ���¶���
		this->size = r.size;

		for (int i = 0; i < this->size; i++)
		{
			this->ps[i] = r.ps[i];
		}

	}
	else
	{
		cout << "��ֵ����Ϊ��,�޷����и�ֵ" << endl;
	}


}
//��������
MyArray::~MyArray()
{
	if (this->ps)
	{
		delete[] this->ps;
	}

	cout << "~��������" << endl;
}
//---------------------��ͨ����----------------

void MyArray::show()
{
	if (this->ps)
	{
		for (int i = 0; i < this->size; i++)
		{
			cout << this->ps[i] << " ";
		}

		cout << endl;
	}


}

MyArray & MyArray::modifyArray()
{
	if (ps)
	{
		cout << "��������Ҫ�޸ĵ�Ԫ�ر��:";
		int id; cin >> id;

		if (id >= 0 && id < size)
		{
			cout << "�޸�Ԫ����ֵ: ps[" << id << "] = ";
			cin >> ps[id];
		}
		else
			cout << "�������Ԫ�ر�ų������鷶Χ!" << endl;
	}
	else
	{
		cout << "�������ڴ�ռ�,�޷��޸�Ԫ��!" << endl;
	}
	return *this;

}

//���ظ�ֵ=�����:��Ա������ʽ:��Ŀ�����(�϶��� = �϶���)
MyArray& MyArray::operator=( const MyArray & r)
{
	cout << "  =��ֵ�����= " << endl;

	//1. ��յ�ǰ�϶�����ڴ�ռ�,���·����¿ռ�
	if (this->ps) { delete[] ps; }

	if (r.ps)
	{
		this->ps = new int[r.size];

	}

	//2. ���ݶ�λ��ֵ����(������λ��ֵ)
	this->size = r.size;

	for (int i = 0; i < this->size; i++)
	{
		this->ps[i] = r.ps[i];
	}

	return (*this);

}

//���ؼӷ�+�����(��Ա������ʽ):��Ŀ�����,�������ṩһ��������,��һ��������*this���󵣵�
MyArray MyArray::operator+( const MyArray &r)
{
	cout << "  +�ӷ������+ " << endl;

	//ִ�мӷ�������������������С��һ����ͬ,������С����ߴ�ӷ�Ϊ׼
	int minsize = (this->size <= r.size) ? this->size : r.size;


	//1.������ʱ���������temp
	MyArray temp(minsize);

	//2.�����ӷ�����
	for (int i = 0; i < minsize; i++)
	{
		temp.ps[i] = this->ps[i] + r.ps[i];
	}

	//3.���ض�������(��Ҫ���ض�������,��Ϊtemp����ܿ�ᱻ�ͷ�)
	return temp;

}


//���ؼ��������(��Ԫ������ʽ):��Ŀ�����,��Ŀ�������Ԫ������Ҫ�ṩ����������
MyArray operator-(MyArray & r1, MyArray & r2)
{

	cout << "  -���������- " << endl;

	//ִ�мӷ�������������������С��һ����ͬ,������С����ӷ�Ϊ׼
	int minsize = r1.size <= r2.size ? r1.size : r2.size;

	//1.������ʱ���������temp
	MyArray temp(minsize);

	//2.������������
	for (int i = 0; i < minsize; i++)
	{
		temp.ps[i] = r1.ps[i] - r2.ps[i];
	}

	//3.���ض�������(��Ҫ���ض�������,��Ϊtemp����ܿ�ᱻ�ͷ�)
	return temp;
}
int main()
{
	//1. �������������������
	MyArray array1(10);
	MyArray array2(30);
	MyArray array3(20);
	MyArray array4;


	//2.������������������
	cout << "array1 = "; array1.show();
	cout << "array2 = "; array2.show();
	cout << "array3 = "; array3.show();

	//3. �������������ʵ�ֶ���Ӽ���
	array3 = array1 + array2;
	array4 = array1 - array2;

	cout << "array1 + array2 = "; array3.show();
	cout << "array1 - array2 = "; array4.show();

	//4.������ͨ��Ա�����޸Ķ����ڵ�����
	array1.modifyArray();

	cout << "�޸ĺ������:";
	array1.show();

	system("pause");

	return 0;
}
