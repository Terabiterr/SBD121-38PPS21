#include <iostream>
#include <string>
#include "List.h"
#include "List.cpp"

using namespace std;

class Student 
{
    class Language { public: string _languages; }; // Вложенный класс в Student
public:
    void SetLanguage(string languages) { language._languages = languages; }
    string GetLanguage() { return language._languages; }
    static bool CompareTo(Student& s1, Student& s2) { return s1.GetLanguage()._Equal(s2.GetLanguage()); }
private:
    Language language;
};

template<class T>
static List<T>& Sort(List<T>& list) // Sort
{
    Node<T>* tmp = &list.GetHead();
    if (tmp->data.CompareTo(tmp->data, tmp->data)) // CompareTo
    {
        cout << "*******_Equal:\t" << endl;
    }
    return list;
}

int main()
{
    Student student; 
    student.SetLanguage("Javascript");
    Student student1;
    student1.SetLanguage("Java");
    Student student2;
    student2.SetLanguage("C#");
    Student student3;
    student3.SetLanguage("Python");
    Student student4;
    student4.SetLanguage("C++");
    
    List<Student> students;
    
    students.Add(student);
    students.Add(student1);
    students.Add(student2);
    students.Add(student3);
    students.Add(student4);

    //head to tail
    cout << "head to tail:\t" << endl;
    Node<Student> * tmp = &students.GetHead();
    while (tmp != nullptr) // show all the students and them interests
    {
        cout << tmp->data.GetLanguage() << "\t";
        tmp = tmp->next;
    }
    cout << endl;
    //tail to head
    cout << "tail to head:\t" << endl;
    tmp = &students.GetTail();
    while (tmp != nullptr) // show all the students and them interests
    {
        cout << tmp->data.GetLanguage() << "\t";
        tmp = tmp->previous;
    }
    cout << endl;

    cout << "operator[2]\t" << students[2].GetLanguage() << "\t" << endl;

    //cout << "operator[150]\t" << endl; // Проверка работает ли наше исключение bad_alloc

    students.Delete(3); // от 0

    Student student5;
    student5.SetLanguage("DELPHI");
    students.Insert(student5, 3); // Insert after C#

    Student student6;
    student6.SetLanguage("SQL");
    students.Replace(student6, 2); // Replace C# on SQL

    tmp = &students.GetHead();
    while (tmp != nullptr) // show all the students and them interests
    {
        cout << tmp->data.GetLanguage() << "\t";
        tmp = tmp->next;
    }
    cout << endl;

    //Sort(students);

    students.Clear();

    return 0;
}
