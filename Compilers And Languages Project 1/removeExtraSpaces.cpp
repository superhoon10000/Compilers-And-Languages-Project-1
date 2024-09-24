#include "Header.h"

string removeExtraSpaces(const string& line)
{
	stringstream stream(line);
	string word;
	string finalString;

	while (stream >> word)
	{
		if(!finalString.empty())
		{
			finalString += " ";
		}
		finalString += word;
	}
	return finalString;
}