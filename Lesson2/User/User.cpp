#include <iostream>
#include <string>
#include <sstream>
#include "Interests.h";

using namespace std;

class User {
public:
    User() : User{ 0, "" } //Конструктор по умолчанию делегирует на конструктор с параметрами
    {
        cout << "constructor default:\t" << endl;
    }
    User(int id, string name) // Конструктор с параметрами
        : _id{ id },
        _name{ name }
    {
        interests = nullptr;
        cout << "constructor with params:\t" << endl;
    }
    ~User()
    {
        cout << "User destroyed:\t" << this << endl;
        delete[] interests;
    }
    void Setinterests(Interests interests)
    {
        Interests* tmpInterests = new Interests[++_lengthinterests]; // Выделить новую память для временного массива
        for (int i = 0; i < _lengthinterests - 1; i++)
            tmpInterests[i] = this->interests[i]; // Копируем все элементы из старого массива в новый
        delete[] this->interests; // Очищаем старый массив
        this->interests = new Interests[_lengthinterests]; // Выделить память на 1 элемент больше в текущем массиве
        for (int i = 0; i < _lengthinterests; i++)
            this->interests[i] = tmpInterests[i]; // Скопировать временный в новый текущего класса
        delete[] tmpInterests; // Очистить временный массив
        this->interests[_lengthinterests - 1] = interests; // Добавляем новый элемент
    }
    string ToString()
    {
        stringstream ss;
        ss << "id:\t" << _id << "\n"
            << "name:\t" << _name << "\n";
        ss << "interests:\n";
        for (int i = 0; i < _lengthinterests; i++)
        {
            ss << interests[i].GetThing() + "\t" << "\n";
        }
        return ss.str();
    }
private:
    int _id;
    string _name;
    Interests* interests;
    int _lengthinterests;
};

int main()
{
    User user(1, "Alex");
    user.Setinterests(Interests("films"));
    user.Setinterests(Interests("computers"));
    user.Setinterests(Interests("programming"));
    user.Setinterests(Interests("news"));
    user.Setinterests(Interests("ball"));
    user.Setinterests(Interests("nature"));
    cout << user.ToString();
}
