#include <iostream>
#include <time.h>
#include <string>
#include <fstream>

#include <vector>

using namespace std;
//---------------------Функции и Прототипы---------------------------------------

class Worker
{
public:

	string name;
	int experience;
	int h_payment;
	int hours;
	int salary;
	int premy;

	Worker()
	{
		cout << "\nEnter worker's name: ";
		cin >> name;
		cout << "\nEnter worker's experience: ";
		cin >> experience;
		cout << "\nEnter worker's hourly payment: ";
		cin >> h_payment;
		cout << "\nEnter hours of work: ";
		cin >> hours;
	}

	void Salary()
	{
		salary = hours * h_payment;
	}

	void Premy()
	{

		if (experience < 1)
		{
			premy = 0;
		}
		else if (experience < 3)
		{
			premy = salary * 0.05;
		}
		else if (experience < 5)
		{
			premy = salary * 0.08;
		}
		else
		{
			premy = salary * 0.15;
		}

	}

	void Print()
	{
		cout << name << "\nExperience is " << experience << "\nHourly payment is " << h_payment <<
			"\n" << name << " has worked " << hours << " hours" << "\nSalary is " << salary <<
			"\nPremy is " << premy << endl;
	}

	void Save()
	{
		string out;
		cout << "\nEnter file name: ";
		cin >> out;

		ofstream fout;

		fout.open(out);

		if (!fout.is_open())
		{
			cout << "\nError! open file.";
		}
		else
		{
			cout << "\nInformation was writen in file : '" << out << "'.";

			fout << "Name is " << name << "\nExperience is " << experience << "\nHourly payment is " << h_payment <<
				"\n" << name << " has worked " << hours << " hours" << "\nSalary is " << salary <<
				"\nPremy is " << premy;

			cout << endl;
		}

	}

};



//------------------------MAIN----------------------------------------------------
int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	//-------------------------------САМА ПРОГА-------------------------------------

	Worker Andrey;

	Andrey.Salary();
	Andrey.Premy();
	Andrey.Print();
	Andrey.Save();






	system("pause");
	return 0;
}
