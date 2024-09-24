#include "lexicalAnalyzer.h"

void outputTokens(const vector<token>& tokens, const string& fileName, int& count)
{
	ofstream output(fileName, ios::app);


	for (const auto& token : tokens)
	{
		output << "Value: " << token.value << ", Type of token: " << getTokenName(token.type) << endl;
		count++;
	}
}