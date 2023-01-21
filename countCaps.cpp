/*
 * programming assignment #10:
 * count caps
 *
 * counts number of capital letters either in a file or in user input,
 * then returns count
 *
 * jason bonner
 * cisc1600
 * 11-08-22
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

void newLine()
{
	char symbol;
	do
	{
		cin.get(symbol);
	} while (symbol != '\n');
}

void openFile(ifstream& inStream)
{
	string fileName;
	cout << "Enter the file name: ";
	cin >> fileName;
	newLine();
	inStream.open(fileName);
	if(inStream.fail())
	{
		cout << "Error! File not found. Exiting..." << endl;
		exit(1);
	}
}

int countCapitals(istream& inStream)
{
	int count(0);
	char next;

	do
	{	
		inStream.get(next);
		if(isupper(next))
			count++;	
	} while (next != '\n');


	return count;
}

int main()
{
	bool valid = false;
	int numCaps(0);
	ifstream inStream;

	do { //allows for repetition until a valid answer is input
		cout << "Are you using a file for input? (Y/N): ";
		char yn;
		cin >> yn;
		
		switch(yn)
		{
			case 'Y':
			case 'y':
				openFile(inStream);
				numCaps = countCapitals(inStream);	
				valid = true;
				break;			
			case 'N':
			case 'n':
				cout << "Enter your string. Press Enter/Return to end: ";
				newLine();
				numCaps = countCapitals(cin);
				valid = true;
				break;
			default:
				cout << "Invalid input - try again." << endl;
				break;
		}

	} while (valid == false);

	cout << "The number of capitals in your string is: " << numCaps << endl;

	return 0;
}
