/* 
 * final exam
 * 
 * populates an array with numbers, then allows user to perform functions on those numbers
 *
 * jason bonner
 * 12-15-2022
 */
 
#include <iostream>
#include <cstdlib>  
using namespace std;
 
const int MAX_SIZE = 20;
 
void fillArray(int arr[], int& length)
{
	int val;
	bool rightSize = false;
	do{
		cout << "Enter a positive number no larger than 20: ";
		cin >> val;
		if((val <= 20) && (val >= 1))
		{
			rightSize = true;
			break;
		}
		else
			rightSize = false;
	} while(rightSize == false);

	length = val;

	for(int i = 0; i < val; i++)
	{	
		arr[i] = ((rand() % 100) + 1);
	}
}

void displayArray(int arr[], int length)
{
	for(int i = 0; i < length; i++)
	{
		cout << arr[i] << endl;
	}
}

bool replaceNum(int arr[], int length, int old, int sub)
{
	bool replaceTrue = false;

	for(int i = 0; i < length; i++)
	{
		if(arr[i] == old)
		{
			arr[i] = sub;
			replaceTrue = true;
			break;
		}
	}
	return replaceTrue;
}
 
int main()
{
    srand(20);
    int arr[MAX_SIZE], length(0), search, replacement;
    bool quit = false;
    char option;
    fillArray(arr, length);
	
    do
    {
	cout << "(D)isplay, (R)eplace, Re(F)ill, or (Q)uit? ";
	cin >> option;
	switch(option)
	{
		case 'd':
		case 'D':
			displayArray(arr, length);
			break;
		case 'r':
		case 'R':
			cout << "Enter a number to search for: ";
			cin >> search;
			cout << "Enter replacement: ";
			cin >> replacement;
			if(replaceNum(arr, length, search, replacement))
				cout << "Replacement successful." << endl;
			else
				cout << "Replacement unsuccessful." << endl;
			break;
		case 'f':
		case 'F':
			fillArray(arr, length);
			break;
		case 'q':
		case 'Q':
			cout << "Good bye!" << endl;
			quit = true;
			break;
		default:
			cout << "Invalid answer - input again!" << endl;
	}
    } while(quit == false);

    return 0;
}
 
