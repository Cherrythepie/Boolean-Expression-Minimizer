 //******************************** PROGRAM IDENTIFICATION *************************************
//*                                                                                             *
//*     PROGRAM FILE NAME: ColumnClass.cpp     ASSIGNMENT #: 1          Grade:   ____________   *
//*                                                                                             *
//*     PROGRAM AUTHOR:     ______________________________________                              *
//*                                     ERIC BUTTON                                             *
//*                                                                                             *
//*     COURSE #: CSC 40300 11                              DUE DATE: October 19, 2015          *
//*                                                                                             *
//***********************************************************************************************

#include "ColumnClass.h"

//************************************* FUNCTION FindPairs *****************************************
Term_Type * ColumnClass::FindPairs(Term_Type newTerms[], int &numTerms)
{
        // Recieves - The "new" terms.
        // Task     - Perform the "Column" operations of the Quine-McKlusky Method.
        // Returns  - The un-Matched terms and how many of them there are.

	bool AtLeastOneMatch = false;	// show if at least one term has found a match (compliment). Determines if a new column needs to be used.

	Term_Type unMatchedTerms[101];		// will be sent back to driver and used in the Table Class
	InitializeTerms(unMatchedTerms);	
	int numUnMatchedTerms = 0;

	Term_Type newerTerms[101];			// will contain the new values that will be used to find new pairs with.
	InitializeTerms(newerTerms);
	int numNewerTerms = 0;

A:	for(int i = 0; i < numTerms; i++)	// "i" is the initial term.
	{
		bool Matched = false;	// shows if term "i" has no Match. Must remember to check if it is complimented though.

		for(int j = i+1; j < numTerms; j++)	// "j" is the term that "i" is being compared to.
		{
			
			if(FindMatch(newTerms[i], newTerms[j], newerTerms[numNewerTerms]))	// check if term "i" and term "j" compliment each other.
			{
				cout << newTerms[i].term << " + " << newTerms[j].term << " = " << newerTerms[numNewerTerms].term << endl;
				numNewerTerms++;
				Matched = true;
				AtLeastOneMatch = true;
			}
		}

		if(Matched == false && newTerms[i].isComplemented == false)	// if term "i" has no compliment
		{
			// adds to the array of un-matched terms.
			unMatchedTerms[numUnMatchedTerms] = newTerms[i];
			numUnMatchedTerms++;
		}
	}
	// when "newerTerms" has been filled.

	FindDuplicates(newerTerms, numNewerTerms);	// removes duplicate terms from the "newerTerms" array.

//	numNewerTerms ++;	// bring the amount up by 1, so that it will work in the latter functions.

	InitializeTerms(newTerms);	// empty the old terms array.
	CopyToNewArray(newTerms, newerTerms, numNewerTerms);	// copy the values from "newerTerms" to "newTerms".

	numTerms = numNewerTerms;		// sets the number of terms that are in the next column to process data.

	InitializeTerms(newerTerms);	// erases the data in "newerTerms".
	numNewerTerms = 0;

	if(AtLeastOneMatch == false)	// if there are no more columns to check 
	{
		InitializeTerms(newTerms);
		for(int i = 0; i < numUnMatchedTerms; i++)
			newTerms[i] = unMatchedTerms[i];

//		numUnMatchedTerms++;	// brings the amount up by 1, so that it can be returned back to the driver and work properly with the table class.
		numTerms = numUnMatchedTerms;	// allows "numUnMatchedTerms" to be returned.
		return unMatchedTerms;	// returns the terms that will crucial for the table class.
	}
	else
	{
		AtLeastOneMatch = false;
		goto A;
	}
}
//************************************* END OF FUNCTION FindPairs **********************************

//************************************* FUNCTION FindMatch *****************************************
bool ColumnClass::FindMatch(Term_Type &term1, Term_Type &term2, Term_Type &newTerm)
{
        // Recieves - 2 terms that are being compared to each other, and a blank term to hold any new combinations of the other two terms.
        // Task     - Compare the first two terms to each other and see if they match. If they do, make a new term and put it into "newTerm".
        // Returns  - The first two terms and the new term.

	bool match = false;
	int noMatchSpot = -1;
	bool oneSpotWithNoMatch = false;

	for(int i = 0; i < term1.termSize; i++)
	{
		if(term1.term[i] == term2.term[i])
			continue;
		else
		{
			if(oneSpotWithNoMatch == true)
				return false;
			else
			{
				noMatchSpot = i;
				oneSpotWithNoMatch = true;
			}
		}
	}

	strcpy(newTerm.term, term1.term);
	newTerm.term[noMatchSpot] = '-';
	newTerm.termSize = term1.termSize;	// transfer old term attributes to new term
	
	// put a check next to each term;
	term1.isComplemented = true;
	term2.isComplemented = true;

	return true;	// a match was found
}
//************************************* END OF FUNCTION FindMatch **********************************

//************************************* FUNCTION CopyToNewArray *****************************************
void ColumnClass::CopyToNewArray(Term_Type newTerms[], Term_Type newerTerms[], int numTerms)
{
        // Recieves - The "new" terms, the ("newer than 'new' ") terms, and the number of ("newer than 'new' ") terms.
        // Task     - Copies data from the newly created array to the array where the data will be processed out of.
        // Returns  - The "new" terms

	for(int i = 0; i < numTerms; i++)
	{
		newTerms[i] = newerTerms[i];
		int j = 5;
	}
}
//************************************* END OF FUNCTION CopyToNewArray **********************************

//************************************* FUNCTION FindDuplicates *****************************************
void ColumnClass::FindDuplicates(Term_Type terms[], int &numTerms)
{
        // Recieves - All the terms, and how many terms there are.
        // Task     - Finds and removes duplicate terms.
        // Returns  - The now unduplicated terms and how many terms there are now

	for(int i = 0; i < numTerms; i++)	// "i" is the initial term
	{
		for (int j = i+1; j < numTerms; j++)	// "j" is the term that "i" is being compared to.
		{
			if(strcmp(terms[i].term, terms[j].term) == 0)
			{
				terms[j].isDuplicate = true;

				for(int k = j; k < numTerms; k++)	// "k" is the term that removes term "j".
				{
					terms[k] = terms[k+1];	// shunts terms forward to remove duplicate term.
					numTerms--;
				}
			}
		}
	}
}
//************************************* END OF FUNCTION FindDuplicates **********************************

//************************************* FUNCTION InitializeTerms *****************************************
void ColumnClass::InitializeTerms(Term_Type term[])
{
        // Recieves - The old "term" array/ unitialized "term" array.
        // Task     - Initializes the information in the "term" array.
        // Returns  - The re-initialized "term" array.

	for(int i = 0; i < 101; i++)
	{
		term[i].isComplemented = false;
		term[i].isDuplicate = false;
		term[i].next = NULL;
		term[i].previous = NULL;
		strcpy(term[i].term, "          "); // the blank is 10 'spaces' long.
		term[i].termSize = 0;
	}
};
//************************************* END OF FUNCTION InitializeTerms **********************************




