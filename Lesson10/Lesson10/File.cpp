#include "File.h"

bool File::Append(string data, string path)
{
    if (!path.empty())
    {
        ofstream file(path, ios::app); // open file append
        file << data;
        file.close();
        return true;
    }
    else
    {
        cerr << "error file:\t" << path << endl;
        return false;
    }
}

string File::GetFile(string path)
{
    ifstream file;
    file.open(path);
    if (!file.is_open())
    {
        cerr << "error open to file:\t" << path << endl;
        return nullptr;
    }
    // options - read all the data from file - 3 разных способа чтения всего файла
    // 1)
    //string tmp(""), result("");
    //while (!file.eof())
    //{
    //    file >> tmp;
    //    result += tmp + "\n";
    //}
    // 2)
    //string result(istreambuf_iterator<char>{file}, istreambuf_iterator<char>{});
    //string result;
    //getline(file, result, '\0'); // read all the data from file
    // 3)
    string result(istreambuf_iterator<char>{file}, istreambuf_iterator<char>{});
    return result;
}

void File::Clear(string path)
{
    ofstream file;
    file.open(path, ofstream::out | ofstream::trunc);
    if (!file.is_open())
    {
        cerr << "error open to file:\t" << path << endl;
        return;
    }
    file.close();
}

string File::GetPath(string name) // Путь должен быть на Английском
{
    return experimental::filesystem::absolute(name).generic_string();
}