//Programmers: ANDREW BRAY, JOSHUA WARNER    IDs: 12518487, 12522483
//Class: cs1570                              Sections: A, B
//Date: 11/05/16                             File: hw8.cpp
//Description:

#include "hw8.h"


int main()
{
  //Variable Declarations
    //The question string is used to take in the user's questions
  char question[MAX_SENTENCE_VALUE];
  int score1 = 0;
  int tempScore = 0;
  int score2 = 0;
  short wordsInQuestion;

  // Seed the RNG
  srand(time(NULL));

  // Greet user
  cout << "Hello, and welcome to The Debate Simulator!" << endl;

  //This for loop allows the user to ask the candidates questions
  for(int i = 1; i <= NUM_QUESTIONS; i++)
  {
    cin.clear();
    cout << endl;
    cout<<"Candidate #" << (i%2 == 0 ? "2: ":"1: ");
    cin.getline(question, MAX_SENTENCE_VALUE, '\n');
    cout << "ans: ";
    wordsInQuestion = numWords(question);
    if(i % 2 != 0)
    {
      candidateResponse(CANDIDATE1_RESPONSE_FILE, tempScore);
      tempScore /= wordsInQuestion;
      score1 += tempScore;
    }
    else
    {
      candidateResponse(CANDIDATE1_RESPONSE_FILE, tempScore);
      tempScore /= wordsInQuestion;
      score2 += tempScore;
    }
  }

  cout<<endl<<"The final scores are: "<<endl;
  cout<<"Candidate 1: "<<score1<<endl;
  cout<<"Candidate 2: "<<score2<<endl;


  return 0;
}
