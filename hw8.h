//Programmers: ANDREW BRAY, JOSHUA WARNER         IDs: 12518487, 12522483
//Class: cs1570                              Sections: A, B
//Date: 11/05/16                             File: hw8.h
//Description:


#ifndef HW8.H
#define HW8.H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <fstream>
using namespace std;

//Constants
   //Percent chance a sentence will end with a . ? or !
   //Random num generator selects number between 1 and 100
   //1-40 results in period. If no period, run the generator again.
   //1-30 results in a ?. If not, run the generator again
const short PERIOD_PERC = 40;
const short QUEST_PERC = 30;
const short EXCLAME_PERC = 30;
  //Percent chance each letter or word increases in score.
  //Works the same as the punctiation chances
const short CHAR_DBL = 3;
const short CHAR_TRPL = 2;
const short WORD_DBL = 5;
const short WORD_TRPL = 2;
  //Percent chance an interjection is interjected
const short INTERJECT_PERC = 25;
  //Used to determine which interjection is selected
const short INTERJECT_MIN = 0;
const short INTERJECT_MAX = 1;
  //Percent chance an introduction/accusation is appended to the sentence
const short INSULT_PERC = 50;
  //Lower and upper limit for the percent chance generator (1 - 100)
const short MIN_PERC = 1;
const short MAX_PERC = 100;
  //Lower and upper limits for how many sentences a candidate will say
const short MIN_SPEAK = 2;
const short MAX_SPEAK = 4;
  //The point value for each character
const char[] ONE_PT = {'e', 'a', 'i', 'o', 'n', 'r', 't', 'l', 's', 'u'};
const char[] TWO_PT = {'d','g'};
const char[] THREE_PT = {'b','c','m','p'};
const char[] FOUR_PT = {'f','h','v','w','y'};
const char[] FIVE_PT = {'k'};
const char[] EIGHT_PT = {'j','x'};
const char[] TEN_PT = {'q','z'};
  //The amount of questions the user will ask
const short NUM_QUESTIONS = 8;
  //The punctuation
const char PERIOD = '.';
const char QUESTION = '?';
const char EXCLAME = '!';


//Structs

//Function Prototypes

void myRand(const short lowerLimit, const short upperLimit);

#endif
