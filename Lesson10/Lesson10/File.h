#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <experimental\filesystem>
#include <filesystem>
using namespace std;

class File
{
public:
	static bool Append(string data, string name); // Дописать в конец файла
	static string GetFile(string path); // Получить весь файл
	static void Clear(string path); // Очистить файл
	static string GetPath(string name); // Получить текущий путь к файлу
};