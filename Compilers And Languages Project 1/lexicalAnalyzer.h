#pragma once
#include "Header.h"

enum class tokenType
{
	KEYWORD,
	IDENTIFIER,
	LITERAL,
	OPERATOR,
	SEPARATOR,
	UNKNOWN
};

struct token
{
	tokenType type;
	string value;

	token(tokenType a, const string& b) :type(a), value(b) {}
};

class lexicalAnalyzer
{
private:
	string input;
	size_t location;
	unordered_map<string, tokenType> keywords;

	void initKeywords();
	bool isWhitespace(char c);
	bool isAlphabet(char c);
	bool isNum(char c);
	bool isAlphaNumeric(char c);
	bool isSeparator(char c);
	bool isOperator(char c);
	bool isStringLiteral(char c);
	string nextWord();
	string nextNumber();

public:
	lexicalAnalyzer(const string& source):input(source),location(0)
	{
		initKeywords();
	}

	vector<token> tokenize();


};

string getTokenName(tokenType type);
void outputTokens(const vector<token>& tokens, const string& fileName, int& count);


/*Uses inspiration from the lexical Analysis created by Geeksforgeeks
https://www.geeksforgeeks.org/lexical-analyzer-in-cpp/
had trouble figuring this out without some help
*/