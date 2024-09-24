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
	return c == ' ' || c == '\n' || c == '\t';
}

bool lexicalAnalyzer::isAlphabet(char c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool lexicalAnalyzer::isNum(char c)
{
	return c >= '0' && c <= '9';
}

bool lexicalAnalyzer::isAlphaNumeric(char c)
{
	return isAlphabet(c) || isNum(c);
}

bool lexicalAnalyzer::isSeparator(char c)
{
	return c == '(' || c == ',' || c == ')' || c == ':' || c == '{' || c == ';' || c == '}';
}

bool lexicalAnalyzer::isOperator(char c)
{
	return c == '=' || c == '+' || c == '=';
}

bool lexicalAnalyzer::isStringLiteral(char c)
{
	return c == '"';
}

string lexicalAnalyzer::nextWord()
{
	size_t begin = location;
	while(location < input.length() && isAlphaNumeric(input[location]))
	{
		location++;
	}
	return input.substr(begin, location - begin);
}

string lexicalAnalyzer::nextNumber()
{
	return string();
}

vector<token> lexicalAnalyzer::tokenize()
{
	vector<token> tokens;

	while(location < input.length())
	{
		char current = input[location];

		if (isWhitespace(current))
		{
			location++;
			continue;
		}

		if (isStringLiteral(current))
		{
			string word = nextWord();
			tokens.emplace_back(tokenType::LITERAL, word);
		}
		else if (isAlphabet(current))
		{
			string word = nextWord();
			if (keywords.find(word) != keywords.end())
			{
				tokens.emplace_back(tokenType::KEYWORD, word);
			}
			else
			{
				tokens.emplace_back(tokenType::IDENTIFIER, word);
			}
		}
		else if(isNum(current))
		{
			string number = nextWord();
			tokens.emplace_back(tokenType::LITERAL, number);
		}
		else if(isOperator(current))
		{
			tokens.emplace_back(tokenType::OPERATOR, string(1, current));
			location++;
		}
		else if(isSeparator(current))
		{
			tokens.emplace_back(tokenType::SEPARATOR, string(1, current));
			location++;
		}
		else
		{
			tokens.emplace_back(tokenType::UNKNOWN, string(1, current));
			location++;
		}
	}
	return tokens;
}
