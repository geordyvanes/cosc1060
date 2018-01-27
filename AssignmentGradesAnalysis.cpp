//*******************************************************************************************************
//
//		File:				AssignmentGradesAnalysis.cpp
//
//		Student:			Geordy van Es
//
//		Assignment:			Program #2
//
//		Course Name:		Programming II
//
//		Course Number:		COSC 1560-02
//
//		Due:				February 5, 2018
//
//
//		This program calculates the final grade based on 13 assignments.
//	
//		Other files required: 
//			1.	None
//			
//*******************************************************************************************************

#include <iostream>
#include <iomanip>
using namespace std;

//*******************************************************************************************************

void getData(int *, const int);
void displayData(int *, const int);
double calcAverage(int *, const int);
int findHighest(int *, const int);

//*******************************************************************************************************

int main()
{
	const int SIZE = 13;

	int grades[SIZE];

	int * ptData = grades;

	getData(ptData, SIZE);

	displayData(ptData, SIZE);

	cout << fixed << setprecision(2);
	cout << "The average is: " << calcAverage(ptData, SIZE) << endl
		<< "The highest grades is: " << findHighest(ptData, SIZE) << endl;
			
	return 0;
}

//*******************************************************************************************************

void getData(int * data, const int SIZE)
{
	cout << "Please enter grades for the 13 assignments." << endl;

	for (int i = 0; i < SIZE; i++)
	{
		do
		{
			cout << "Grade " << i + 1 << ": ";
			cin >> *(data + i);

			if (*(data + i) < 0 || *(data + i) > 100)
				cout << "ERROR: Grades cannot be less than 0 or more than 100" << endl;
		} while (*(data + i) < 0 || *(data + i) > 100);
	}

	cout << endl;
}

//*******************************************************************************************************

void displayData(int * data, const int SIZE)
{
	cout << "All grades entered:" << endl;

	for (int i = 0; i < SIZE; i++)
	{
		cout << left << setw(5) << *(data + i);
	}
	
	cout << endl << endl;
}

//*******************************************************************************************************

int findHighest(int * data, const int SIZE)
{
	int highest = 0;

	for (int i = 0; i < SIZE; i++)
	{
		if (*(data + i) > highest)
			highest = *(data + i);
	}

	return highest;
}

//*******************************************************************************************************

double calcAverage(int * data, const int SIZE)
{
	double average = 0.0;

	for (int i = 0; i < SIZE; i++)
	{
		average += *(data + i);
	}

	average /= static_cast<double>(SIZE);

	return average;
}

//*******************************************************************************************************
/*
Please enter grades for the 13 assignments.
Grade 1: 95
Grade 2: -95
ERROR: Grades cannot be less than 0 or more than 100
Grade 2: 92
Grade 3: 103
ERROR: Grades cannot be less than 0 or more than 100
Grade 3: 100
Grade 4: 50
Grade 5: 75
Grade 6: 67
Grade 7: 89
Grade 8: 0
Grade 9: 100
Grade 10: 25
Grade 11: 99
Grade 12: 100
Grade 13: 100

All grades entered:
95   92   100  50   75   67   89   0    100  25   99   100  100

The average is: 76.31
The highest grades is: 100
Press any key to continue . . .
*/