#include <iostream>
#include <stdlib.h> 
#include <conio.h> 
#include <string.h> 
#include <stdio.h> 
#include "worker.h" 
#include "func.h" 
#define N 10
using namespace std;

int main()
{

	worker rabotnik[10];
	setlocale(LC_ALL, "rus");
	int i = 0;
	int  note;
	int n = 0;
	int num;
	while (1)
	{
		while (1)
		{
			cout << "1 - Ввод данных\n2 - Показать все данные в алфавитном порядке \n3 - Поиск по заданию\n4 - Изменить данные\n5 - Выход\n\n";

			cout << "Введите номер:\n";
			cin >> num;
			if (num > 5 || num < 1)
			{
				cout << "\nНеккоректно введены данные!Для продолжения нажмите любую кнопку.\n";
				_getch();
				system("cls");
				continue;
			}
			break;
		}

		switch (num)
		{
		case 1: system("cls");
			for (int i = 0; i < N; i++)
			{
				while (1)
				{
					system("cls");
					cin >> rabotnik[i];
					try
					{
						for (int j = 0; j < N; j++)
						{
							if ((rabotnik[i].take_fio() == rabotnik[j].take_fio()) && i != j)
								throw 7;
						}
					}

					catch (int p)
					{
						cout << "Ошибка. Данный работник уже существует в базе.\n";
						cout << "\nДля продолжения нажмите любую кнопку.\n";
						_getch();
						continue;
					}
					break;
				}
			}
			cout << "\nДля продолжения нажмите любую кнопку.\n";
			_getch();
			system("cls");
			break;

		case 2: system("cls");
			sort(rabotnik);
			disp(rabotnik);
			cout << "\nДля продолжения нажмите любую кнопку.\n";
			_getch();
			system("cls");
			break;

		case 3: system("cls");
			sort(rabotnik);
			search(rabotnik);
			cout << "\nДля продолжения нажмите любую кнопку.\n";
			_getch();
			system("cls");
			break;

		case 4: system("cls");
			sort(rabotnik);

			while (1)
			{
				disp(rabotnik);
				cout << "Введите номер редактируемой записи:\n";
				cin >> note;
				if (note > N || note < 1)
				{
					cout << "\nНеккоректно введены данные!Для продолжения нажмите любую кнопку.\n";
					_getch();
					system("cls");
					continue;
				}
				break;

			}

			while (1)
			{
				system("cls");
				cin >> rabotnik[note - 1];
				try
				{
					for (int j = 0; j < N; j++)
					{
						if ((rabotnik[note - 1].take_fio() == rabotnik[j].take_fio()) && ((note - 1) != j))
							throw 7;
					}
				}

				catch (int p)
				{
					cout << "Ошибка. Данный работник уже существует в базе.\n";
					cout << "\nДля продолжения нажмите любую кнопку.\n";
					_getch();
					continue;
				}
				break;
			}
			cout << "\nДля продолжения нажмите любую кнопку.\n";
			_getch();
			system("cls");
			break;

		case 5:

			cout << "До свидания!\n";
			return 0;
			break;
		}
	}
}
