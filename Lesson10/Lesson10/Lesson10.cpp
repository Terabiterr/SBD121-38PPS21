/*
    help
    1. The path must be have in English
    2. Project -> properties -> General -> C++ Language Standart -> C++ 17
    3. Project -> properties -> C/C++ -> Preprocessor -> Preprocessor Definition -> add -> _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
*/
/*
    If error localtime
    Go to your VS context menu Project>Properties.
    Click Configuration>Properties>C/C++>Preprocessor.
    Edit Preprocessor Definitions and add _CRT_SECURE_NO_WARNINGS last empty line.
    This compile warning will be gone.
*/
#include <iostream>
#include "File.h"
#include <thread> // многопоточность
#include <string>
#include "Log.cpp"
#include <mutex> // потокобезопасность

using namespace std;

void WriteDegreeToFile(int numberDegree, string path)
{
    mutex door; // mutex 
    door.lock(); // Open the door
    File::Clear(path); // Clear all data in the file
    string data{ "" };
    for (size_t i = 2, number = 0; i < numberDegree; i *= 2, number++)
    {
        cout << path << endl;
        this_thread::sleep_for(2000ms); // остановить текущий поток на 2 секунды
        data = to_string(number) + "^2->" + to_string(i);
        File::Append(data + "\n", path);
        cout << "Wrote the data:\t" << data << endl;
    }
    Log::Append("Success", File::GetPath("Log.txt"));
    door.unlock(); // Close the door
}

int main()
{
    cout << "Threads count:\t" << thread::hardware_concurrency() << endl; // Узнать количество потоков

    thread th(WriteDegreeToFile, 2048, File::GetPath("degree2048.txt"));
    thread th1(WriteDegreeToFile, 1024, File::GetPath("degree1024.txt"));
    thread th2(WriteDegreeToFile, 4096, File::GetPath("degree4096.txt"));

    cout << "Started thread:\t" << th.get_id() << endl;
    cout << "Started thread:\t" << th1.get_id() << endl;
    cout << "Started thread:\t" << th2.get_id() << endl;

    for (size_t i = 0; i < 300000; i++)
    {
        Log::Append("Success", File::GetPath("Log.txt"));
    }

    th.join(); // Ожидание конца потока. (Последовально)
    th1.join();
    th2.join();
    return 0;
}
