/*

#include "Header.h"

//Function that deletes whitespaces from a string that is passed to it
string deleteWhitespace(const string& line)
{
	//sets beginning variable to the index of the first non-whitespace character found
	size_t beginning = line.find_first_not_of(" \t");

	//If there are only whitespace characters returns an empty string
	if (beginning == string::npos)
		return"";

	//sets ending variable to index of last non-whitespace character found
	size_t ending = line.find_last_not_of(" \t");

	//returns the substring starting with beginning ending with ending variable leading to any extra whitespaces being removed
	return line.substr(beginning, ending - beginning + 1); 
}

**************************************Function is no longer used and kept for archival purposes****************************************
*/