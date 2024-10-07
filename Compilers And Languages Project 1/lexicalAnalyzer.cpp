#include "lexicalAnalyzer.h"

//initialized what words are seen as keywords by the lexical analyzer
void lexicalAnalyzer::initKeywords()
{
	keywords["def"] = tokenType::KEYWORD;
	keywords["return"] = tokenType::KEYWORD;
	keywords["if"] = tokenType::KEYWORD;
	keywords["print"] = tokenType::KEYWORD;
	keywords["int"] = tokenType::KEYWORD;
	keywords["calculate_sum"] = tokenType::KEYWORD;
	keywords["void"] = tokenType::KEYWORD;
	keywords["else"] = tokenType::KEYWORD;
}

//uses a bool to return a true or false value on if a character is seen as a whitespace character
bool lexicalAnalyzer::isWhitespace(char c)
{
	return c == ' ' || c == '\n' || c == '\t';
}

//uses a bool to return a true or false value on if a character is seen as an alphabet character
bool lexicalAnalyzer::isAlphabet(char c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

//uses a bool to return a true or false value on if a character is seen as a number
bool lexicalAnalyzer::isNum(char c)
{
	return c >= '0' && c <= '9';
}

//uses a bool to return a true or false value on if a character is seen as an alphanumeric character
bool lexicalAnalyzer::isAlphaNumeric(char c)
{
	return isAlphabet(c) || isNum(c);
}

//uses a bool to return a true or false value on if a character is seen as a separator character
bool lexicalAnalyzer::isSeparator(char c)
{
	return c == '(' || c == ',' || c == ')' || c == ':' || c == '{' || c == ';' || c == '}';
}

//uses a bool to return a true or false value on if a character is seen as an operator character
bool lexicalAnalyzer::isOperator(char c)
{
	return c == '=' || c == '+' || c == '<' || c == '>';
}

//uses a bool to return a true or false value on if a character is seen as a string literal
bool lexicalAnalyzer::isStringLiteral(char c)
{
	return c == '"';
}

//Outputs a string that consists of the next full word such as int or num
string lexicalAnalyzer::nextWord()
{
	//a variable that stores the beginning location of the word
	size_t begin = location;

	//a loop that goes write the word letter by letter until it reaches a non alphanumeric/_ character or if it reaches the end of the input.
	while(location < input.length() && (isAlphaNumeric(input[location]) || input[location] == '_'))
	{
		location++;
	}
	//returns the string starting from the first letter of the word to the last letter of the word
	return input.substr(begin, location - begin);
}

//Outputs a string that consists of the entire string literal including the " from the starting " to the ending "
string lexicalAnalyzer::nextString()
{
	//a variable that stores the beginning location of the string
	size_t begin = location;

	//if it is not the end of the line, and it encounters a " it will go into this if statement
 	if (location < input.length() && isStringLiteral(input[location]))
	{
		//moves past the "
		location++;
		//loop that loops until it hits the ending "
		while (location < input.length() && !isStringLiteral(input[location]))
		{
			location++;
		}

		//unless the end of the line is reached it will move 1 more to the add the ending " to the output
		if (location < input.length() && isStringLiteral(input[location]))
		{
			location++;
		}

		//returns the full string literal including the "
		return input.substr(begin, location - begin);
	}
}

//outputs a vector with the tokenized outputs
vector<token> lexicalAnalyzer::tokenize()
{
	//initializes the vector that stores the tokens
	vector<token> tokens;

	//a loop that goes through the line until it reaches its end
	while(location < input.length())
	{
		//a variable that holds the char of the current location such as 'i' in int or '=' where there is a =
		char current = input[location];

		// checks if it is whitespace and if so skips it.
		if (isWhitespace(current))
		{
			location++;
			continue;
		}

		//checks if it is a string literal and if so it gets the full string and adds it to the back of the vector as a literal type
		if (isStringLiteral(current))
		{
			string word = nextString();
			tokens.emplace_back(tokenType::LITERAL, word);
		}
		//checks if it is an alphabetical char or _ and if so it gets the next word
		else if (isAlphabet(current) || current == '_')
		{
			string word = nextWord();
			//if it is a keyword adds it to the back of the vector as type keyword
			if (keywords.find(word) != keywords.end())
			{
				tokens.emplace_back(tokenType::KEYWORD, word);
			}
			//if it is an identifier adds it to the back of the vector as type identifier
			else
			{
				tokens.emplace_back(tokenType::IDENTIFIER, word);
			}
		}
		//checks if it's a number by itself and if so put it in the back of the vector as type literal
		else if(isNum(current))
		{
			string number = nextWord();
			tokens.emplace_back(tokenType::LITERAL, number);
		}
		//checks if it is an operator
		else if(isOperator(current))
		{
			//gets the next char and checks if it is a compound operator 
			char nextChar = input[location + 1];
			//if it is a compound operator it outputs both to the vector as one compound operator
			if((current == '=' && nextChar == '=') || (current == '<' && nextChar == '<'))
			{
				tokens.emplace_back(tokenType::OPERATOR, string(1, current) + string(1, nextChar));
				location+= 2;
			}
			//if not it just outputs the operator to the vector
			else
			{
				tokens.emplace_back(tokenType::OPERATOR, string(1, current));
				location++;
			}
		}
		//checks if it is a separator adds it to the back of the vector as type separator
		else if(isSeparator(current))
		{
			tokens.emplace_back(tokenType::SEPARATOR, string(1, current));
			location++;
		}
		//if all else fails outputs an unknown type for testing errors
		else
		{
			tokens.emplace_back(tokenType::UNKNOWN, string(1, current));
			location++;
		}
	}
	//returns the tokens vector which holds all the values
	return tokens;
}
