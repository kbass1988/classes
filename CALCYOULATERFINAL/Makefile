###
### Makefile for CalcYouLater Project
### CalcYouLater is an RPN calculator
###
### Author:  Kalead Bassma



CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -std=c++14 -c
LDFLAGS  = -g3
PROGRAM = calcyoul8er


$(PROGRAM):	$(PROGRAM).o Datum.o	DatumStack.o	RPNCalc.o	
	${CXX} ${LDFLAGS} $^ -o $@


$(PROGRAM).o:  $(PROGRAM).cpp
	${CXX} ${CXXFLAGS}  $(PROGRAM).cpp


Datum.o:  Datum.cpp 
	$(CXX) $(CXXFLAGS) $<


DatumStack.o:  DatumStack.cpp 
	$(CXX) $(CXXFLAGS) $<


RPNCalc.o:  RPNCalc.cpp 
	$(CXX) $(CXXFLAGS) $<




