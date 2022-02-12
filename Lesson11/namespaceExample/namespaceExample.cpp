#include <iostream>
#include <vector>

using namespace std;

namespace mystd {
    class Task {
    public:
        Task() { cout << typeid(this).name() << endl; }
        Task(initializer_list<int> l) : tasks(l) {}
        void Print()
        {
            for (auto& task : tasks)
                cout << task << "\t";
        }
    private:
        vector<int> tasks;
    };
}

int main()
{
    mystd::Task task = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    task.Print();
}
