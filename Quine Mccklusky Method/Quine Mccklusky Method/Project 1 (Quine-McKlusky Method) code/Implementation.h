 //******************************** PROGRAM IDENTIFICATION *************************************
//*                                                                                             *
//*     PROGRAM FILE NAME: Implementation.h     ASSIGNMENT #: 1         Grade:   ____________   *
//*                                                                                             *
//*     PROGRAM AUTHOR:     ______________________________________                              *
//*                                     ERIC BUTTON                                             *
//*                                                                                             *
//*     COURSE #: CSC 40300 11                              DUE DATE: October 19, 2015          *
//*                                                                                             *
//***********************************************************************************************

#ifndef IMPLEMENTATION_H
#define IMPLEMENTATION_H

struct Term_Type
{
	char term[11];	// Actual term (Example: "ABC").
	bool isComplemented;	// Is it complemented by another term.
	bool isDuplicate;	// Does another term already exist in column_X.
	short termSize;	// How long is the term (Example: "ABC" has a termSize of 3).
	bool isFinalTerm;

	Term_Type *next, *previous;



};



#endif;