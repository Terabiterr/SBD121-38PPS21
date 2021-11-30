#include <iostream>
// Рекомендую поставить точку остановы на деструкторе и пройтись отладчиком кода
class B{}; // Тип B

class A { // Тип A
public:
    int x;
    int GetX() { return x; }
    void SetX(int x) { this->x = x; }
    B* b;
    //A(const A& oldA) { // Консутрктор копирования
    //    this->b = new B[10];
    //    for (int i = 0; i < 10; i++)
    //        this->b[i] = oldA.b[i];
    //    std::cout << "copy constructor B" << std::endl;
    //}
    A() { b = new B[10]; x = 0; }
    ~A() { 
        std::cout << "Destructor A:\t" << std::endl;
        delete[] b;
    }
};

void main()
{
    A a1;
    A * a2 = &a1;
    a2->SetX(5);
    std::cout << a1.GetX() << std::endl;

    //A a4 = *(a2); // Будет вызван не явный конструктор копирования Что бы не было ошибки, нужно раскомментировать явный конструктор копирования
    //A a3 = a1; // Будет вызван не явный конструктор копирования Что бы не было ошибки, нужно раскомментировать явный конструктор копирования
}
