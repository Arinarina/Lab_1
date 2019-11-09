#include "worker.h"

#include <stdlib.h> 

#include <conio.h> 

#include <stdio.h> 

#include <cstring>

#define N 10

#define _CRT_SECURE_NO_WARNINGS 

using namespace std;


void worker::set_fio(char* data)

{

	long int size = strlen(data);

	delete[] fio;

	fio = NULL;

	fio = new char[size + 1];

	strcpy(fio, data);

	return;

}

void worker::set_position(char* data)

{

	long int size = strlen(data);

	delete[] position;

	position = NULL;

	position = new char[size + 1];

	strcpy(position, data);

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

	cout << "Фамилия и инициалы: " << fio << "\n";

	return;

}

void worker::get_position(void)

{

	cout << "Занимаемая должность: " << position << "\n";

	return;

}

void worker::get_year(void)

{

	cout << "Год поступления на работу: " << year << "\n";

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

	//cout << "Введите фамилию и инициалы:\n";
	gets_s(str1);
	obj.set_fio(str1);
	while (1)
	{
		cout << "Введите фамилию и инициалы:\n";
		gets_s(str);


		/*if (test_stroka(str) == false)
		{
			cout << "\nНеккоректно введены данные!Для продолжения нажмите любую кнопку.\n";
			_getch();
			system("cls");
			continue;
		}*/
		break;
	}
	obj.set_fio(str);




	while (1)
	{
		cout << "Введите занимаемую должность:\n";
		gets_s(str);


		/*if (test_stroka(str) == false)
		{
			cout << "\nНеккоректно введены данные!Для продолжения нажмите любую кнопку.\n";
			_getch();
			system("cls");
			continue;
		}*/
		break;
	}
	obj.set_position(str);


	while (1)
	{
		cout << "Введите год поступления на работу:\n";
		cin >> data_year;

		if (data_year > 2020 || data_year < 1960)
		{
			cout << "\nНеккоректно введены данные!Для продолжения нажмите любую кнопку.\n";
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

bool operator < (worker obj1, worker obj2) {
	if ((strcmp(obj2.take_fio(), obj1.take_fio()) > 0) && (strcmp(obj2.take_position(), " ") != 0) && (strcmp(obj1.take_position(), " ") != 0))
		return true;
	else
		return false;

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

	long int size = strlen(src.fio);
	fio = new char[size + 1];
	strcpy(fio, src.fio);
	size = strlen(src.position);
	position = new char[size + 1];
	strcpy(position, src.position);
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

	long int size = strlen(src.fio);
	fio = new char[size + 1];
	strcpy(fio, src.fio);
	size = strlen(src.position);
	position = new char[size + 1];
	strcpy(position, src.position);
	year = src.year;
	return *this;
}

int worker::take_year(void)
{
	return year;
}

worker::worker(char* data_fio, char* data_position, int data_year)
{
	long int size = strlen(data_fio);
	fio = NULL;
	fio = new char[size + 1];
	strcpy(fio, data_fio);
	size = strlen(data_position);
	position = NULL;
	position = new char[size + 1];
	strcpy(position, data_position);
	year = data_year;
}
void disp(worker obj[])
{
	int count = 1;
	cout << "\t\t\t\tВся информация:\n\n";
	for (int i = 0; i < N; i++)
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
	cout << "Введите необходимый стаж работы для поиска сотрудников: \n";
	cin >> stag;

	cout << "\t\t\t Сотрудники, чей стаж работы не превышает " << stag << " лет (года) \n\n";
	int i;
	int flag = 0;
	for (i = 0; i < N; ++i) {
		if (stag >= (2020 - obj[i].take_year())) {
			flag++;
			cout << obj[i] << "\n\n";
		}

	}
	if (flag == 0)
		cout << "Нет таких работников!\n";
	return;

}
