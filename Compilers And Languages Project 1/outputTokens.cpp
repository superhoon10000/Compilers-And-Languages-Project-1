#include "lexicalAnalyzer.h"

void outputTokens(const vector<token>& tokens, const string& fileName)
{
	ofstream output(fileName, ios::app);


	int tokenCount = 0;
	for (const auto& token : tokens)
	{
		output << "Value: " << token.value << ", Type of token: " << getTokenName(token.type) << endl;
		tokenCount++;
	}

	output << "\n\nThere are a total of: " << tokenCount << " Tokens.\n\n";
}