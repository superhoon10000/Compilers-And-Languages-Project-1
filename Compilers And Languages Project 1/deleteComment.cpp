#include "Header.h"

//Function that deletes comments from a string that is passed to it
string deleteComment (const string& line)
{
	//variables initialized
	string cleaned = line;
	size_t cPlusPlusComment = cleaned.find("//");
	size_t pythonComment = cleaned.find("#");
	size_t largeCommentStart = cleaned.find("/*");
	size_t largeCommentMiddle = cleaned.find("*");
	size_t largeCommentEnd = cleaned.find("*/");

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

	//Deletes everything after the comment in case there is any code written before the comment (works on large block comments)
	if (largeCommentStart != string::npos)
	{
		cleaned = cleaned.substr(0, largeCommentStart);
	}

	//Deletes everything after the comment in case there is any code written before the comment (works on large block comments)
	if (largeCommentMiddle != string::npos)
	{
		cleaned = cleaned.substr(0, largeCommentMiddle);
	}

	//Deletes everything after the comment in case there is any code written before the comment (works on large block comments)
	if (largeCommentEnd != string::npos)
	{
		cleaned = cleaned.substr(0, largeCommentEnd);
	}

	//returns line with the comments removed
	return removeExtraSpaces(cleaned);
}