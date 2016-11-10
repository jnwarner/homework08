//Programmers: ANDREW BRAY, JOSHUA WARNER    IDs: 12518487, 12522483
//Class: cs1570                              Sections: A, B
//Date: 11/05/16                             File: hw8.h
//Description:

#include "hw8.h"

short myRand(const short lowerLimit, const short upperLimit)
{
  return rand() % (upperLimit - lowerLimit + 1) + lowerLimit;
}


void candidateResponse(const string fileName,  int& score)
{
  // Connect file
  ifstream fin(fileName.c_str());

  if(fin.is_open())
  {
    splitSentence(fileName, score);

    fin.clear();
  }
  else
    cout << "The file is not open, you idiot" << endl;

  // Close file
  fin.close();

  return;
}

void candidateInterjection(const string fileName, int & score)
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
  {
    cout<<interject[i];
  }

  scoreAdjuster(score, interject);

  fin.close();
  return;
}

void appendPrefix(const string fileName, int & score)
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
  for(int i = 0; i < strlen(append); i++)
  {
    cout<<append[i];
  }

  scoreAdjuster(score, append);

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

void splitSentence(const string fileName, int & score)
{
  ifstream fin;

  short fileLength;
  short splitVal;
  char tempSentence[MAX_SENTENCE_VALUE];

  short numSentences = myRand(MIN_SPEAK, MAX_SPEAK);

  appendPrefix(PREFIX_FILE, score);

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

      for (short t = splitVal; t < stringLength-1; t++)
      {
        cout << tempSentence[t];
      }
      if(myRand(MIN_PERC, MAX_PERC) <= PERIOD_PERC)
        cout << '.';
      else if(myRand(MIN_PERC, MAX_PERC) <= QUEST_PERC)
        cout <<'?';
      else
        cout <<'!';
    }

    scoreAdjuster(score, tempSentence);
    short interjectionChance = myRand(MIN_PERC, MAX_PERC);

    if (interjectionChance < INTERJECT_PERC)
    {
      if (fileName == CANDIDATE1_RESPONSE_FILE)
        candidateInterjection(CANDIDATE1_INTERJECTIONS_FILE, score);
      else
        candidateInterjection(CANDIDATE2_INTERJECTIONS_FILE, score);
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

void scoreAdjuster(int & score, char arr[])
{
  int letScore = 0;
  int wordScore = 0;
  for(int i = 0; i < strlen(arr); i++)
  {
    if(isalpha(arr[i]))
    {
      wordScore = 0;
      if(isupper(arr[i]))
        tolower(arr[i]);
      letterScore(letScore, arr[i]);
    }
    else if(isspace(arr[i]) || ispunct(arr[i]))
    {
      wordScore += letScore;
      letScore = 0;
      if(myRand(MIN_PERC, MAX_PERC) <= WORD_DBL)
        wordScore *= 2;
      else if(myRand(MIN_PERC, MAX_PERC) <= WORD_TRPL)
        wordScore *= 3;
      score += wordScore;
    }
  }
  return;
}

void letterScore(int & score, const char letter)
{
  short tempScore = 0;
  bool found = false;
  short index = 0;
  while(!found && index < strlen(ONE_PT))
  {
    if (letter == ONE_PT[index])
    {
      found = true;
      tempScore = 1;
      if(myRand(MIN_PERC, MAX_PERC) <= CHAR_DBL)
        tempScore *= 2;
      else if(myRand(MIN_PERC, MAX_PERC) <= CHAR_TRPL)
        tempScore *= 3;
      score += tempScore;
    }
  }
  if(!found)
  {
    while(!found && index < strlen(TEN_PT))
    {
      if (letter == TEN_PT[index])
      {
        found = true;
        tempScore = 10;
        if(myRand(MIN_PERC, MAX_PERC) <= CHAR_DBL)
          tempScore *= 2;
        else if(myRand(MIN_PERC, MAX_PERC) <= CHAR_TRPL)
          tempScore *= 3;
        score += tempScore;
      }
    }

    while(!found && index < strlen(TWO_PT))
    {
      if (letter == TWO_PT[index])
      {
        found = true;
        tempScore = 2;
        if(myRand(MIN_PERC, MAX_PERC) <= CHAR_DBL)
          tempScore *= 2;
        else if(myRand(MIN_PERC, MAX_PERC) <= CHAR_TRPL)
          tempScore *= 3;
        score += tempScore;
      }
    }

    while(!found && index < strlen(THREE_PT))
    {
      if (letter == THREE_PT[index])
      {
        found = true;
        tempScore = 3;
        if(myRand(MIN_PERC, MAX_PERC) <= CHAR_DBL)
          tempScore *= 2;
        else if(myRand(MIN_PERC, MAX_PERC) <= CHAR_TRPL)
          tempScore *= 3;
        score += tempScore;
      }
    }

    while(!found && index < strlen(FOUR_PT))
    {
      if (letter == FOUR_PT[index])
      {
        found = true;
        tempScore = 4;
        if(myRand(MIN_PERC, MAX_PERC) <= CHAR_DBL)
          tempScore *= 2;
        else if(myRand(MIN_PERC, MAX_PERC) <= CHAR_TRPL)
          tempScore *= 3;
        score += tempScore;
      }
    }

    while(!found && index < strlen(FIVE_PT))
    {
      if (letter == FIVE_PT[index])
      {
        found = true;
        tempScore = 5;
        if(myRand(MIN_PERC, MAX_PERC) <= CHAR_DBL)
          tempScore *= 2;
        else if(myRand(MIN_PERC, MAX_PERC) <= CHAR_TRPL)
          tempScore *= 3;
        score += tempScore;
      }
    }

    while(!found && index < strlen(EIGHT_PT))
    {
      if (letter == EIGHT_PT[index])
      {
        found = true;
        tempScore = 8;
        if(myRand(MIN_PERC, MAX_PERC) <= CHAR_DBL)
          tempScore *= 2;
        else if(myRand(MIN_PERC, MAX_PERC) <= CHAR_TRPL)
          tempScore *= 3;
        score += tempScore;
      }
    }
  }


  return;
}
