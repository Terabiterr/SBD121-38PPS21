#include <iostream>
#include <string>
using namespace std;
// must have C++ 17
template<class ... Arg>
class PrintArguments {
public:
    void DisplayCMD(const Arg&... args) const {
        constexpr auto sizeArgs{ sizeof...(Arg) };
        cout << "Arguments size:\t" << sizeArgs << endl;
        (cout << ... << args); // Expression
    }
};
// C++ 11
//template<class ... Arg> class PrintArguments
//{
//public:
//    void DisplayCMD(const Arg &...args) const
//    {
//        constexpr auto sizeArgs{ sizeof...(Arg) };
//        cout << "Arguments size:\t" << sizeArgs << endl;
//        const void* dummy[] = { &(cout << args << endl)... };
//    }
//};
// C++ 14
//template<class ...Arg> class PrintArguments
//{
//public:
//    template <size_t ...I> void DisplayCMD(const Arg &...args, index_sequence<I...>) const
//    {
//        const size_t dummy[] = { (cout << args << endl, I)... };
//    }
//
//    void DisplayCMD(const Arg &...args) const
//    {
//        constexpr auto sizeArgs{ sizeof...(Arg) };
//        cout << "Arguments size:\t" << sizeArgs << endl;
//        DisplayCMD(args..., make_index_sequence<sizeArgs>{});
//    }
//};

int main()
{
    const char ch = 'H';
    PrintArguments<int, double, float, char> print;
    print.DisplayCMD(2, 2.5, 2.87f, ch);
}
