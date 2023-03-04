#include <iostream>
#include <fstream>
#include "../include/print.h"
#include <string>

using namespace std;

int main(){
  
  fstream myFile;

  myFile.open("biskyy.txt", ios::out); // opens the file in write mode; will create if it doesnt exist

  if (myFile.is_open()) {
    myFile << "Hi\n";
    myFile << "second line?"; // to write on the next line use \n on the previous line;
    myFile.close();
  }

  myFile.open("biskyy.txt", ios::app); // opens the file in append mode

  if (myFile.is_open()) {
    myFile << endl << 1;
    myFile.close();
  }

  myFile.open("biskyy.txt", ios::in);
  if(myFile.is_open()) {
    string line;
    while(getline(myFile, line)) {
      // it reads from the file and then it stores in the line variable
      // while there are lines to be read the while loop will continue
      // getline is a function from the string library!
      if (line == "Hi")
      cout << line << endl;
    }
    myFile.close(); // make sure to close the file afterwards
  }

  return 0;
}
