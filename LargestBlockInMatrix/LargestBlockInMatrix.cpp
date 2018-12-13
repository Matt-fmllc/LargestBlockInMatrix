// LargestBlockInMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <unordered_map>
#include <string>


int min3(int a, int b, int c)
{
	int iMin = a;
	if (b < iMin) {
		iMin = b;
	}
	if (c < iMin) {
		iMin = c;
	}

	return iMin;
}


int DetermineLargestBlock(int** InputMatrice, int iKey, int iRows, int iColumns)
{
	int iLargestValue = 0;
	// create a copy of the array
	std::unordered_map< std::string, int > ResultsMap;

	printf("\nInput Array\n");
	for (int x = 0; x < iRows; x++) {
		for (int y = 0; y < iColumns; y++) {
			char buffer[64] = { 0 };
			sprintf_s( buffer,"%d,%d",x,y );
			std::string Vert = buffer;
			ResultsMap[Vert] = InputMatrice[x][y];
			//printf("%s ", buffer);
			printf("%d ", ResultsMap[Vert]);
		}
		printf("\n");
	}
	printf("\n");

	char buffer2[64];
	for (int x = 0; x < iRows; x++) {
		for (int y = 0; y < iColumns; y++) {

			// designate the vertice that is being examined
			sprintf_s(buffer2, "%d,%d", x, y);

			if (x != 0 && y != 0) {
				int iResult;
				if (InputMatrice[x][y] == iKey) {
					int i, j, k;
					char buffer[64];
					sprintf_s(buffer, "%d,%d", x, y-1);
					i = ResultsMap[buffer];
					sprintf_s(buffer, "%d,%d", x - 1, y - 1);
					j = ResultsMap[buffer];
					sprintf_s(buffer, "%d,%d", x - 1, y);
					k = ResultsMap[buffer];
					iResult = min3(i, j, k);

					ResultsMap[buffer2] = iResult + 1;
				}
				if (iLargestValue < ResultsMap[buffer2]) {
					iLargestValue = ResultsMap[buffer2];
				}
			}

		}

	}

	printf("Output Array\n");
	for (int x = 0; x < iRows; x++) {
		for (int y = 0; y < iColumns; y++) {
			char buffer[64] = { 0 };
			sprintf_s(buffer, "%d,%d", x, y);
			printf("%d ", ResultsMap[buffer]);
		}
		printf("\n");
	}

	return iLargestValue;
}

int main()
{

	// create a random array of values
	int InputArray[][6] = {	{ 1, 0, 0, 0, 0, 1 },
							{ 0, 0, 0, 0, 0, 0 },
							{ 0, 0, 0, 0, 1, 1 },
							{ 1, 1, 0, 0, 1, 0 },
							{ 0, 0, 1, 1, 0, 1 },
							{ 0, 1, 1, 1, 1, 1 }	};

	int* SourceArray[6] = { 0 };
	// fill surrogate array for annoying syntax
	for (int i = 0; i < 6; i++) {
		SourceArray[i] = InputArray[i];
	}

	
	// determine largest block for each of the elements
	int iResult = 0;
	printf("\nDetermine Largest block of \"%d\"", 1);
	iResult = DetermineLargestBlock(SourceArray, 1, 6, 6);
	printf("\nLargest block = %dx%d\n", iResult, iResult);
	printf("\nDetermine Largest block of \"%d\"", 0);
	iResult = DetermineLargestBlock(SourceArray, 0, 6, 6);
	printf("\nLargest block = %dx%d\n", iResult, iResult);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
