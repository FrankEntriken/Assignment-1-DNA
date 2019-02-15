/*
Frank Entriken
2298368
entriken@chapman.edu
CPSC 350
Assignment 1: DNA
*/

#include "DNA.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

DNA::DNA() //constructor
{
  double mean;
  double variance;
  double stdDev;
  double aPercent;
  double tPercent;
  double cPercent;
  double gPercent;

}

DNA::~DNA() //deconstructor
{

}

//finds statistics such as nucleotide and nucleotide bigram probability and line length sum, mean, variance, and standard deviation
void DNA::lineStatistic(ifstream &file, ofstream &outfile)
{
  string previousCharacter;

  double aCount;
  double tCount;
  double cCount;
  double gCount;

  double aaCount, atCount, acCount, agCount;
  double taCount, ttCount, tcCount, tgCount;
  double caCount, ctCount, ccCount, cgCount;
  double gaCount, gtCount, gcCount, ggCount;

  double lineNumber;
  string str;
  while (getline(file, str))
  {
    previousCharacter = "";
    lineNumber += 1;
    for (char character : str)
    {
      //converts char to string
      string s(1, character); //https://www.geeksforgeeks.org/how-to-convert-a-single-character-to-string-in-cpp/

      //converts to uppercase
      transform(s.begin(), s.end(),s.begin(), ::toupper); //https://stackoverflow.com/questions/735204/convert-a-string-in-c-to-upper-case
      if(s == "A")
      {
        aCount += 1;
      }
      if(s == "T")
      {
        tCount += 1;
      }
      if(s == "C")
      {
        cCount += 1;
      }
      if(s == "G")
      {
        gCount += 1;
      }

      //A
      if (previousCharacter + s == "AA")
      {
        aaCount += 1;
      }
      if (previousCharacter + s == "AT")
      {
        atCount += 1;
      }
      if (previousCharacter + s == "AC")
      {
        acCount += 1;
      }
      if (previousCharacter + s == "AG")
      {
        agCount += 1;
      }

      //T
      if (previousCharacter + s == "TA")
      {
        taCount += 1;
      }
      if (previousCharacter + s == "TT")
      {
        ttCount += 1;
      }
      if (previousCharacter + s == "TC")
      {
        tcCount += 1;
      }
      if (previousCharacter + s == "TG")
      {
        tgCount += 1;
      }

      //C
      if (previousCharacter + s == "CA")
      {
        caCount += 1;
      }
      if (previousCharacter + s == "CT")
      {
        ctCount += 1;
      }
      if (previousCharacter + s == "CC")
      {
        ccCount += 1;
      }
      if (previousCharacter + s == "CG")
      {
        cgCount += 1;
      }

      //G
      if (previousCharacter + s == "GA")
      {
        gaCount += 1;
      }
      if (previousCharacter + s == "GT")
      {
        gtCount += 1;
      }
      if (previousCharacter + s == "GC")
      {
        gcCount += 1;
      }
      if (previousCharacter + s == "GG")
      {
        ggCount += 1;
      }
      previousCharacter = s;
    }
  }

  //TOTAL COUNT FOR EACH NUCLEOTIDE
  double lineSum = aCount + tCount + cCount + gCount;

  outfile << "\n~~ NUCLEOTIDE COUNT ~~" << endl;
  outfile << "Total count: " << lineSum << endl;
  outfile << "A count: " << aCount << endl;
  outfile << "T count: " << tCount << endl;
  outfile << "C count: " << cCount << endl;
  outfile << "G count: " << gCount << endl;

  //NUCLEOTIDE PROBABILITY
  aPercent = (aCount / lineSum) * 100;
  tPercent = (tCount / lineSum) * 100;
  cPercent = (cCount / lineSum) * 100;
  gPercent = (gCount / lineSum) * 100;

  outfile << "\n~~ NUCLEOTIDE PROBABILITIES ~~" << endl;
  outfile << "A: " << aPercent << "%" << endl;
  outfile << "T: " << tPercent << "%" << endl;
  outfile << "C: " << cPercent << "%" << endl;
  outfile << "G: " << gPercent << "%" << endl;

  //NUCLEOTIDE BIGRAMS
  outfile << "\n~~ NUCLEOTIDE BIGRAMS ~~" << endl;
  outfile << "AA: " << aaCount << endl;
  outfile << "AT: " << atCount << endl;
  outfile << "AC: " << acCount << endl;
  outfile << "AG: " << agCount << endl;
  outfile << "\n";
  outfile << "TA: " << taCount << endl;
  outfile << "TT: " << ttCount << endl;
  outfile << "TC: " << tcCount << endl;
  outfile << "TG: " << tgCount << endl;
  outfile << "\n";
  outfile << "CA: " << caCount << endl;
  outfile << "CT: " << ctCount << endl;
  outfile << "CC: " << ccCount << endl;
  outfile << "CG: " << cgCount << endl;
  outfile << "\n";
  outfile << "GA: " << gaCount << endl;
  outfile << "GT: " << gtCount << endl;
  outfile << "GC: " << gcCount << endl;
  outfile << "GG: " << ggCount << endl;

  //NUCLEOTIDE BIGRAM PROBABILITY
  double aaPercent = (aaCount / lineSum) * 100;
  double atPercent = (atCount / lineSum) * 100;
  double acPercent = (acCount / lineSum) * 100;
  double agPercent = (agCount / lineSum) * 100;

  double taPercent = (taCount / lineSum) * 100;
  double ttPercent = (ttCount / lineSum) * 100;
  double tcPercent = (tcCount / lineSum) * 100;
  double tgPercent = (tgCount / lineSum) * 100;

  double caPercent = (caCount / lineSum) * 100;
  double ctPercent = (ctCount / lineSum) * 100;
  double ccPercent = (ccCount / lineSum) * 100;
  double cgPercent = (cgCount / lineSum) * 100;

  double gaPercent = (gaCount / lineSum) * 100;
  double gtPercent = (gtCount / lineSum) * 100;
  double gcPercent = (gcCount / lineSum) * 100;
  double ggPercent = (ggCount / lineSum) * 100;

  outfile << "\n~~ NUCLEOTIDE BIGRAM PROBABILITIES ~~" << endl;
  outfile << "AA: " << aaPercent << "%" << endl;
  outfile << "AT: " << atPercent << "%" << endl;
  outfile << "AC: " << acPercent << "%" << endl;
  outfile << "AG: " << agPercent << "%" << endl;
  outfile << "\n";
  outfile << "TA: " << taPercent << "%" << endl;
  outfile << "TT: " << ttPercent << "%" << endl;
  outfile << "TC: " << tcPercent << "%" << endl;
  outfile << "TG: " << tgPercent << "%" << endl;
  outfile << "\n";
  outfile << "CA: " << caPercent << "%" << endl;
  outfile << "CT: " << ctPercent << "%" << endl;
  outfile << "CC: " << ccPercent << "%" << endl;
  outfile << "CG: " << cgPercent << "%" << endl;
  outfile << "\n";
  outfile << "GA: " << gaPercent << "%" << endl;
  outfile << "GT: " << gtPercent << "%" << endl;
  outfile << "GC: " << gcPercent << "%" << endl;
  outfile << "GG: " << ggPercent << "%" << endl;

  //resets the ifstream so that reading from file again starts from the top
  file.clear();
  file.seekg(0, ios::beg); //http://www.cplusplus.com/forum/beginner/30644/

  outfile << "\n~~ LINE LENGTH CALCULATIONS ~~" << endl;

  //SUM
  outfile << "Sum: " << lineSum << endl;

  //MEAN
  mean = lineSum / lineNumber;
  outfile << "Mean: " << mean << endl;

  //VARIANCE
  while(getline(file, str))
  {
    variance += (str.length() - mean) * (str.length() - mean);
  }
  variance = variance / lineNumber;
  outfile << "Variance: " << variance << endl;

  //STANDARD DEVIATION
  stdDev = sqrt(variance);
  outfile << "Standard Deviation: " << stdDev << endl;
  outfile << "\n";

  //resets variable values for next file
  aCount = 0;
  tCount = 0;
  cCount = 0;
  gCount = 0;

  aaCount, atCount, acCount, agCount = 0;
  taCount, ttCount, tcCount, tgCount = 0;
  caCount, ctCount, ccCount, cgCount = 0;
  gaCount, gtCount, gcCount, ggCount = 0;
}

//Generates a random list of nucleotides based on gaussian distribution of line lengths from given file
void DNA::generateStrings(ofstream &outfile)
{
  outfile << "~~ 1000 RANDOM STRINGS WITH GAUSSIAN DISTRIBUTION ~~" << endl;

  //rand() would yield the same "random" number
  srand(time(NULL)); //https://stackoverflow.com/questions/9459035/why-does-rand-yield-the-same-sequence-of-numbers-on-every-run

  for(int i = 0; i < 1000; ++i)
  {
    double a = 1.0 * rand() / RAND_MAX;
    double b = 1.0 * rand() / RAND_MAX;
    double c = sqrt(-2*log(a)) * cos(2*M_PI*b); //https://stackoverflow.com/questions/1727881/how-to-use-the-pi-constant-in-c
    double d = stdDev*c + mean;

    //If d is negative, turn positive
    if(d < 0)
    {
      d = -1*d;
    }

    for(int k = 0; k < d; ++k)
    {
      double probability = rand() % 100;

      //A
      if (aPercent > probability)
      {
        outfile << "A";
      }

      //T
      else if (aPercent + tPercent > probability)
      {
        outfile << "T";
      }

      //C
      else if (aPercent + tPercent + cPercent > probability)
      {
        outfile << "C";
      }

      //G
      else
      {
        outfile << "G";
      }
    }
    outfile << "\n";
  }

  //resets variable values for next file
  mean = 0;
  variance = 0;
  stdDev = 0;
  aPercent = 0;
  tPercent = 0;
  cPercent = 0;
  gPercent = 0;
}
