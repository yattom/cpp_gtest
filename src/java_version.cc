#include <string>
#include "java_version.h"

using namespace std;

const string NUMBERS = "0123456789";

bool Version::isValid(string str) {
	if(str.substr(0, 3) != "JDK") {
		return false;
	}
	size_t u_pos = str.find("u", 3);
	if(u_pos == string::npos) {
		return false;
	}
	string updateNumber = str.substr(u_pos + 1);
	for(string::const_iterator i = updateNumber.begin(); i != updateNumber.end(); i++) {
		if(NUMBERS.find(*i) == string::npos) {
			return false;
		}
	}
	return true;
}
