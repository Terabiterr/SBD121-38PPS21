#include <iostream>
#include "Vector.h"
#include "Vector.cpp" // В шаблонном многофайловом проекте это обязательно !!!

template<typename T>
int GetVectorSize(T & collecton) // Шаблонная функция
{
    return collecton.size();
}

//template<class T>
//void swap(T& object1, T& object2)
//{
//    T tmp{ std::move(object1) }; // вызывает конструктор перемещения
//    object1 = std::move(object2); // вызывает оператор присваивания перемещением
//    object2 = std::move(tmp); // вызывает оператор присваивания перемещением
//}

int main()
{
    
    // добавление в конец вектора
    Vector<int> vector;
    vector.push_back(5);
    vector.push_back(6);
    vector.push_back(7);
    vector.push_back(8);
    vector.push_back(9);
    cout << "vector:\n";
    cout << vector << endl;
    // извлечь с конца вектора
    vector.pop_back();
    vector.pop_back();
    cout << "vector:\n";
    cout << vector << endl;

    Vector<int> vector2 = { move(vector) }; // Конструктор перемещения
    cout << "vector:\n";
    cout << "Vector size:\t" << GetVectorSize(vector) << endl;
    cout << "vector2:\n";
    cout << "Vector size:\t" << GetVectorSize(vector2) << endl; // size = 0 Это значит, что мы из объекта 1 забрали данные в объект 2
    cout << "vector2:\n";
    cout << vector2 << endl;
    
    Vector<int> vector3;
    vector3 = move(vector2); // Оператор присваивания
    cout << "vector2:\n";
    cout << "Vector size:\t" << GetVectorSize(vector2) << endl;
    cout << "vector3:\n";
    cout << vector3 << endl;
    cout << "vector3:\n";
    cout << "Vector size:\t" << GetVectorSize(vector3) << endl;

    swap(vector, vector3); // Встроенная функция для перестановки объектов или чего либо
    cout << "vector:\n";
    cout << vector << endl; // вернули данные обратно в vector

    Vector<double> vectorDouble;
    vectorDouble.push_back(25.50);
    vectorDouble.push_back(10.25);
    vectorDouble.push_back(25);

    Vector<double> vectorDouble2 = vectorDouble; // Так будет вызван конструктор копирования Vector<double> vectorDouble2 = vectorDouble;
    vectorDouble2 = vectorDouble; // Так мы вызываем оператор присваивания. 
    cout << "vectorDouble2:\n";
    cout << "vectorDouble2 size:\t" << GetVectorSize(vectorDouble2) << endl;
    cout << vectorDouble2 << endl;

    return 0;
}
