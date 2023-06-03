/* DatumStack.h
*  Kalead Bassma
*  CS15M1
*  Header file for Datumstack that creates a stack of Datum objects
*/

#include "Datum.h"
#include <iostream>
#ifndef _DATUMSTACK_H_
#include <vector>

class DatumStack{
public: //All members are public per specifications
DatumStack();

DatumStack(int len, Datum *list);

~DatumStack();

void clear();

int size();

Datum top();

void pop();

void push(Datum &insertion);

bool empty();

std::vector <Datum> stack;


};
#endif