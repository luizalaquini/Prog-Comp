#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	map<string, string> m;
	string line;
	while ((getline(cin, line)) && line.length() > 0) {
		int space = line.find(' ');
		string a = line.substr(0, space);
		string b = line.substr(space + 1);
		m[b] = a;
	}
	while ((getline(cin, line)) && line.length() > 0) {
		if (m[line].length() == 0)
			cout << "eh\n";
		else
			cout << m[line] << endl;
	}
	return 0;
}