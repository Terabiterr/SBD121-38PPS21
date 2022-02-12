// expre_const_cast_Operator.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;

int main() {
	const char* str = "hello";
	//int i = static_cast<int>(str);//error C2440: 'static_cast' : cannot
								  // convert from 'const char *' to 'int'
	int j = (int)str; // C-style cast. Did the programmer really intend
					  // to do this?
	int k = reinterpret_cast<int>(str);// Programming intent is clear.
									   // However, it is not 64-bit safe.
}
