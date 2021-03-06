//Programmers: ANDREW BRAY, JOSHUA WARNER         IDs: 12518487, 12522483
//Class: cs1570                              Sections: A, B
//Date: 11/05/16                             File: hw8.h
//Description:


#ifndef  HW8_H
#define  HW8_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <cstring>
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
const short PREFIX_PERC = 50;
  //Lower and upper limit for the percent chance generator (1 - 100)
const short MIN_PERC = 1;
const short MAX_PERC = 100;
  //Lower and upper limits for how many sentences a candidate will say
const short MIN_SPEAK = 2;
const short MAX_SPEAK = 4;
  //The point value for each character
const char ONE_PT[] = {'e', 'a', 'i', 'o', 'n', 'r', 't', 'l', 's', 'u'};
const char TWO_PT[] = {'d','g'};
const char THREE_PT[] = {'b','c','m','p'};
const char FOUR_PT[] = {'f','h','v','w','y'};
const char FIVE_PT[] = {'k'};
const char EIGHT_PT[] = {'j','x'};
const char TEN_PT[] = {'q','z'};
  //The amount of questions the user will ask
const short NUM_QUESTIONS = 8;
  //The punctuation
const char PERIOD = '.';
const char QUESTION = '?';
const char EXCLAME = '!';
  // Max values
const short MAX_SENTENCE_VALUE = 1000;
const short MAX_WORD_VALUE = 20;

  // Filenames
const string CANDIDATE1_RESPONSE_FILE = "candidate1_sentences.dat";
const string CANDIDATE1_INTERJECTIONS_FILE = "candidate1_interjections.dat";
const string CANDIDATE2_RESPONSE_FILE = "candidate2_sentences.dat";
const string CANDIDATE2_INTERJECTIONS_FILE = "candidate2_interjections.dat";
const string PREFIX_FILE = "prefix_expressions.dat";

//Structs

//Function Prototypes

// Desc: Generates random number between lowerLimit and upperLimit
// Pre: lowerLimit and upperLimit must be shorts passed to function
// Post: Return random number
short myRand(const short lowerLimit, const short upperLimit);

// Desc: Opens file and gets response from candidate
// Pre: Score must be initialized and modifiable
// Post: Prints candidates response and modifies score
void candidateResponse(const string fileName, int & score);

// Desc: Opens file and determines interjection to be used
// Pre: Score must be modifiable
// Post: Print out candidate interjection
void candidateInterjection(const string fileName, int & score);

//Desc: Opens a file and determines what string to append
//Pre: Score must be modifiable
//Post: An insult/prefix has been appended
void appendPrefix(const string fileName, int & score);

//Desc:This function finds how many data sets are in a file
//Pre:None
//Post: The number of data sets are returned
short fileSize(const string fileName);

//Desc: Finds the number of words in an ntca
//Pre: None
//Post: Returns the number of words in the passed ntca
short numWords(const char sentence[]);


//Desc: This function displays random sentence fragments and calculates their
//  scores. Also calls the candidateInterjection function
//Pre: Score must be modifiable
//Post: The candidate's random response is displayed and the score is calculated
void splitSentence(const string fileName, int & score);

//Desc: This function finds how many characters are in an NTCA
//Pre: None
//Post: The number of characters in the NTCA is returned
short charCounter(const char sentence[], const short length);

//Desc: This function calculates the score value of a single letter. It also
//  determines whether the value of a letter should be doubled or tripled
//Pre: Score must be modifiable
//Post: The point value of the letter is added to score
void letterScore(int & score, const char letter);

//Desc: This function calculates the point value of an entire sentence. It
//  determines whether a word's score must be doubled or tripled and calls the
//  letterScore function
//Pre: Score must be modifiable
//Post: The point value for the sentence is added to score
void scoreAdjuster(int & score, char arr[]);

#endif
