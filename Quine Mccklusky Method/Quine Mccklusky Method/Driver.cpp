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

//********************************* PROGRAM DESCRIPTION *****************************************
//*                                                                                             *
//*     PROCESS: This program is designed to perform the Quine-McKlusky method for minimizing	*
//*              boolean expressions. It uses "columns" and a "table" to perfrom the operation. *
//*                                                                                             *
//***********************************************************************************************


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cctype>

#include "Implementation.h"
#include "ColumnClass.h"
#include "TableClass.h"

using namespace std;

void InitializeTerms(Term_Type terms[]);

//************************************* FUNCTION main *******************************************
int main()
{
	Term_Type terms[101];
	Term_Type OriginalTerms[101];
	int numTerms = 0;

	ifstream inputFile("DATA1.txt");	// data file
	ofstream outputFile("output.txt");	// output file

	int probNum = 1;

	while(!inputFile.eof())	// look through the file until it ends
	{
		numTerms = 0;
		char term[11] = {0};	// A single term.

		InitializeTerms(terms);	// erases the data inside "terms".
		
		for(int i = 0;; i++)			// while not at the end of the line.
		{
			inputFile >> term;

			if(term[0] == 'X')	// if at the end of the line
			{
				break;	// get out of this 'for loop'
			}
			
			strcpy(terms[i].term, term);				// puts the term in the array.
			terms[i].termSize = strlen(terms[i].term);	// finds how long the term is;
			numTerms++;
		}

		int numOriginalTerms = numTerms;

		ColumnClass column;
		column.CopyToNewArray(OriginalTerms, terms, numOriginalTerms);	// copy the original "terms" array.
		column.FindPairs(terms, numTerms);

		TableClass table;
		table.PerformTableOperations(OriginalTerms, terms, numOriginalTerms, numTerms);

		// prints the original expression

		outputFile << probNum++ << ") \n";
		outputFile << "The Original Boolean Expression is: " << endl;

		for(int i = 0; i < numOriginalTerms; i++)
		{
			outputFile << OriginalTerms[i].term;

			if(i + 1 != numOriginalTerms)
				outputFile << " + ";
		}

		// prints the minimized expression
		outputFile << "\n\nThe Minimized Boolean Expression is: " << endl;

		for(int i = 0; i < numTerms; i++)
		{

			if(terms[i].isFinalTerm == true)
				for(int s = 0; s < terms[i].termSize; s++)
				{	
					if(terms[i].term[s] != '-')
						outputFile << terms[i].term[s];
				}

			if(i + 1 == numTerms)
			{
				outputFile << "\n" << endl;
				break;
			}
			if(terms[i].isFinalTerm == true)
				outputFile << " + ";
		}

		outputFile << "*******************************************************************************************"
			       << endl;

		cout << "===========\n"
			 << "New Problem\n"
			 << "==========="
			 << endl;
	}
	

	return 0;
}
//************************************* END OF FUNCTION main ************************************


//************************************* FUNCTION InitializeTerms ********************************
void InitializeTerms(Term_Type terms[])
{
        // Recieves - All the terms
        // Task - Initializes the "terms" array.
        // Returns - The "terms" array.

	for(int i = 0; i < 101; i++)
	{
		terms[i].isComplemented = false;
		terms[i].isDuplicate = false;
		terms[i].next = NULL;
		terms[i].previous = NULL;
		strcpy(terms[i].term, "          "); // the blank is 10 'spaces' long.
		terms[i].termSize = 0;
		terms[i].isFinalTerm = false;
	}
}
//************************************* END OF FUNCTION InitializeTerms *************************


