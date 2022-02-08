#include <iostream>
#include <filesystem>
#include "Explorer.h"
using namespace std;
using namespace filesystem;

int main(int argc, char* argv[]) // Первый аргумент всегда содержит полный путь к текущему проекту root directory
{
    path dir{ argc > 1 ? argv[1] : "." };

    if (!exists(dir)) { // Если директории нет return 1;
        cout << "Path " << dir << " does not exist.\n";
        return 1;
    }

    Explorer explorer(dir);
    explorer.ShowDirectory();

    return 0;
}
