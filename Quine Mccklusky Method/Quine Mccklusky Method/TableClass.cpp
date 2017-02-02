 //******************************** PROGRAM IDENTIFICATION *************************************
//*                                                                                             *
//*     PROGRAM FILE NAME: Driver     ASSIGNMENT #: 1                   Grade:   ____________   *
//*                                                                                             *
//*     PROGRAM AUTHOR:     ______________________________________                              *
//*                                     ERIC BUTTON                                             *
//*                                                                                             *
//*     COURSE #: CSC 40300 11                              DUE DATE: October 19, 2015          *
//*                                                                                             *
//***********************************************************************************************

#include "TableClass.h"

//************************************* FUNCTION TableClass *****************************************
TableClass::TableClass()
{
        // Recieves - Nothing
        // Task     - Initializes the "table".
        // Returns  - The new initialized "table".


	for(int i = 0; i < 101; i++)
	{
		for(int j = 0; j < 101; j++)
		{
			table[i][j] = ' ';
		}
		minimizedTerms[i] = 0;
	}
}
//************************************* END OF FUNCTION TableClass **********************************


//************************************* FUNCTION CreateSingleXinColumn *****************************************
void TableClass::CreateSingleXinColumn(Term_Type OriginalTerms[], Term_Type unMatchedTerms[], int numOriginalTerms, int numUnMatchedTerms)
{
        // Recieves - The original terms, the un-Matched terms, and how many terms there are of both.
        // Task     - Finds un-Matched terms that are subsets of Original terms.
        // Returns  - A brand new "table".

	for(int i = 0; i < numUnMatchedTerms; i++)	// UnMatchedTerms
	{
		char unMatchedTerm[101] = {0};
		strcpy(unMatchedTerm, unMatchedTerms[i].term);
		
		for(int j = 0; j < numOriginalTerms; j++)	// Orignal Terms
		{
		char OriginalTerm[101] = {0};
		strcpy(OriginalTerm, OriginalTerms[j].term);	// allows the program to test values;

			bool subsets = false;

			for(int k = 0; k < OriginalTerms[0].termSize; k++)	// Figures out if the two terms being tested below are subsets.
			{
				if(OriginalTerm[k] == unMatchedTerm[k] || unMatchedTerm[k] == '-')	// if they are subsets
					subsets = true;

				else
				{
					subsets = false;
					cout << '-';
					break;	// Otherwise, test the next term.
				}
			}

			if(subsets == true)
			{
				table[i][j] = 'x';	// then place an 'x' in the table.
				cout << table[i][j];
			}

		}
		cout << endl;
	}
	cout << endl;
}
//************************************* END OF FUNCTION CreateSingleXinColumn **********************************

//************************************* FUNCTION PerformTableOperations *****************************************
void TableClass::PerformTableOperations(Term_Type OriginalTerms[], Term_Type unMatchedTerms[], int numOriginalTerms, int &numUnMatchedTerms)
{
	CreateSingleXinColumn(OriginalTerms, unMatchedTerms, numOriginalTerms, numUnMatchedTerms);
	FindSingleXinColumn(numOriginalTerms, numUnMatchedTerms);
	FindXinSameRow_As_SingleXinColumn(numOriginalTerms, numUnMatchedTerms);
	FindResultingTerms(unMatchedTerms, numOriginalTerms, numUnMatchedTerms);
}
//************************************* END OF FUNCTION PerformTableOperations **********************************

//************************************* FUNCTION FindSingleXinColumn *****************************************
void TableClass::FindSingleXinColumn(int numOriginalTerms, int numUnMatchedTerms)
{
        // Recieves - The "table".
        // Task     - Finds all x's that are the only 'x' in any column.
        // Returns  - The "table".

	for(int i = 0; i < numOriginalTerms; i++)	// i = column number / original term
	{
		bool singleX = false;
		int xpos = -1;

		for(int j = 0; j < numUnMatchedTerms; j++)	// j = row number / unMatchedTerm
		{
			if(table[j][i] == 'x')	// if an x has been found in the column
			{
				if(singleX == false)	// if a "single" x does not already exist.
				{
					singleX = true;
					xpos = j;
				}
				else
				{
					singleX = false;
					xpos = -1;
					break;
				}
			}


		}

		if(singleX == true)
		{
			table[xpos][i] = 'c';
			xpos = -1;
			cout << "single x in column" << endl;
		}

	}


}
//************************************* END OF FUNCTION FindSingleXinColumn **********************************

//************************************* FUNCTION FindXinSameRow_As_SingleXinColumn *****************************************
void TableClass::FindXinSameRow_As_SingleXinColumn(int numOriginalTerms, int numUnMatchedTerms)
{
        // Recieves - The "table"
        // Task     - Finds an 'x' that is in the same row as "a single 'x' in a column"
        // Returns  - The "table"

	for(int i = 0; i < numUnMatchedTerms; i++)	// look in the column
	{
		bool foundSomeRandomXinRow = false;
		bool foundSingleXinColumn = false;

		int locRandomXinRow[2] = {0};

		bool foundBoth = false;

		for(int j = 0; j < numOriginalTerms; j++)	// look in the row
		{
			if(table[i][j] == 'x')	// if an 'x' has been found in a row
			{
				foundSomeRandomXinRow = true;	// remember that an 'x' had been found
				locRandomXinRow[0] = i;
				locRandomXinRow[1] = j;
			}

			if(table[i][j] == 'c')	// if an 'x' has a circle around it.
			{
				foundSingleXinColumn = true;
			}

			if(foundSomeRandomXinRow == true && foundSingleXinColumn == true)
				foundBoth = true;

			if(foundBoth == true)
			{
				table[locRandomXinRow[0]][locRandomXinRow[1]] = 's';	// put a square around x's in rows that contain a 'single-x in a column'
				cout << "made a square" << endl;
				foundBoth = false;
				break;
			}
		}
	}
}
//************************************* END OF FUNCTION FindXinSameRow_As_SingleXinColumn **********************************

//************************************* FUNCTION FindResultingTerms *****************************************
void TableClass::FindResultingTerms(Term_Type unMatchedTerms[], int numOriginalTerms, int &numUnMatchedTerms)
{
        // Recieves - The "table"
        // Task     - Finds the rows that have "squared" x's along with "circled x's.
        // Returns  - the un-Matched terms at the head of those rows.

	for(int i = 0; i < numUnMatchedTerms; i++)	// original Terms
	{
		for(int j = 0; j < numOriginalTerms; j++)	// unMatchedTerms
		{
			if(table[i][j] == 's')	// checks if an 'x' has a square around it.
			{
				unMatchedTerms[i].isFinalTerm = true;
				continue;
			}
		}
	}
}
//************************************* END OF FUNCTION FindResultingTerms **********************************








