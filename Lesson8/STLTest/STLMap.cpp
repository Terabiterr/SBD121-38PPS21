#include <iostream>
#include <map>
#include <string>
using namespace std;

template<class T1, class T2>
class Dictonary {
public:
    Dictonary() { cout << "Created:\t" << typeid(this).name() << endl; }
    void Add(T1 key, T2 value)
    {
        m.insert(pair<T1, T2>(key, value));
    }
    void PrintDictonary()
    {
        //map<T1, T2>::iterator itr; // В шаблонных классах компилятор не даст использовать итератор таким способом. Специфика template
        for (auto itr = m.begin(); itr != m.end(); itr++) {
            cout << itr->first << " = " << itr->second << endl;
        }
    }
    map<T1, T2>& GetDictonary() { return m; }
private:
    map<T1, T2> m;
};
 
template<class T1, class T2>
class BookDeitel final : public Dictonary<T1, T2> {
public:
    BookDeitel() { cout << "Created:\t" << typeid(this).name() << endl; }
    string GetTitle() { return _title; }
    void SetTitle(string title) { _title = title; }
private:
    string _title;
};

template<class T1, class T2>
class BookCPlusPlus : public BookDeitel<T1, T2> {
public:
    BookCPlusPlus() { cout << "Created:\t" << typeid(this).name() << endl; }
};

//class ComicNinja final {};
//class ComicNinjaTurtles : public ComicNinja {}; // Нельзя наследовать класс помеченный final

int main()
{
    BookDeitel<int, string> deitel;
    deitel.SetTitle("C++ OOP");
    deitel.Add(1, "History");
    deitel.Add(5, "if else");
    deitel.Add(6, "if else");
    deitel.Add(2, "variables");
    deitel.Add(3, "types");
    deitel.Add(6, "OOP");
    deitel.Add(6, "OOP"); // map не поддерживает одинаковых ключей. Он их откинет. 
    deitel.Add(6, "OOP");
    deitel.Add(6, "OOP");
    deitel.PrintDictonary();
    //--------------------------------------
    //BookCPlusPlus<int, string> cplusplus;
    //cplusplus.SetTitle("C++ OOP"); // Ошибка! Нельзя взять методы класса, который помечен final
    //cplusplus.Add(1, "History");
    //cplusplus.Add(5, "if else");
    //cplusplus.Add(2, "variables");
    //cplusplus.Add(3, "types");
    //cplusplus.Add(6, "OOP");
    //cplusplus.PrintDictonary();
    return 0;
}
