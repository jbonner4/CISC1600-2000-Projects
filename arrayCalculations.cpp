/*
 * programming assignment #11:
 * arrray calculations
 *
 * prompts user to enter values for an array, then performs and prints out calculations on those values
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

const int NUM_VALUES = 50;

void newLine() //function to create a new line, "eating" empty chars
{
	char symbol;
	do
	{
		cin.get(symbol);
	} while (symbol != '\n');
}

void arrayInput(int arr[], int& length) //prompts user to input values for an array, storing the number of filled values in 'length'
{
	cout << "Please enter up to " << NUM_VALUES << " non-negative whole numbers separated by space." << endl << "Mark the end of the input list with a negative number:" << endl;
	int next, index(0);

	cin >> next;
	while (next >= 0 && index < NUM_VALUES)
	{
		arr[index] = next;
		index++;
		cin >> next;
	}

	length = index;

	//cout << "length is: " << length << endl; TEST FRAGMENT
}

void display(int arr[], int length) //shows all filled values in array up to length
{
	for(int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	
	newLine();
}

void inArray(int arr[], int length) //prints out a statement confirming whether a target value is in ana array or not
{
	int target;
	cout << "Please enter the value you want to search in the array: ";
	cin >> target;

	bool isInArray = false;
	int next;

	for(int i = 0; i < length; i++)
	{
		next = arr[i];
		//cout << "index " << i << " = " << arr[i] << endl; TEST FRAGMENT
		if(next == target)
		{
			isInArray = true;
			break;
		}
	}

	if(isInArray == true)
	{
		cout << "Find your target " << target << endl;
	}
	else
	{
		cout << "Could not find " << target << endl;
	}
}

void numInArray(int arr[], int length) //prints out the number of times a target value is found in an array
{
	
	int target;
	cout << "Please enter the value you want to know the frequency of: ";
	cin >> target;
	
	int num(0);
	for(int i = 0; i < length; i++)
	{
		if(arr[i] == target)
			num++;	
	}
	cout << "The number " << target << " has occurred " << num << " time(s) in the array" << endl;
}

int minimum(int arr[], int length) //finds the minimum of all values in an array
{
	int min(arr[0]);

	for(int i = 0; i < length; i++)
	{
		if(arr[i] < min)
			min = arr[i];
	}
	return min;
}

int maximum(int arr [], int length) //finds the maximum of all values in an array
{
	int max(arr[0]);
	
	for(int i = 0; i < length; i++)
	{
		if(arr[i] > max)
			max = arr[i];
	}	
	return max;
}

int sum(int arr[], int length) //returns the sum of all values in an array
{
	int total(0);

	for(int i = 0; i < length; i++)
	{
		total += arr[i];	
	}
	return total;
}

double average(int arr[], int length) //returns the average of all values in an array
{
	double total(0.0);
	
	for(int i = 0; i < length; i++)
	{
		total += arr[i];
	}
	return (total / length);
}

int main()
{
	cout.setf(ios::fixed); // setting decimal precision
	cout.setf(ios::showpoint);
	cout.precision(2);

	int arr[NUM_VALUES], length(0);

	arrayInput(arr, length);
	display(arr, length);

	cout << "\nThe minimum value in the array is " << minimum(arr, length) << "\nThe maximum value in the array is " << maximum(arr,length)
	<< "\nThe sum of all the elements in the array is " << sum(arr, length) << "\nThe average of all the elements in the array is "<< average(arr, length) << endl;

	inArray(arr, length);
	numInArray(arr, length);

	return 0;
}


