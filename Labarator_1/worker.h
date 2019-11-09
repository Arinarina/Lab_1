#pragma once

#include <iostream> 
#include <stdio.h> 
#include <string> 
 

using namespace std;

class worker
{
private:

	char* fio;

	char* position;

	int year;

public:

	void set_fio(char* data);

	void set_position(char* data);

	void set_year(int data);

	void get_fio(void);

	void get_position(void);

	void get_year(void);

	char* take_fio(void);

	char* take_position(void);

	int take_year(void);

	worker();

	worker(char* data_fio, char* data_position, int data_year);

	~worker();

	worker(const worker& src);

	worker& operator=(const worker& src);

	friend ostream& operator<<(ostream& os, worker& obj);

	friend istream& operator>>(istream& stream, worker& obj);

	friend bool operator < (worker obj1, worker obj2);

	friend void disp(worker obj[]);

	friend void search(worker obj[]);


};



