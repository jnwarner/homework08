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
  char append[MAX_SENTENCE_VALUE];
  char c1_response[MAX_SENTENCE_VALUE];
  char c2_response[MAX_SENTENCE_VALUE];
  //char word[MAX_WORD_VALUE];
  short fileLength;

  if(fin.is_open())
  {
    if (fileName == CANDIDATE1_RESPONSE_FILE)
      splitSentence(CANDIDATE1_RESPONSE_FILE, c1_response);
    else
      splitSentence(CANDIDATE2_RESPONSE_FILE, c2_response);

    fin.clear();
  }
  else
    cout << "The file is not open, you idiot" << endl;

  // Close file
  fin.close();

  return;
}

void candidateInterjection(const string fileName, char response[])
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

  strcat(response, interject);


  fin.close();
  return;
}

void appendPrefix(const string fileName, char response[])
{
  ifstream fin(fileName.c_str());
  const short size = fileSize(fileName);

  short index = myRand(1, size);
  char append[MAX_SENTENCE_VALUE];

  for(int i = 0; i < size; i++)
  {
    if(i == index - 1)
        fin.getline(append, MAX_SENTENCE_VALUE, '\n');
    fin.ignore(500, '\n');
  }
  //Printing the prefix
  strcat(response, append);

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

void splitSentence(const string fileName, char response[])
{
  ifstream fin;

  short fileLength;
  short splitVal;
  short responseVal;
  short tempScore;
  char tempSentence[MAX_SENTENCE_VALUE];

  short numSentences = myRand(MIN_SPEAK, MAX_SPEAK);

  appendPrefix(PREFIX_FILE, response);

  for (short i = 0; i < numSentences; i++)
  {
    fin.open(fileName.c_str());
    fin.ignore();
    fin.clear();

    fin >> fileLength;

    short randomSentence = myRand(2, fileLength);

    for (short t = 0; t + 1 <= randomSentence; t++)
    {
      fin.getline(tempSentence, MAX_SENTENCE_VALUE);
    }

    short stringLength = strlen(tempSentence);

    splitVal = stringLength / numSentences;

    short endVal = splitVal * 2;

    if (i == 0)
    {
      if (tempSentence[splitVal] != ' ' || tempSentence[endVal] != ' ')
      {
        while (tempSentence[splitVal] != ' ')
          splitVal--;
        while (tempSentence[endVal] != ' ')
          endVal--;
      }

      for (short t = 0; t < splitVal; t++)
        cout << tempSentence[t];
    }

    if (i == 1)
    {
      if (tempSentence[splitVal] != ' ' || tempSentence[endVal] != ' ')
      {
        while (tempSentence[splitVal] != ' ')
          splitVal--;
        while (tempSentence[endVal] != ' ')
          endVal--;
      }

      if (!(numSentences >= 2))
      {
        for (short t = splitVal; t < endVal; t++)
        {
          cout << tempSentence[t];
        }
      }
      else
      {
        for (short t = splitVal; t < stringLength; t++)
        {
          cout << tempSentence[t];
        }
      }
    }

    if (i == 2)
    {
      splitVal *= 2;
      endVal *= 2;
      if (tempSentence[splitVal] != ' ' || tempSentence[endVal] != ' ')
      {
        while (tempSentence[splitVal] != ' ')
          splitVal--;
        while (tempSentence[endVal] != ' ')
          endVal--;
      }

      if (numSentences != 3)
      {
        for (short t = splitVal; t < endVal; t++)
        {
          cout << tempSentence[t];
        }
      }
      else
      {
        for (short t = splitVal; t < stringLength; t++)
        {
          cout << tempSentence[t];
        }
      }
    }

    if (i == 3)
    {
      splitVal *= 3;
      if (tempSentence[splitVal] != ' ')
      {
        while (tempSentence[splitVal] != ' ')
          splitVal--;
      }

      for (short t = splitVal; t < stringLength; t++)
      {
        cout << tempSentence[t];
      }
    }

    short interjectionChance = myRand(MIN_PERC, MAX_PERC);

    if (interjectionChance < INTERJECT_PERC)
    {
      if (fileName == CANDIDATE1_RESPONSE_FILE)
        candidateInterjection(CANDIDATE1_INTERJECTIONS_FILE, response);
      else
        candidateInterjection(CANDIDATE2_INTERJECTIONS_FILE, response);
    }

    fin.close();
  }

  return;
}

short charCounter(const char sentence[], const short length)
{
  short words = 0;
  short index = 0;

  while(words < length)
  {
    if(isspace(sentence[index]))
      words++;
    index++;
  }
  return index;
}
