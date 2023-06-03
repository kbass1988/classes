/* DatumStack.cpp
*  Kalead Bassma
*  CS15M1
*  Imlementation file for Datumstack that creates a stack of Datum objects
*/

#include "datumStack.h"

/* DatumStack Constructor
*  Purpose: Initializes the DatumStack object
*  Parameters: None.
*  Returns: A DatumStack with an initialzied stack
*/

DatumStack::DatumStack(){

    stack.reserve(1);

}

DatumStack::DatumStack(int len, Datum *list){

   for(int i=0;i<len;i++){
       stack.push_back(list[i]);
   }

}
/* DatumStack Destructor
*  Purpose: Clears the DatumStack obkect
*  Parameters: None.
*  Returns: Clears the heap
*/

DatumStack::~DatumStack(){
    clear();
}

/* clear()
*  Purpose: Clears the stack.
*  Parameters: None.
*  Returns: A cleared vector that is used as a stack
*/

void DatumStack::clear(){
    stack.clear();
}

/* size()
*  Purpose: Returns the number of items currently in the stack
*  Parameters: None.
*  Returns: The number of items in the stack as an integer
*/

int DatumStack::size(){
    return stack.size();
}

/* top()
*  Purpose: Returns the last item in the vector (the top) of the stack
*  Parameters: None.
*  Returns: The item on top of the stack
*/

Datum DatumStack::top(){
    return stack[size()-1]; //returns the last element inserted IAW stack specification LIFO
}

/* pop()
*  Purpose: Removes the top of the stack
*  Parameters: None.
*  Returns: None.
*/


void DatumStack::pop(){
    stack.pop_back();
}

/* push()
*  Purpose: Adds an item to the stack
*  Parameters: Datum object to be added
*  Returns: A filled stack
*/

void DatumStack::push(Datum &insertion){
    stack.push_back(insertion);
}


bool DatumStack::empty(){
    if(stack.empty()==true){
        return true;
    } else{
        return false;
    }
}