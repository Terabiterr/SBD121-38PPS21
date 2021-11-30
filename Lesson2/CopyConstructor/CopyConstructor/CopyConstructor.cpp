#include <iostream>
using namespace std;

class CopyConstructor
{
public:
    CopyConstructor(const CopyConstructor& other) { // Конструктор копирования
        this->size = other.size; // копируем size с другого объекта
        this->arr = new int[this->size]; // так как память очистится новым деструктором. Нам нужно снова ее выделить для нашего массива
        for (int i = 0; i < other.size; i++)
            this->arr[i] = other.arr[i];  // полное копирование нашего массива из другого объкта такого же типа и его массива
    }
    CopyConstructor(int size) { // конструктор с параметром size
        this->size = size;
        arr = new int[this->size]; // Выделить память для массива размером size
    }
    ~CopyConstructor() { // деструктор
        cout << "Destroyed:" << this << endl;
        delete[size] arr; // удалить массив
    }
    int GetSize() { return size; } // Получить текущий size
private:
    int size; // Размер массива
    int* arr; // динамический массив типа int
};
/*
Здесь не явно будет вызван скрытый конструктор копирования, который создаст новую копию нашего объекта
Если раскомментировать наш личный конструктор копирования, не явный уже не будет вызван и не будет ошибки
*/
void DisplaySize(CopyConstructor test) { // Полная копия объекта скрытым конструктором копирования 
    cout << "size arr = " << test.GetSize() << endl; // Показать size
}

void main()
{
    /*При запуске программы мы получаем 2 раза деструктор, а как мы помним мы в деструкторе чистим arr*/
    CopyConstructor сс(10); // Создать объект класса CopyConstructor и передать в конструктор size число 10
    /*Если раскомментировать наш конструктор копирования, то ошибки не будет*/
    DisplaySize(сс); // Передаем в функцию объект класса
}
