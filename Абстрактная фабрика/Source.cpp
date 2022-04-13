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
		Name = "\n�����\n";
		cout << Name;
	}

};

class Parrot:protected Flying
{
protected:

	void CreateParrot()
	{
		Paroda = "�������";
	}

	void Print()
	{
		cout << "\n������ " << Paroda << "\n";
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
		Name = "\n��������\n";
		cout << Name;
	}

};

class Snake: protected Reptiles
{

protected:

	void CreateSnake()
	{
		Paroda = "����";
	}

	void Print()
	{
		cout << "\n������� " << Paroda << "\n";
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
		Name = "\n�������������\n";
		cout << Name;
	}

};

class Bear: protected Mammals
{
protected:

	void CreateBear()
	{
		Paroda = "�������";
	}

	void Print()
	{
		cout << "\n������ " << Paroda << "\n";
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
		cout << "\n������� ���� ��������� ������ ������ ������� ��� 0 ��� �� ��������� ������ ���������\n";
		cout << "\n1 - �������\n";
		cout << "\n2 - ����\n";
		cout << "\n3 - �������\n";
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