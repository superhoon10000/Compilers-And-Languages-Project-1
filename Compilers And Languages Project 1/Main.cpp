#include "Header.h"
using namespace std;
int main()
{
	string iFileName;
	string oFileName;
	string line;

	cout << "Enter Code Set file name\n";
	getline(cin, iFileName);

	cout << "Enter name for output file\n";
	getline(cin, oFileName);

	ifstream codeSet(iFileName);
	ofstream codeOutput(oFileName);

	while (getline(codeSet, line)) {
		codeOutput << line << endl;
	}

	codeSet.close();


	return 0;
}