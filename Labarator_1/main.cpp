#include <iostream>
#include <stdlib.h> 
#include <conio.h> 
#include <string.h> 
#include <stdio.h> 
#include "worker.h" 
#include "func.h" 

using namespace std;

int main()
{

	worker rab[10];
	setlocale(LC_ALL, "rus");
	int i = 0;
	int  note;
	int n = 0;
	int num;
	while (1)
	{
		while (1)
		{
			cout << "1 - ���� ������\n2 - �������� ��� ������ � ���������� ������� \n3 - ����� �� �������\n4 - �������� ������\n5 - �����\n\n";

			cout << "������� �����:\n";
			cin >> num;
			if (num > 5 || num < 1)
			{
				cout << "\n����������� ������� ������!��� ����������� ������� ����� ������.\n";
				_getch();
				system("cls");
				continue;
			}
			break;
		}

		switch (num)
		{
		case 1: system("cls");
			for (int i = 0; i < 10; i++)
			{
				while (1)
				{
					system("cls");
					cin >> rab[i];
					try
					{
						for (int j = 0; j < 10; j++)
						{
							if ((rab[i].take_fio() == rab[j].take_fio()) && i != j)
								throw 7;
						}
					}

					catch (int p)
					{
						cout << "������. ������ �������� ��� ���������� � ����.\n";
						cout << "\n��� ����������� ������� ����� ������.\n";
						_getch();
						continue;
					}
					break;
				}
			}
			cout << "\n��� ����������� ������� ����� ������.\n";
			_getch();
			system("cls");
			break;

		case 2: system("cls");
			sort(rab);
			disp(rab);
			cout << "\n��� ����������� ������� ����� ������.\n";
			_getch();
			system("cls");
			break;

		case 3: system("cls");
			sort(rab);
			search(rab);
			cout << "\n��� ����������� ������� ����� ������.\n";
			_getch();
			system("cls");
			break;

		case 4: system("cls");
			sort(rab);

			while (1)
			{
				disp(rab);
				cout << "������� ����� ������������� ������:\n";
				cin >> note;
				if (note > 10 || note < 1)
				{
					cout << "\n����������� ������� ������!��� ����������� ������� ����� ������.\n";
					_getch();
					system("cls");
					continue;
				}
				break;

			}

			while (1)
			{
				system("cls");
				cin >> rab[note - 1];
				try
				{
					for (int j = 0; j < 10; j++)
					{
						if ((rab[note - 1].take_fio() == rab[j].take_fio()) && ((note - 1) != j))
							throw 7;
					}
				}

				catch (int p)
				{
					cout << "������. ������ �������� ��� ���������� � ����.\n";
					cout << "\n��� ����������� ������� ����� ������.\n";
					_getch();
					continue;
				}
				break;
			}
			cout << "\n��� ����������� ������� ����� ������.\n";
			_getch();
			system("cls");
			break;

		case 5:

			cout << "�� ��������!\n";
			return 0;
			break;
		}
	}
}
