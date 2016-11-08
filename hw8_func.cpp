//Programmers: ANDREW BRAY, JOSHUA WARNER    IDs: 12518487, 12522483
//Class: cs1570                              Sections: A, B
//Date: 11/05/16                             File: hw8.h
//Description:

#include "hw8.h"

short myRand(const short lowerLimit, const short upperLimit)
{
  return rand() % (upperLimit - lowerLimit + 1) + lowerLimit;
}


void candidateResponse(const string fileName, const int& score)
{
  // Connect file
  ifstream fin(fileName.c_str());
  char response[MAX_SENTENCE_VALUE];
  char word[MAX_WORD_VALUE];
  short fileLength;

  if(fin.is_open())
  {
    fin >> fileLength;

    short randomNumber = myRand(1, fileLength);

    for(short i = 0; i < randomNumber; i++)
    {
      fin.getline(response, MAX_SENTENCE_VALUE);

      short size = strlen(response);

      if (i + 1 == randomNumber)
      {
        for (short r = 0; r < size; r++)
        {
          cout << response[r];
        }
      }

      fin.clear();
    }
  } else
    cout << "The file is not open, you idiot" << endl;

  // Close file
  fin.close();

  return;
}

void candidateInterjection(const string fileName)
{
  ifstream fin(fileName.c_str());
  short size;
  fin >> size;
  short index = myRand(0,size-1);
  char interject[MAX_SENTENCE_VALUE];


  for(int i = 0; i < size; i++)
  {
    fin.ignore(500, '\n');
    if(i == index)
      fin.getline(interject, MAX_SENTENCE_VALUE, '\n');
  }

  for(int i = 0; i < strlen(interject); i++)
    cout << interject[i];

  fin.close();
  return;
}

void appendInsult(const string fileName)
{
  ifstream fin(fileName.c_str());
  const short size = fileSize(fileName);

  short index = myRand(0,size-1);
  char append[MAX_SENTENCE_VALUE];
  for(int i = 0; i < size; i++)
  {
    if(i == index)
      fin.getline(append, MAX_SENTENCE_VALUE, '\n');
  }

  for(int i = 0; i < strlen(append); i++)
    cout << append[i];

  fin.close();
  return;
}

short fileSize(const string fileName)
{
  ifstream fin(fileName.c_str());
  short size = 0;
  string dummy;
  while(fin >> dummy)
    size++;

  fin.close();
  return size;
}
