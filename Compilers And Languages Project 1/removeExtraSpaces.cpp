#include "Header.h"

//Function that sets a single space between every word from a string that is passed to it, effectively removing double or extra spaces from the string
string removeExtraSpaces(const string& line)
{
	//variables initialized
	stringstream stream(line);
	string word;
	string finalString;

	//A while loop that reads the original string one word at a time, stopping when the string is finished
	while (stream >> word)
	{
		//if the string isn't empty adds a space, adding a space between every word during the loop but not creating an extra space before the first word.
		if(!finalString.empty())
		{
			finalString += " ";
		}
		//Adds the current word to the final string that is output
		finalString += word;
	}
	//returns the final string that only has a single space between each word
	return finalString;
}