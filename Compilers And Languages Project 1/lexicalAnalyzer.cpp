#include "lexicalAnalyzer.h"

void lexicalAnalyzer::initKeywords()
{
	keywords["def"] = tokenType::KEYWORD;
	keywords["return"] = tokenType::KEYWORD;
	keywords["if"] = tokenType::KEYWORD;
	keywords["print"] = tokenType::KEYWORD;
	keywords["int"] = tokenType::KEYWORD;
	keywords["calculate_sum"] = tokenType::KEYWORD;
	keywords["cout"] = tokenType::KEYWORD;
	keywords["endl"] = tokenType::KEYWORD;
}

bool lexicalAnalyzer::isWhitespace(char c)
{
	return false;
}

bool lexicalAnalyzer::isAlphabet(char c)
{
	return false;
}

bool lexicalAnalyzer::isDigit(char c)
{
	return false;
}

bool lexicalAnalyzer::isAlphaNumeric(char c)
{
	return false;
}

string lexicalAnalyzer::getNextWord()
{
	return string();
}

string lexicalAnalyzer::getNextNumber()
{
	return string();
}

vector<token> lexicalAnalyzer::tokenize()
{
	return vector<token>();
}
