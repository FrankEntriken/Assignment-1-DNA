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

using namespace std;

int main()
{
  //so that user can process multiple files
  while(true)
  {
    string userFile;
    cout << "Enter the name of the file: ";
    cin >> userFile;

    ofstream outFile("FrankEntriken.txt");
    outFile << "Frank Entriken \n2298368 \nentriken@chapman.edu \nCPSC 350 \nAssignment 1 \n";

    ifstream inputFile;
    inputFile.open(userFile);

    if(!inputFile)
    {
      cout << "Unable to find file" << endl;
      exit(1);
    }

    DNA a;
    a.lineStatistic(inputFile, outFile);
    a.generateStrings(outFile);
    outFile.close();
    inputFile.close();

    cout << "File FrankEntriken.txt has been made." << endl;

    //ask user if they would like to process another file
    string choice;
    cout << "\nWould you like to process another file? (y/n) ";
    cin >> choice;

    if(choice == "y")
    {
      continue;
    }

    else if(choice == "n")
    {
      cout << "Program Terminated" << endl;
      exit(1);
    }

    else
    {
      cout << "Input not valid" << endl;
      exit(1);
    }
  }
}
