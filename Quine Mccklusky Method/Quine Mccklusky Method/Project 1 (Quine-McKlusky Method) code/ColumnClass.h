 //******************************** PROGRAM IDENTIFICATION *************************************
//*                                                                                             *
//*     PROGRAM FILE NAME: ColumnClass.h     ASSIGNMENT #: 1            Grade:   ____________   *
//*                                                                                             *
//*     PROGRAM AUTHOR:     ______________________________________                              *
//*                                     ERIC BUTTON                                             *
//*                                                                                             *
//*     COURSE #: CSC 40300 11                              DUE DATE: October 19, 2015          *
//*                                                                                             *
//***********************************************************************************************

#ifndef COLUMNCLASS_H
#define COLUMNCLASS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cctype>

#include "Implementation.h"

using namespace std;

class ColumnClass
{

private:
	Term_Type NoMatchTerms[101];
	int numTerms;
	int termSize;

public:
	void		ColumnClass::InitializeTerms(Term_Type term[]);
	Term_Type * ColumnClass::FindPairs(Term_Type newTerms[], int &numTerms);
	bool		ColumnClass::FindMatch(Term_Type &term1, Term_Type &term2, Term_Type &newTerm);
	void		ColumnClass::CopyToNewArray(Term_Type newTerms[], Term_Type newerTerms[], int numTerms);
	void		ColumnClass::FindDuplicates(Term_Type terms[], int &numTerms);




};





#endif;