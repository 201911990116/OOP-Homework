#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;
const int N = 10;
int numCount = 0;
class Student
{
	//姓名、性别、学号、出生日期、家庭住址、6个科目的考试成绩
private:
	char* name;
	char sex[7];
	char stuNumber[13];
	char birth[11];
	char* address;
	double chineseScore, mathScore, englishScore, moralScore, scienceScore, computerScore;

public:

	//初始化学生类对象
	Student();
	Student(char* na, char* se, char* num, char* bir, char* addr);
	Student(double ch, double math, double en, double moral, double sci, double comp);
	Student(const Student &stu);
	~Student();

	//获取学生任意信息
	char* GetName();
	char* GetSex();
	char* GetStuNumber();
	char* GetBirth();
	char* GetAddress();

	double GetChineseScore();
	double GetMathScore();
	double GetEnglishScore();
	double GetMoralScore();
	double GetScienceScore();
	double GetComputerScore();


	void Input();//输入学生信息
	void Update();//修改学生信息
	void Display();//展示学生信息

};




void menu();//主菜单
void InputData(Student* array);//输入学生数据
void UpdateData(Student* array);//更新学生数据
void OutputData(Student* array, char* num);//查询某一条信息
void OutputList(Student* array);//输出学生列表
int main()
{
	Student array[N];
	int choice;

	do
	{
		menu();

		cout << "请输入选项:";

		cin >> choice;
		if (choice >= 0 && choice <= 4)
		{
			switch (choice)
			{
			case 1:
				InputData(array);
				break;
			case 2:
				UpdateData(array);
				break;
			case 3:
				cout << "请输入学号查询：";

				char check[13];

				cin >> check;

				OutputData(array, check);

				break;
			case 4:
				OutputList(array);
				break;
			default:
				break;
			}
		}

	} while (choice);


	system("pause");

	return 0;
}



void  menu()//主菜单
{
	cout << "******1.录入信息******" << endl;
	cout << "******2.更新信息******" << endl;
	cout << "******3.查询信息******" << endl;
	cout << "******4.输出信息******" << endl;
	cout << "******0.退    出******" << endl;
}

void InputData(Student* array)//输入学生信息
{
	char ch;
	do
	{
		array[numCount].Input();

		numCount++;

		cout << "是否继续输入(Y or N)";

		cin >> ch;

	} while (ch == 'Y');
}

void UpdateData(Student* array)//更新学生信息
{
	char ch, num[13];

	cout << "请输入学号： ";

	cin >> num;

	for (int i = 0; i < numCount; i++)
	{
		if (strcmp(array[i].GetStuNumber(), num) == 0)
		{
			do
			{
				array[i].Update();

				cout << "是否继续修改(Y or N)： ";

				cin >> ch;

			} while (ch == 'Y');
		}
		else
		{
			cout << "该学生信息未录入!" << endl;
		}
	}


}

void OutputData(Student* array, char *num)//查询学生某一条信息
{
	for (int i = 0; i < numCount; i++)
	{
		if (strcmp(array[i].GetStuNumber(), num) == 0)
		{
			cout << "学生姓名为：" << array[i].GetName() << "(" << array[i].GetStuNumber() << ")" << endl;
			char ch;
			do
			{
				int a;

				cout << endl << "1.性别\t" << "2.出生年月\t" << "3.家庭住址" << endl;
				cout << "4.语文成绩\t" << "5.数学成绩\t" << "6.英语成绩" << endl;

				cout << "7.思品成绩\t" << "8.科学成绩\t" << "9.计算成绩" << endl;

				cout << "请输入需要查询的信息序号： ";

				cin >> a;

				switch (a)
				{
				case 1:
					cout << "性别： " << array[i].GetSex() << endl;
					break;
				case 2:
					cout << "出生日期： " << array[i].GetBirth() << endl;
					break;
				case 3:
					cout << "家庭住址： " << array[i].GetAddress() << endl;
					break;
				case 4:
					cout << "语文成绩： " << array[i].GetChineseScore() << endl;
					break;
				case 5:
					cout << "数学成绩： " << array[i].GetMathScore() << endl;
					break;
				case 6:
					cout << "英语成绩： " << array[i].GetEnglishScore() << endl;
					break;
				case 7:
					cout << "思想品德成绩： " << array[i].GetMoralScore() << endl;
					break;
				case 8:
					cout << "科学成绩： " << array[i].GetScienceScore() << endl;
					break;
				case 9:
					cout << "计算机成绩： " << array[i].GetComputerScore() << endl;
					break;
				default:
					break;
				}

				cout << "是否继续查询(Y or N)： ";

				cin >> ch;

			} while (ch == 'Y');

			break;
		}
		else
		{
			cout << "未查询到有效身份!" << endl;
		}
	}
}

void OutputList(Student* array)//输出列表
{
	cout << "当前学生人数为： " << numCount << endl;
	for (int i = 0; i < numCount; i++)
	{
		array[i].Display();
	}
}
Student::Student()
{
	name = NULL;
	address = NULL;
	chineseScore = mathScore = englishScore = moralScore = scienceScore = computerScore = 0;
}

Student::Student(char* na, char* se, char* num, char* bir, char* addr)//学生基本信息
{
	if (na)
	{
		name = new char[strlen(na) + 1];

		strcpy_s(name, strlen(na) + 1, na);
	}

	strcpy_s(sex, se);

	strcpy_s(stuNumber, num);

	strcpy_s(birth, bir);

	if (addr)
	{
		address = new char[strlen(addr) + 1];

		strcpy_s(address, strlen(addr) + 1, addr);

	}
}

Student::Student(double ch, double math, double en, double moral, double sci, double comp)//学生成绩信息
{
	chineseScore = ch;
	mathScore = math;
	englishScore = en;
	moralScore = moral;
	scienceScore = sci;
	computerScore = comp;
}

Student::Student(const Student &stu)
{
	if (stu.name)
	{
		name = new char[strlen(stu.name) + 1];

		strcpy_s(name, strlen(stu.name) + 1, stu.name);
	}

	strcpy_s(sex, stu.sex);

	strcpy_s(stuNumber, stu.stuNumber);

	strcpy_s(birth, stu.birth);

	if (stu.address)
	{
		address = new char[strlen(stu.address) + 1];

		strcpy_s(address, strlen(stu.address) + 1, stu.address);

	}
}

Student::~Student()
{
	if (name)
	{
		delete[]name;
	}

	if (address)
	{
		delete[]address;
	}
}

//基本信息获取
char * Student::GetName()
{
	return name;
}

char * Student::GetSex()
{
	return sex;
}

char * Student::GetStuNumber()
{
	return stuNumber;
}

char * Student::GetBirth()
{
	return birth;
}

char * Student::GetAddress()
{
	return address;
}

double Student::GetChineseScore()
{
	return chineseScore;
}

double Student::GetMathScore()
{
	return mathScore;
}

double Student::GetEnglishScore()
{
	return englishScore;
}

double Student::GetMoralScore()
{
	return moralScore;
}

double Student::GetScienceScore()
{
	return scienceScore;
}

double Student::GetComputerScore()
{
	return computerScore;
}

//首次录入信息
void Student::Input()
{
	char na[20];

	cout << "请输入姓名： ";

	cin >> na;

	if (name)
	{
		delete name;
	}

	name = new char[strlen(na) + 1];

	strcpy_s(name, strlen(na) + 1, na);

	cout << "请输入性别(male/female)： ";

	cin >> sex;

	cout << "请输入学号： ";

	cin >> stuNumber;

	cout << "请输入生日(xxxx-xx-xx)： ";

	cin >> birth;

	char addr[30];

	cout << "请输入地址(Shandong-Jinan-Changqing)： ";

	cin >> addr;

	if (address)
	{
		delete address;
	}

	address = new char[strlen(addr) + 1];

	strcpy_s(address, strlen(addr) + 1, addr);

	cout << "请输入成绩(语文 数学 英语 思想品德 科学 计算机)： ";

	cin >> chineseScore >> mathScore >> englishScore >> moralScore >> scienceScore >> computerScore;

	cout << "信息录入完毕!" << endl;
}

//更新学生成绩信息
void Student::Update()
{
	int sub;
	double score;

	cout << "请输入科目代号(1.语文 2.数学 3.英语 4.思想品德 5.科学 6.计算机)： ";

	cin >> sub;

	cout << "请输入最新成绩：";

	cin >> score;

	switch (sub)
	{
	case 1:
		chineseScore = score;
		break;
	case 2:
		mathScore = score;
		break;
	case 3:
		englishScore = score;
		break;
	case 4:
		moralScore = score;
		break;
	case 5:
		scienceScore = score;
		break;
	case 6:
		computerScore = score;
		break;
	}

	cout << "成绩更新完毕!" << endl;
}

//学生信息一览
void Student::Display()
{
	cout << "学生姓名： " << name << "性别： " << sex << "生日： " << birth << endl;
	cout << "学号： " << stuNumber << "地址： " << address << endl;

	cout << "语文： " << chineseScore << "数学： " << mathScore << "英语： " << englishScore << endl;
	cout << "思想品德： " << moralScore << "科学： " << scienceScore << "计算机： " << computerScore << endl;
}