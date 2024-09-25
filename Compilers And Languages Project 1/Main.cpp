#include "lexicalAnalyzer.h"

int main()
{
	//initialized variables
	string iFileName;
	string oFileName;
	string line;
	string tokenizedOFileName;
	int tokenCount = 0;

	//asks for the file to input the code from
	cout << "Enter Code Set file name\n";
	getline(cin, iFileName);


	//asks for the file to output the processed code to
	cout << "Enter name for output file\n";
	getline(cin, oFileName);

	//initialized to the files asked for by the user
	ifstream codeSet(iFileName);
	fstream codeOutput(oFileName);

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
	codeOutput.close();

	codeOutput.open(oFileName);
	codeOutput.seekg(0);

	cout << "Enter Name of File to Output the final tokenized code to\n";
	getline(cin, tokenizedOFileName);



	while (getline(codeOutput, line))
	{
		lexicalAnalyzer tokenizer(line);
		vector<token> tokens = tokenizer.tokenize();
		outputTokens(tokens,tokenizedOFileName,tokenCount);
	}

	ofstream tokenizedFile(tokenizedOFileName, ios::app);

	tokenizedFile << "\n\nThere are a total of: " << tokenCount << " Tokens.";

	codeOutput.close();
	tokenizedFile.close();

	return 0;
}