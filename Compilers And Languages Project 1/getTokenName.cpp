#include "lexicalAnalyzer.h"


string getTokenName(tokenType type)
{
	switch (type)
	{
	case tokenType::KEYWORD:
		return "Keyword";
	case tokenType::IDENTIFIER:
		return "Identifier";
	case tokenType::OPERATOR:
		return "Operator";
	case tokenType::SEPARATOR:
		return "Separator";
	case tokenType::LITERAL:
		return "Literal";
	case tokenType::UNKNOWN:
		return "ERROR:UNKNOWN TYPE!!!";
	default:
		return "Defaulting";
	}
}