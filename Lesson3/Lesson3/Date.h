#pragma once
#include <ostream>
#include <string>
#include <iostream>
using namespace std;
class Date
{
public:
	Date();
	Date(int day, int month, int year); // 12 байт
	friend ostream& operator<< (ostream& out, const Date& date); // Перегрузка оператора <<
	Date& operator= (const Date& right);
	const Date operator+ (const Date& right);
	const Date operator- (const Date& right);
	const Date & operator+= (const Date& right);
	const Date & operator-= (const Date& right);
	bool operator!= (const Date& right);
	bool operator== (const Date& right);
	bool operator<= (const Date& right);
	bool operator>= (const Date& right);
	bool operator< (const Date& right);
	bool operator> (const Date& right);
	Date& operator++(); // Префиксный инкремент (пре-инкремент)	++x	Инкремент x, затем вычисление x
	Date& operator--(); // Префиксный декремент (пре-декремент)	−−x	Декремент x, затем вычисление x
	Date operator++(int); //Постфиксный инкремент (пост-инкремент) x++ Вычисление x, затем инкремент x
	Date operator--(int); //Постфиксный декремент(пост-декремент) x−− Вычисление x, затем декремент x
	Date& operator[] (const int index);
	void* operator new[](size_t size); // Пользовательская логика для выделения памяти под массив объектов (К примеру обработка исключений при выделении памяти)
	void operator delete[](void* ptr); // Пользовательская логика для удаления памяти (К примеру обработка исключений при очистках памяти)
private:
	int _day;
	int _month;
	int _year;
	void ShiftDate31();
};