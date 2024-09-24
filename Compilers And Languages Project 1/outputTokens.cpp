#include "lexicalAnalyzer.h"

void outputTokens(const vector<token>& tokens, ofstream& output)
{
	int tokenCount = 0;
	for (const auto& token : tokens)
	{
		output << "Value: " << token.value << ", Type of token: " << getTokenName(token.type) << endl;
	}
}