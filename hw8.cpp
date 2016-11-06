//Programmers: ANDREW BRAY, JOSHUA WARNER    IDs: 12518487, 12522483
//Class: cs1570                              Sections: A, B
//Date: 11/05/16                             File: hw8.cpp
//Description:

#include "hw8.h"


int main()
{
  //Variable Declarations
    //The question string is used to take in the user's questions
  string question;
  int score1 = 0;
  int score2 = 0;


  // Seed the RNG
  srand(time(NULL));

  // Greet user
  cout << "Hello, and welcome to The Debate Simulator!" << endl;

  //This for loop allows the user to ask the candidates questions
  for(int i = 1; i <= NUM_QUESTIONS; i++)
  {
    cout<<"Candidate #"<<i%2 == 0 ? "1: ":"2: ";
    cin >> question;
    cout<<"ans: "
    if(i % 2 == 0)
      candidateResponse(CANDIDATE1_RESPONSE_FILE, score1);
    else
      candidateResponse(CANDIDATE2_RESPONSE_FILE, score2);

  }


  return 0;
}
