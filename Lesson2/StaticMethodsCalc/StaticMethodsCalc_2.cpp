#include <iostream>
#include "CalcMethods.h"
using namespace std;
int main()
{
	CalcMethods calc1;
	CalcMethods calc2;
	CalcMethods calc3;
	cout << calc1.ToString() << endl;

    string userX = "", userY = "", command = "";
	int x = 0, y = 0, next = 1;
	try
	{
		while (next) {
			cout << "enter x:" << endl;
			cin >> userX;
			cout << "enter y:" << endl;
			cin >> userY;
			cout << "enter separator: [+ -]" << endl;
			cin >> command;
			x = atoi(userX.c_str());
			y = atoi(userY.c_str());
			if (command._Equal("+"))
				cout << "result:\t" << CalcMethods::Plus(x, y) << endl;
			else if (command._Equal("-"))
				cout << "result:\t" << CalcMethods::Minus(x, y) << endl;
			else
				cout << "error: [separator]" << endl;
			cout << "exit? 1/0" << endl;
			cin >> next;
		}
	}
	catch (const exception&)
	{
		cout << "error: [x or y]" << endl;
	}
}
