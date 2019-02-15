/*
Frank Entriken
2298368
entriken@chapman.edu
CPSC 350
Assignment 1: DNA
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

class DNA
{
  private:
    double mean;
    double variance;
    double stdDev;
    double aPercent;
    double tPercent;
    double cPercent;
    double gPercent;

  public: //everything under this is public
    DNA(); //constructor
    ~DNA(); //destructor -- deallocate memory back to system
    void generateStrings(ofstream &file); //function to generate 1000 random strings based on gaussian distribution
    void lineStatistic(ifstream &file, ofstream &outfile); //function to find statistics of input file
};
