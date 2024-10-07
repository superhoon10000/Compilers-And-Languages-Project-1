#include "lexicalAnalyzer.h"

void outputTokens(const vector<token>& tokens, const string& fileName, int& count)
{
	//opens the output file in append mode so that when tokens from the next lines are added they do not overwrite the previous lines
	ofstream output(fileName, ios::app);

	//outputs the token name and type with space in between so they look better formatted.
	for (const auto& token : tokens)
	{
		output << left << "Value: " << setw(40) << token.value << "Type of token: " << setw(40) << getTokenName(token.type) << endl;
		//increases the total token counter by 1.
		count++;
	}
}