#include "worker.h"

#include <stdlib.h> 

#include <conio.h> 

#include <stdio.h> 

using namespace std;


void worker::set_fio(char* data)

{

	long int size = dlina(data);

	delete[] fio;

	fio = NULL;

	fio = new char[size + 1];

	copy(fio, data);

	return;

}

void worker::set_position(char* data)

{

	long int size = dlina(data);

	delete[] position;

	position = NULL;

	position = new char[size + 1];

	copy(position, data);

	return;

}

void worker::set_year(int data)

{

	year = 0;

	year = data;

	return;

}

void worker::get_fio(void)

{

	cout << "������� � ��������: " << fio << "\n";

	return;

}

void worker::get_position(void)

{

	cout << "���������� ���������: " << position << "\n";

	return;

}

void worker::get_year(void)

{

	cout << "��� ����������� �� ������: " << year << "\n";

	return;

}

worker::worker()

{
	fio = new char[2];

	*(fio + 0) = ' ';

	*(fio + 1) = '\0';

	position = new char[2];

	*(position + 0) = ' ';

	*(position + 1) = '\0';

	year = 0;

}

worker::~worker()

{

	delete[] fio;

	fio = NULL;

	delete[] position;

	position = NULL;

	year = 0;

}

istream& operator>>(istream& stream, worker& obj)

{
	//fflush(stdin);
	char str1[100];
	char str[100];
	int data_year;

	//cout << "������� ������� � ��������:\n";
	gets_s(str1);
	obj.set_fio(str1);
	while (1)
	{
		cout << "������� ������� � ��������:\n";
		gets_s(str);


		if (test(str) == false)
		{
			cout << "\n����������� ������� ������!��� ����������� ������� ����� ������.\n";
			_getch();
			system("cls");
			continue;
		}
		break;
	}
	obj.set_fio(str);




	while (1)
	{
		cout << "������� ���������� ���������:\n";
		gets_s(str);


		if (test(str) == false)
		{
			cout << "\n����������� ������� ������!��� ����������� ������� ����� ������.\n";
			_getch();
			system("cls");
			continue;
		}
		break;
	}
	obj.set_position(str);


	while (1)
	{
		cout << "������� ��� ����������� �� ������:\n";
		cin >> data_year;

		if (data_year > 2020 || data_year < 1960)
		{
			cout << "\n����������� ������� ������!��� ����������� ������� ����� ������.\n";
			_getch();
			system("cls");
			continue;
		}
		break;
	}

	obj.set_year(data_year);
	return stream;

}

ostream& operator<<(ostream& stream, worker& obj)
{
	obj.get_fio();
	obj.get_position();
	obj.get_year();
	return stream;
}

char* worker::take_fio(void)
{
	return fio;
}

char* worker::take_position(void)
{
	return position;
}

worker::worker(const worker& src)
{
	if (fio)
	{
		delete[] fio;
		fio = NULL;
	}

	if (position)
	{
		delete[] position;
		position = NULL;
	}

	long int size = dlina(src.fio);
	fio = new char[size + 1];
	copy(fio, src.fio);
	size = dlina(src.position);
	position = new char[size + 1];
	copy(position, src.position);
	year = src.year;
}

worker& worker::operator=(const worker& src)
{
	if (fio)
	{
		delete[] fio;
		fio = NULL;
	}

	if (position)
	{
		delete[] position;
		position = NULL;
	}

	long int size = dlina(src.fio);
	fio = new char[size + 1];
	copy(fio, src.fio);
	size = dlina(src.position);
	position = new char[size + 1];
	copy(position, src.position);
	year = src.year;
	return *this;
}

int worker::take_year(void)
{
	return year;
}

worker::worker(char* data_fio, char* data_position, int data_year)
{
	long int size = dlina(data_fio);
	fio = NULL;
	fio = new char[size + 1];
	copy(fio, data_fio);
	size = dlina(data_position);
	position = NULL;
	position = new char[size + 1];
	copy(position, data_position);
	year = data_year;
}
void disp(worker obj[])
{
	int count = 1;
	cout << "\t\t\t\t��� ����������:\n\n";
	for (int i = 0; i < 10; i++)
	{
		if (*obj[i].take_fio() == ' ' && *obj[i].take_position() == ' ' && obj[i].take_year() == 0)
			continue;
		cout << "***** " << count << " *****\n";
		count++;
		cout << obj[i];
		cout << "\n\n";
	}
	return;
}
void search(worker obj[]) {
	int stag;
	cout << "������� ����������� ���� ������ ��� ������ �����������: \n";
	cin >> stag;

	cout << "\t\t\t ����������, ��� ���� ������ �� ��������� " << stag << " ��� (����) \n\n";
	int i;
	int flag = 0;
	for (i = 0; i < 10; ++i) {
		if (stag >= (2020 - obj[i].take_year())) {
			flag++;
			cout << obj[i] << "\n\n";
		}

	}
	if (flag == 0)
		cout << "��� ����� ����������!\n";
	return;

}
