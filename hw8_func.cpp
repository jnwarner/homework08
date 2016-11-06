//Programmers: ANDREW BRAY, JOSHUA WARNER    IDs: 12518487, 12522483
//Class: cs1570                              Sections: A, B
//Date: 11/05/16                             File: hw8.h
//Description:

#include "hw8.h"

// Desc: Generates random number between lowerLimit and upperLimit
// Pre: lowerLimit and upperLimit must be shorts passed to function
// Post: Return random number
short myRand(const short lowerLimit, const short upperLimit)
{
  return rand() % (upperLimit - lowerLimit + 1) + lowerLimit;
}
