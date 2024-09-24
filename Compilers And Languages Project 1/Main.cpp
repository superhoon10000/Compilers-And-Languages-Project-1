#include "Header.h"

int main()
{
	//initialized variables
	string iFileName;
	string oFileName;
	string line;

	//asks for the file to input the code from
	cout << "Enter Code Set file name\n";
	getline(cin, iFileName);


	//asks for the file to output the processed code to
	cout << "Enter name for output file\n";
	getline(cin, oFileName);

	//initialized to the files asked for by the user
	ifstream codeSet(iFileName);
	ofstream codeOutput(oFileName);

	//While loop that reads through the file line by line
	while (getline(codeSet, line)) {

		//deletes all comments and extra spaces from the function
		line = deleteComment(line);

		//if the line is not empty adds it to the final output file, removing all empty new lines between the code
		if (!line.empty())
		{
			codeOutput << line << endl;
		}
	}

	codeSet.close();


	return 0;
}