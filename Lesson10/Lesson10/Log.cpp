#include <string>
#include <time.h> //<ctime>
#include "File.h"
#include <sstream>
using namespace std;
class Log {
public:
	static void Append(string event, string path)
	{
		time_t now = time(nullptr);
		tm timeNow = *localtime(&now);
		stringstream ss;
		ss
			<< "time:\t" << put_time(&timeNow, "%m:%d:%Y %T") << "\n"
			<< "event:\t" << event << "\n";
		File::Append(ss.str(), path);
	}
};