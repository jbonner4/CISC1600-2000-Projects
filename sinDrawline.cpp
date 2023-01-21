/*
 * programming assignment #7:
 * sin with drawline
 *
 * prints the sin of every angle that is a multiple of 10º between
 * 0º and 720º and prints a line of 30 dashes after every angle that
 * is a multiple of 90º using two specialized functions to simplify
 * main code block
 *
 * jason bonner
 * cisc1600
 * 10-25-22
 */

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

	const double PI = 3.14159265358979323846;
	const double conversionFactor = PI/180; //declared as two separate (global) vars, but could just be one; done for sake of clarity

	double degrees2Radians(double degrees) //takes in degrees, converts to radians 
	{	
		double radians = degrees * conversionFactor;
		return radians;
	}	

	void drawline(char c, int numRepititions) //prints a line of a given character a given number of times
	{
		for(int i = 1; i <= numRepititions; i++)
		{
			cout << c;
		}
		
		cout << endl;
	}

	int main()
	{	
		cout.setf(ios::fixed); // setting decimal precision
		cout.setf(ios::showpoint);
		cout.precision(5);

		double radians; //can be done because previous radians variable is local to degrees2Radians

		for(int degrees = 0; degrees <= 720; degrees++)
		{
			if((degrees % 10) == 0)
			{
				radians = degrees2Radians(degrees);
				cout << "sin(" << degrees << ") = " <<  sin(radians) << endl;
			}
			
			if((degrees% 90) == 0)
			{
				drawline('-', 30);	
			}
		}

		return 0;
	}	

//everything is indented one line over by accident, would fix if part of a larger program.
