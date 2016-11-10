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
  int score1 = 0;//Candidate 1's score
  int tempScore = 0;
  int score2 = 0;//Candidates 2's score
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
    cin.getline(question, MAX_SENTENCE_VALUE, '\n');//Takes in the question
    cout << "ans: ";
    tempScore = 0;
    wordsInQuestion = numWords(question);
    if(i % 2 != 0)
    {
      candidateResponse(CANDIDATE1_RESPONSE_FILE, tempScore);//Prints response
      tempScore /= wordsInQuestion;                          //and gets score
      score1 += tempScore;
      cout<<endl<<"Score: "<<tempScore<<endl;//Prints the score of this response
    }
    else
    {
      candidateResponse(CANDIDATE1_RESPONSE_FILE, tempScore);
      tempScore /= wordsInQuestion;
      score2 += tempScore;
      cout<<endl<<"Score: "<<tempScore<<endl;
    }
  }

  //Outputting the winner
  cout<<endl<<"The final scores are: "<<endl;
  cout<<"Candidate 1: "<<score1<<endl;
  cout<<"Candidate 2: "<<score2<<endl;
  cout<<"The winner is Candidate "<<(score2<score1 ? "2!" :"1!");
  cout<<endl;


  return 0;
}
