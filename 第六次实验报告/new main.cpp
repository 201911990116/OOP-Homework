#include<iostream>
#include"cstdlib"

using namespace std;


class Graduate
{
private:
	string name;
	bool gender;
	string id;
	double score;
	string research;
	string tutor;
	const string university;
public:
	Graduate(string Name = "Xiao wei", bool Gender = 1, string Id = "201911990116", double Score = 400, string Research = "computer", string Tutor = "Zhangqingke") :university("SDNU")
	{
		name = Name;
		gender = Gender;
		id = Id;
		score = Score;
		research = Research;
		tutor = Tutor;

	}
	void graduate(string Name, bool Gender, string Id, double Score, string Research, string Tutor)
	{
		name = Name;
		gender = Gender;
		id = Id;
		score = Score;
		research = Research;
		tutor = Tutor;
	}
	Graduate(const Graduate& graduate) :university("SDNU")
	{
		name = graduate.name;
		gender = graduate.gender;
		id = graduate.id;
		score = graduate.score;
		research = graduate.research;
		tutor = graduate.tutor;
	}
	~Graduate()
	{
		cout << "The destructor is called!" << endl;
	}
	void OutPut();
	void Output() const;
	static void Average(Graduate *graduate);
	friend void Rank(Graduate* graduate);
};

void Graduate::OutPut()
{
	cout << "name:"<< name << endl;
	cout << "gender:" << gender << endl;
	cout << "student number:" << id << endl;
	cout << "score:" << score << endl;
	cout << "research field:" << research << endl;
	cout << "tutor:" << tutor << endl;
	cout << "university:" << university << endl;
}

void Graduate::Output() const
{
	cout << "name:"<< name << endl;
	cout << "gender:" << gender << endl;
	cout << "student number:" << id << endl;
	cout << "score:" << score << endl;
	cout << "research field:" << research << endl;
	cout << "tutor:" << tutor << endl;
	cout << "university:" << university << endl;
}

void Graduate::Average(Graduate *graduate)
{
	double sum = 0.0;
	for (int i = 0; i < 3; i++)
		sum += graduate[i].score;
	double ave = sum / 3.0;
	cout << "the average is:" << ave << endl;
}

int main()
{
	Graduate graduate[3];
	Graduate student;
	Graduate const Student;
	string name;
	bool gender;
	string id;
	double score;
	string research;
	string tutor;
	student.OutPut();
	Student.Output();
	for (int i = 0; i < 3; i++)
	{
		cout << "name: ";
		cin >> name;

		cout << "gender: ";
		cin >> gender;

		cout << "id: ";
		cin >> id;

		cout << "score: ";
		cin >> score;

		cout << "research: ";
		cin >> research;

		cout << "tutor:";
		cin >> tutor;

		graduate[i].graduate(name, gender, id, score, research, tutor);
	}
	graduate[3].Average(graduate);
	Rank(graduate);
	system("pause");
	return 0;
}

void Rank(Graduate* graduate)
{
	for (int i = 0; i < 3; i++)
	{
		switch (int(graduate[i].score) / 10)
		{
		case 9:
			cout << "A" << endl; break;
		case 8:
			cout << "B" << endl; break;
		case 7:
			cout << "C" << endl; break;
		case 6:
			cout << "D" << endl; break;
		default:
			cout << "E" << endl; break;
		}
	}
}
