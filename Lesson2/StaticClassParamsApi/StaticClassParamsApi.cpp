#include <iostream>
#include <string>
using namespace std;

static class ParamsApi {
public:
    string GetParams() {
        return "{ name : 'Bob', secondName : 'Rero' }";
    }
} params;

int main()
{
    cout << params.GetParams() << endl;
}
