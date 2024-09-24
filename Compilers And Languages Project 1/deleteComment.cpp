#include "Header.h"


string deleteComment (const string& line)
{
	string cleaned = line;
	size_t cPlusPlusComment = cleaned.find("//");
	size_t pythonComment = cleaned.find("#");

	if (cPlusPlusComment != string::npos)
	{
		cleaned = cleaned.substr(0, cPlusPlusComment);
	}

	if (pythonComment != string::npos)
	{
		cleaned = cleaned.substr(0, pythonComment);
	}

	return deleteWhitespace(cleaned);
}