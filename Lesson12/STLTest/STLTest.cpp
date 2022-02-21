//#include <iostream>
//
//using std::cout;
//
//class Square {
//public:
//    int operator() (const int value) const {
//        return value * value;   //возводим в квадрат
//    }
//};
//
//int main() {
//    Square sq;
//    cout << sq(10) << '\n';     // 10 * 10 = 100
//    cout << sq(20) << '\n';     // 20 * 20 = 400
//}
#include <functional> 
#include <numeric>
#include <algorithm> 
#include <vector> 
#include <iostream> 
#include <iterator>
using namespace std;

/////////////////////////////////////////////////////////////////////////////
// создание объекта-функции для заполнения случайными числами 
// функция Rand - шаблон, наследник от стандартной функции unary_function
// параметры шаблона: PAR - тип данных, void - возвращаемое значение оператора ()
template <class PAR>
class Rand : public unary_function<PAR, void>
{
    // диапазон случайных чисел
    PAR m_min, m_max;
public:
    // конструктор, в котором задается диапазон случайных чисел
    Rand(PAR min, PAR max)
        : m_min(min), m_max(max)
    { }

    // перегруженный оператор вызова функции, в котором число value заполняется случайным числом
    void operator() (PAR& value)
    {
        value = (PAR)(rand() * (m_max - m_min)) / RAND_MAX + m_min;
    }
};
/////////////////////////////////////////////////////////////////////////////
// создание объекта-функции определения попадания числа в диапазон
// функция InRange - шаблон, наследник от стандартной функции unary_function
// параметры шаблона: int - тип данных, bool - возвращаемое значение оператора ()
class InRange : public unary_function<int, bool>
{
    // диапазон чисел
    int m_left, m_right;
public:
    // конструктор, в котором задается диапазон
    InRange(int left, int right)
        : m_left(left), m_right(right)
    {}

    // перегруженный оператор вызова функции, в котором определяется 
    // попадание числа value в диапазон от m_left до m_right
    bool operator() (const int& value)
    {
        return (value > m_left && value < m_right);
    }
};
/////////////////////////////////////////////////////////////////////////////
// тестирование предикатов
void main()
{
    vector<int> v(10);

    // заполнение контейнера случайными числами при помощи объекта-функции Rand
    for_each(v.begin(), v.end(), Rand<int>(-10, 10));
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // сортировка с использованием предиката greater
    sort(v.begin(), v.end(), greater<int>());
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // использование InRange для подсчета количества элементов в диапазоне от 0 до 10 
    cout << count_if(v.begin(), v.end(), InRange(0, 10));
    cout << endl;
}
/////////////////////////////////////////////////////////////////////////////
