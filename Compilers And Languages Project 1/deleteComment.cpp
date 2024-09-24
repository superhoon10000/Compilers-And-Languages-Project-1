#include "Header.h"

//Function that deletes comments from a string that is passed to it
string deleteComment (const string& line)
{
	//variables initialized
	string cleaned = line;
	size_t cPlusPlusComment = cleaned.find("//");
	size_t pythonComment = cleaned.find("#");

	//Deletes everything after the comment in case there is any code written before the comment (works on C++ comments)
	if (cPlusPlusComment != string::npos)
	{
		cleaned = cleaned.substr(0, cPlusPlusComment);
	}

	//Deletes everything after the comment in case there is any code written before the comment (works on Python comments)
	if (pythonComment != string::npos)
	{
		cleaned = cleaned.substr(0, pythonComment);
	}

	//returns line with the comments removed
	return deleteWhitespace(cleaned);
}