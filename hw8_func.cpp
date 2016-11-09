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
    if(myRand(MIN_PERC,MAX_PERC) <= PREFIX_PERC)
      appendPrefix(PREFIX_FILE);

    short numSentences = myRand(MIN_SPEAK, MAX_SPEAK);
    splitSentence(fileName, numSentences, response);


    //for(short i = 0; i < randomNumber; i++)
    //{

      short size = strlen(response);


        for (short r = 0; r < size; r++)
        {
          cout << response[r];
        }


      fin.clear();
    //}
  }
  else
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

void appendPrefix(const string fileName)
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
  //Printing the prefix
  for(int i = 0; i < strlen(append); i++)
    cout << append[i];
  cout <<" ";

  fin.close();
  return;
}

short fileSize(const string fileName)
{
  ifstream fin(fileName.c_str());
  short size = 0;
  string dummy;
  while(getline(fin, dummy))
    size++;

  fin.close();
  return size;
}

short numWords(const char sentence[])
{
  short words = 1;
  short index = 0;
  string dummy;
  while(sentence[index] != '\0')
  {
    if(isspace(sentence[index]))
      words++;
    index++;
  }
  return words;
}

void splitSentence(const string fileName, const short numSentences, char response[])
{
  ifstream fin(fileName.c_str());
  short splitVal;
  short fileLength;
  fin >> fileLength;
  short pickSentence;
  char tempSentence[MAX_SENTENCE_VALUE];
  char temp1[MAX_SENTENCE_VALUE];
  char temp2[MAX_SENTENCE_VALUE];
  char temp3[MAX_SENTENCE_VALUE];
  char temp4[MAX_SENTENCE_VALUE];
  short index;

  for(int i = 1; i <= numSentences; i++)
  {
    pickSentence = myRand(1, fileLength);
    for(int r = 0; r < fileLength; r++)
    {
      if(r+1 == pickSentence)
      {
        fin.getline(tempSentence, MAX_SENTENCE_VALUE);
        splitVal = numWords(tempSentence) / numSentences;
        index = 0;

        for(int c = 0; c < splitVal; c++)
        {
          do
          {
            temp1[index] = tempSentence[index];
            index++;
          } while(tempSentence[index] != ' ');
        }
        for(int c = 0; c < splitVal; c++)
        {
          do
          {
            temp2[index] = tempSentence[index];
            index++;
          } while(tempSentence[index] != ' ');
        }
        if(numSentences > 2)
        {
          for(int c = 0; c < splitVal; c++)
          {
            do
            {
              temp3[index] = tempSentence[index];
              index++;
            } while(tempSentence[index] != ' ');
          }
        }
        if(numSentences > 3)
        {
          for(int c = 0; c < splitVal; c++)
          {
            do
            {
              temp4[index] = tempSentence[index];
              index++;
            } while(tempSentence[index] != '\0');
          }
        }

        if(i == 1)
          strcat(response, temp1);
        if(i == 2)
          strcat(response, temp2);
        if(i == 3)
          strcat(response, temp3);
        if(i == 4)
          strcat(response, temp4);


        if(i != 1)
        {
          if(myRand(MIN_PERC,MAX_PERC) <= INTERJECT_PERC)
          {
            if(fileName == CANDIDATE1_RESPONSE_FILE)
              candidateInterjection(CANDIDATE1_INTERJECTIONS_FILE);
            else
              candidateInterjection(CANDIDATE2_INTERJECTIONS_FILE);
          }
        }
      }
    }

  }
  return;
}
