#include "Header.h"

string deleteWhitespace(const string& line)
{
	size_t beginning = line.find_first_not_of(" \t");

	if (beginning == string::npos)
		return"";
	size_t ending = line.find_last_not_of(" \t");

	return line.substr(beginning, ending - beginning + 1);
}