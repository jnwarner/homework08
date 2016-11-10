//Programmers: ANDREW BRAY, JOSHUA WARNER    IDs: 12518487, 12522483
//Class: cs1570                              Sections: A, B
//Date: 11/05/16                             File: hw8.h
//Description:

#include "hw8.h"

short myRand(const short lowerLimit, const short upperLimit)
{
  // Return random number
  return rand() % (upperLimit - lowerLimit + 1) + lowerLimit;
}


void candidateResponse(const string fileName,  int& score)
{
  // Connect file
  ifstream fin(fileName.c_str());

  // Check if file is open
  if(fin.is_open())
  {
    // Split sentence and calculate score
    splitSentence(fileName, score);

    // Clear for good measure
    fin.clear();
  }
  else
    // Let the user know the file is not open
    cout << "The file is not open, you idiot" << endl;

  // Close file
  fin.close();

  return;
}

void candidateInterjection(const string fileName, int & score)
{
  // Connect file
  ifstream fin(fileName.c_str());
  short size;   // Declare size
  fin >> size;    // Get size of file
  short index = myRand(0,size-1);   // Generate index
  char interject[MAX_SENTENCE_VALUE];   // Get interjection index

  // Get line at randomly generated index
  for(int i = 0; i < size; i++)
  {
    fin.ignore(500, '\n');
    if(i == index)
      fin.getline(interject, MAX_SENTENCE_VALUE, '\n');
  }

  // Output space for formatting
  cout<<" ";

  // Output interjection
  for(int i = 0; i < strlen(interject); i++)
  {
    cout<<interject[i];
  }
  // Output space for formatting
  cout<<" ";

  // Adjusts score according to guidelines
  scoreAdjuster(score, interject);

  // Close the file
  fin.close();
  return;
}

void appendPrefix(const string fileName, int & score)
{
  // Connect file
  ifstream fin(fileName.c_str());
  // Set size to size of file
  const short size = fileSize(fileName);
  // Set index equal to random number between 1 and size
  short index = myRand(1, size);
  // Declare append variable
  char append[MAX_SENTENCE_VALUE];

  // get random line
  for(int i = 0; i < size; i++)
  {
    if(i == index - 1)
        fin.getline(append, MAX_SENTENCE_VALUE, '\n');
    fin.ignore(500, '\n');
  }
  //Printing the prefix
  for(int i = 0; i < strlen(append); i++)
  {
    // Output append[]
    cout << append[i];
  }
  // Output space for formatting
  cout<<" ";

  // Adjust score
  scoreAdjuster(score, append);

  // Close file
  fin.close();
  return;
}

short fileSize(const string fileName)
{
  // Connect file
  ifstream fin(fileName.c_str());
  short size = 0;   // Set size to 0
  string dummy;   // Dummy string to get line
  while(getline(fin, dummy))  // Increments size
    size++;

  // close file
  fin.close();
  return size;
}

short numWords(const char sentence[])
{
  short words = 1;  // Words set to 1 by default
  short index = 0;  // Index set to 0
  string dummy;   // Dummy sentence for finding number of words
  while(sentence[index] != '\0')
  {
    // Check if index is space
    if(isspace(sentence[index]))
      words++;
    index++;
  }
  return words;
}

void splitSentence(const string fileName, int & score)
{
  // Declare fin
  ifstream fin;

  short fileLength;   // File length
  short splitVal;   // Split value based on numSentences
  char tempSentence[MAX_SENTENCE_VALUE];  // tempSentence

  short numSentences = myRand(MIN_SPEAK, MAX_SPEAK);  // Generate numSentences

  appendPrefix(PREFIX_FILE, score);   // append prefix to output sentence

  // For loop for number of sentences generated
  for (short i = 0; i < numSentences; i++)
  {
    // Connect file to go to top of file
    fin.open(fileName.c_str());
    fin.ignore();
    fin.clear();

    // Get fileLength
    fin >> fileLength;

    // Get random sentence within file
    short randomSentence = myRand(2, fileLength);

    // Getline of randomSentence
    for (short t = 0; t + 1 <= randomSentence; t++)
    {
      fin.getline(tempSentence, MAX_SENTENCE_VALUE);
    }

    // Get length of string
    short stringLength = strlen(tempSentence);

    // Calculate splitVal
    splitVal = stringLength / numSentences;

    // Get endVal for string chunk calculation
    short endVal = splitVal * 2;

    // check for first sentence
    if (i == 0)
    {
      // Check if index at splitVal and endVal are spaces. if not, sutract
      if (tempSentence[splitVal] != ' ' || tempSentence[endVal] != ' ')
      {
        while (tempSentence[splitVal] != ' ')
          splitVal--;
        while (tempSentence[endVal] != ' ')
          endVal--;
      }

      // output tempSentence
      for (short t = 0; t < splitVal; t++)
        cout << tempSentence[t];
    }

    if (i == 1)
    {
      // Check if index at splitVal and endVal are spaces. if not, sutract
      if (tempSentence[splitVal] != ' ' || tempSentence[endVal] != ' ')
      {
        while (tempSentence[splitVal] != ' ')
          splitVal--;
        while (tempSentence[endVal] != ' ')
          endVal--;
      }

      // output tempSentence
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
      // calculate splitval and endval for third sentence
      splitVal *= 2;
      endVal *= 2;
      // Check if index at splitVal and endVal are spaces. if not, sutract
      if (tempSentence[splitVal] != ' ' || tempSentence[endVal] != ' ')
      {
        while (tempSentence[splitVal] != ' ')
          splitVal--;
        while (tempSentence[endVal] != ' ')
          endVal--;
      }

      // output tempSentence
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
      // Get new splitval for last chunk
      splitVal *= 3;
      // Check if index at splitVal is a space. if not, sutract
      if (tempSentence[splitVal] != ' ')
      {
        while (tempSentence[splitVal] != ' ')
          splitVal--;
      }

      // output tempSentence
      for (short t = splitVal; t < stringLength-1; t++)
      {
        cout << tempSentence[t];
      }
      // Calculate punctuation at the end of sentence
      if(myRand(MIN_PERC, MAX_PERC) <= PERIOD_PERC)
        cout << '.';
      else if(myRand(MIN_PERC, MAX_PERC) <= QUEST_PERC)
        cout <<'?';
      else
        cout <<'!';
    }

    // Adjust score
    scoreAdjuster(score, tempSentence);
    short interjectionChance = myRand(MIN_PERC, MAX_PERC);

    // Calculate chance of interjection
    if(i != numSentences - 1)
    {
      if (interjectionChance < INTERJECT_PERC)
      {
        if (fileName == CANDIDATE1_RESPONSE_FILE)
          candidateInterjection(CANDIDATE1_INTERJECTIONS_FILE, score);
        else
          candidateInterjection(CANDIDATE2_INTERJECTIONS_FILE, score);
      }
    }
    // Close file
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
    index++;
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
      index++;
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
      index++;
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
      index++;
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
      index++;
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
      index++;
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
      index++;
    }
  }


  return;
}
