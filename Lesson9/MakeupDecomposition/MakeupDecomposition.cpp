#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

// Декомпозиция auto
// Сверстка
// C++ 17

template <typename T, typename ... Ts>
void insert_all(vector<T>& vec, Ts ... ts)
{
    (vec.push_back(ts), ...);
}
int main()
{
    // Сверстка
    vector<int> v{ 1, 2, 3 };
    insert_all(v, 4, 5, 6);

    for (auto& data : v)
        cout << data << endl;

    // Декомпозиция
    map<int, int> m{
        {1, v[0]},
        {2, v[1]},
        {3, v[2]},
        {4, v[3]},
        {5, v[4]},
        {6, v[5]},
    };
    for (auto& [key, value] : m) // [key, value] = pair
        cout << "key:\t" << key << "\t" << "value:\t" << value << endl;
}
