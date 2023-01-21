/* Jason Bonner
 * CISC2000 - Computer Science II
 *
 * inflation rate
 *
 * uses a function to calculate inflation rate given an old and new
 * cpi (consumer price index) including a loop to continue asking
 * user for inflation rate and an average across the iterations of
 * that loop
 *
 * last edited: 1-18-23
 */
#include <iostream>
using namespace std;

/*
 * calcInflationRate - calculates the inflation rate given the old and new consumer price index (both must be greater than 0)
 * @param old_cpi: is the consumer price index that it was a year ago
 * @param new_cpi: is the consumer price index that it is currently 
 * @returns the computed inflation rate or 0 if inputs are invalid.
 */
double calcInflationRate(double old_cpi, double new_cpi);

int main()   //C++ programs start by executing the function main
{
   // TODO #1: declare two float variables for the old consumer price index (cpi) and the new cpi
	float oldCPI, newCPI, avgInflation, numRepeats(0);
	bool isComplete = false;
	char yn;

	do
	{
   	// TODO #2: Read in two float values for the cpi and store them in the variables
		cout << "Enter the old and new consumer price indices: ";
		cin >> oldCPI >> newCPI;

   	// TODO #3: call the function calcInflationRate with the two cpis
		float inflation = calcInflationRate(oldCPI, newCPI);

   	// TODO #4: print the results
		cout << "Inﬂation rate is " << inflation << endl;
	
   	// NEW CODE
	
		if(inflation != 0)
		{
			avgInflation += inflation;
			numRepeats++;
		}

		cout << "Try again? (y or Y): ";
		cin >> yn;

		if(yn == 'n' || yn == 'N')
			isComplete = true;

	} while(isComplete == false);

	avgInflation /= numRepeats;
	cout << "Average rate is " << avgInflation << endl;

   return 0;
}


// double calcInflationRate(float old_cpi, float new_cpi)
// precondition:   both prices must be greater than 0.0
// postcondition:  the inflation rate is returned or 0 for invalid inputs
double calcInflationRate(double old_cpi, double new_cpi)
{
   // TODO: Implement InflationRate to calculate the percentage increase or decrease
   // Use (new_cpi - old_cpi) / old_cpi * 100
	if(new_cpi <= 0 || old_cpi <= 0)
		return 0;
	else
		return (new_cpi - old_cpi) / old_cpi * 100;
}
