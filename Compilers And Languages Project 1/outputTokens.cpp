#include "lexicalAnalyzer.h"

void outputTokens(const vector<token>& tokens, const string& fileName, int& count)
{
	ofstream output(fileName, ios::app);


	for (const auto& token : tokens)
	{
		output << left << "Value: " << setw(25) << token.value << "Type of token: " << setw(25) << getTokenName(token.type) << endl;
		count++;
	}
}