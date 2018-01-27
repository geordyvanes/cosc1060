//*******************************************************************************************************
//
//		File:				TwoDArray.cpp
//
//		Student:			Geordy van Es
//
//		Assignment:			Program #1
//
//		Course Name:		Programming II
//
//		Course Number:		COSC 1560 02
//
//		Due:				January 27 2018
//
//
//		This program collects and analyzes data from special types of bacteria. The program outputs the
//		averages, highest and lowest value, and the sum of a row.
//	
//		Other files required: 
//			1.	None
//			
//*******************************************************************************************************

#include <iostream>
#include <iomanip>
using namespace std;

//*******************************************************************************************************

const int COL_SIZE = 4;

//*******************************************************************************************************

void getData(int data[][COL_SIZE], const int ROW);
void displayData(const int data[][COL_SIZE], const int ROW);
double getAverage(const int data[][COL_SIZE], const int ROW_SIZE);
int getAllHighest(const int data[][COL_SIZE], const int ROW_SIZE);
int getRowSum(const int data[][COL_SIZE], const int ROW_REQUESTED);
int getColLowest(const int data[][COL_SIZE], const int ROW_SIZE, const int COL_REQUESTED);

//*******************************************************************************************************

int main()
{
	const int ROW_SIZE = 4;

	int data[ROW_SIZE][COL_SIZE];

	int rowRequested,
		colRequested;

	getData(data, ROW_SIZE);

	displayData(data, ROW_SIZE);

	cout << fixed << setprecision(2);

	cout << "The average is: " << getAverage(data, ROW_SIZE) << endl << endl;

	cout << "The highest value is: " << getAllHighest(data, ROW_SIZE) << endl << endl;

	cout << "Please enter a row number to calculate the sum: ";
	cin >> rowRequested;

	cout << "The sum of row " << rowRequested << " is: " << getRowSum(data, rowRequested) << endl << endl;

	cout << "Please enter a collumn number to find the lowest value: ";
	cin >> colRequested;

	cout << "The lowest value in collumn " << colRequested << " is: " << getColLowest(data, ROW_SIZE, colRequested) << endl;

	return 0;
}

//*******************************************************************************************************

void getData(int data[][COL_SIZE], const int ROW)
{
	cout << "Please enter all values:" << endl;

	for (int r = 0; r < ROW; r++)
	{
		cout << "Enter values for Row " << r + 1 << ": ";
		
		for (int c = 0; c < COL_SIZE; c++)
		{
			do
			{
				cin >> data[r][c];

				if (data[r][c] < 0 || data[r][c] > 500)
				{
					cout << "Invalid value! Please enter a value between 0-500." << endl
						 << "Enter values for Row " << r + 1 << ": ";

					for (int i = 0; i < c; i++)
						cout << data[r][i] << " ";
				}
			} 
			while (data[r][c] < 0 || data[r][c] > 500);
		}
	}

	cout << "----------------------------------------" << endl;
}

//*******************************************************************************************************

void displayData(const int data[][COL_SIZE], const int ROW)
{
	cout << "You have entered:" << endl;

	for (int r = 0; r < ROW; r++)
	{
		for (int c = 0; c < COL_SIZE; c++)
		{
			cout << left << setw(5) << data[r][c] << " ";
		}

		cout << endl;
	}

	cout << "----------------------------------------" << endl;
}

//*******************************************************************************************************

double getAverage(const int data[][COL_SIZE], const int ROW_SIZE)
{
	double average = 0;

	int totalNum = ROW_SIZE * COL_SIZE;

	for (int r = 0; r < ROW_SIZE; r++)
	{
		for (int c = 0; c < COL_SIZE; c++)
		{
			average += data[r][c];
		}
	}

	average /= totalNum;

	return average;
}

//*******************************************************************************************************

int getAllHighest(const int data[][COL_SIZE], const int ROW_SIZE)
{
	int highest = 0;

	for (int r = 0; r < ROW_SIZE; r++)
	{
		for (int c = 0; c < COL_SIZE; c++)
		{
			if (data[r][c] > highest)
				highest = data[r][c];
		}
	}

	return highest;
}

//*******************************************************************************************************

int getRowSum(const int data[][COL_SIZE], const int ROW_REQUESTED)
{
	int sum = data[ROW_REQUESTED-1][0];

	for (int c = 1; c < COL_SIZE; c++)
	{
		sum += data[ROW_REQUESTED-1][c];
	}

	return sum;
}

//*******************************************************************************************************

int getColLowest(const int data[][COL_SIZE], const int ROW_SIZE, const int COL_REQUESTED)
{
	int lowest = data[0][COL_REQUESTED-1];

	for (int r = 1; r < ROW_SIZE; r++)
	{
		if (data[r][COL_REQUESTED-1] < lowest)
			lowest = data[r][COL_REQUESTED-1];
	}

	return lowest;
}

//*******************************************************************************************************
/*
Please enter all values:
Enter values for Row 1: 105 156 142 143
Enter values for Row 2: 201 213 212 244
Enter values for Row 3: 98 82 92 97
Enter values for Row 4: 10 13 15 19
----------------------------------------
You have entered:
105   156   142   143
201   213   212   244
98    82    92    97
10    13    15    19
----------------------------------------
The average is: 115.13

The highest value is: 244

Please enter a row number to calculate the sum: 2
The sum of row 2 is: 870

Please enter a collumn number to find the lowest value: 3
The lowest value in collumn 3 is: 15
Press any key to continue . . .
*/