 //******************************** PROGRAM IDENTIFICATION *************************************
//*                                                                                             *
//*     PROGRAM FILE NAME: TableClass.h     ASSIGNMENT #: 1             Grade:   ____________   *
//*                                                                                             *
//*     PROGRAM AUTHOR:     ______________________________________                              *
//*                                     ERIC BUTTON                                             *
//*                                                                                             *
//*     COURSE #: CSC 40300 11                              DUE DATE: October 19, 2015          *
//*                                                                                             *
//***********************************************************************************************

#ifndef TABLECLASS_H
#define TABLECLASS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cctype>

#include "Implementation.h"

using namespace std;

class TableClass
{

private:
//	int lenX,	// number of "OriginalTerms"
//		lenY;	// number of "unMatchedTerms"
	char table[101][101];
	int minimizedTerms[101];


public:
	TableClass();
	void TableClass::PerformTableOperations(Term_Type OriginalTerms[], Term_Type unMatchedTerms[], int numOriginalTerms, int &numUnMatchedTerms);	// comes first
	void TableClass::FindSingleXinColumn(int numOriginalTerms, int numUnMatchedTerms);	// comes third
	void TableClass::FindXinSameRow_As_SingleXinColumn(int numOriginalTerms, int numUnMatchedTerms);	// comes fourth
	void TableClass::FindResultingTerms(Term_Type unMatchedTerms[], int numOriginalTerms, int &numUnMatchedTerms);	// comes fifth

	void TableClass::CreateSingleXinColumn(Term_Type OriginalTerms[], Term_Type unMatchedTerms[], int numOriginalTerms, int numUnMatchedTerms);	// comes second


};

#endif;