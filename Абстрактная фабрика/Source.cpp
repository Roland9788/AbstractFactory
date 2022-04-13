#include<iostream>
#include<conio.h>
using namespace std;

class Animal
{
public:

	string Name;
	string Paroda;
	Animal()
	{
		Name = "None";
	}

	virtual void Speek() = 0;

	virtual void GetName() = 0;
};

class Flying: public Animal
{
protected:

	virtual void Speek()
	{
		cout << "\nChik-Chirik\n";
	}

	virtual void GetName()
	{
		Name = "\nПтица\n";
		cout << Name;
	}

};

class Parrot:protected Flying
{
protected:

	void CreateParrot()
	{
		Paroda = "Попугай";
	}

	void Print()
	{
		cout << "\nСоздан " << Paroda << "\n";
		Flying::Speek();
		Flying::GetName();
	}

};

class Reptiles: public Animal
{

protected:

	virtual void Speek()
	{
		cout << "\nPshhh...\n";
	}

	virtual void GetName()
	{
		Name = "\nРептилии\n";
		cout << Name;
	}

};

class Snake: protected Reptiles
{

protected:

	void CreateSnake()
	{
		Paroda = "Змея";
	}

	void Print()
	{
		cout << "\nСоздана " << Paroda << "\n";
		Reptiles::Speek();
		Reptiles::GetName();
	}


};

class Mammals : public Animal
{

protected:

	virtual void Speek()
	{
		cout << "\nRrrr...\n";
	}

	virtual void GetName()
	{
		Name = "\nМлекопитающие\n";
		cout << Name;
	}

};

class Bear: protected Mammals
{
protected:

	void CreateBear()
	{
		Paroda = "Медведь";
	}

	void Print()
	{
		cout << "\nСоздан " << Paroda << "\n";
		Mammals::Speek();
		Mammals::GetName();
	}

};

class Interface: protected Parrot, Snake, Bear
{
	string ID;

public:

	void Print()
	{
		if (this->ID == "1")
		{
			Parrot::CreateParrot();
			Parrot::Print();
		}
		if (this->ID == "2")
		{
			Snake::CreateSnake();
			Snake::Print();
		}
		if (this->ID == "3")
		{
			Bear::CreateBear();
			Bear::Print();
		}
	}

	void SetID(string ID)
	{
		this->ID = ID;
	}
	
};


int main()
{
	setlocale(LC_ALL, "Rus");
	Interface interface;
	string buff;
	do
	{
		cout << "\nВведите айди животного корого хотите создать или 0 что бы закончить работу программы\n";
		cout << "\n1 - попугай\n";
		cout << "\n2 - Змея\n";
		cout << "\n3 - Медведь\n";
		do
		{
			buff = _getch();

		} while (buff == "115");

		system("cls");
		interface.SetID(buff);
		interface.Print();
		cout << "\n\n";

	} while (buff != "0");

	return 0;
}