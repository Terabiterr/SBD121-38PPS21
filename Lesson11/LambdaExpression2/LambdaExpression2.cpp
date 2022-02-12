#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main(void)
{
    vector<int> v = { 1, 2, 3, 4, 5 };
    for_each(v.begin(), v.end(), [](int element) {cout << element; });
    return 0;
}
