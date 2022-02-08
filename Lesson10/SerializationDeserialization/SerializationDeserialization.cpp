/*
    help
    1. The path must be have in English
    2. Project -> properties -> General -> C++ Language Standart -> C++ 17
    3. Project -> properties -> C/C++ -> Preprocessor -> Preprocessor Definition -> add -> 
    _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
*/
/*
    If error localtime
    Go to your VS context menu Project>Properties.
    Click Configuration>Properties>C/C++>Preprocessor.
    Edit Preprocessor Definitions and add _CRT_SECURE_NO_WARNINGS last empty line.
    This compile warning will be gone.
*/
#include <iostream>
#include <fstream>
#include <filesystem> // C++ 17
#include <experimental\filesystem> // C++ 17
using namespace std;

// Тривиальный объект
class Student {
public:
    int _id { 0 };
    char _firstName[255];
    char _lastName[255];

    // Если заменить char name[255] на const char * то это будет работать только пока Вы не закроете VS т.к.
    // const char * - это 8 байт (Указатель на константный char) Нужно обязательно знать точный размер объекта
};

int main()
{
    const int size = 3;
    Student studentsToFile[size] = {
        { 1, "Bob", "Bobexes" },
        { 2, "Alex", "Michael" },
        { 3, "Arnold", "Alerto" }
    };

    for (auto& student : studentsToFile) // Вывод students
        cout << student._firstName << endl;

    // write
    ofstream fwrite("students.txt", ios_base::binary); // Запишет в текущий проект
    fwrite.write(reinterpret_cast<char*>(&studentsToFile), sizeof(studentsToFile));
    fwrite.close();

    Student studentsFromFile[size] = { {}, {}, {} }; // Создание нового массива студентов
    //read
    string path = experimental::filesystem::absolute("students.txt").generic_string(); // Получить абсолютный путь
    ifstream fread(path, ios_base::binary);
    if (!fread) { std::cerr << "File not found"; return 1; }
    fread.read(reinterpret_cast<char*>(&studentsFromFile), sizeof(studentsFromFile));
    fread.close();

    for (auto& student : studentsFromFile) // Вывод полученного массива объектов из файла
        cout << student._firstName << endl;

    return 0;
}
