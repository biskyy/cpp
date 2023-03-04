#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

int main(){

  fstream fileIn;
  int nrCerinta, nrLini, nrColoane, nrMine, minCtrMine = 0, maxCtrMine = 0, maxLinie;
  fileIn.open("deminare.in", ios::in);

  if(!fileIn.is_open()) {
    return 1;
  }
  string temp;
  getline(fileIn, temp); // line 1
  nrCerinta = atoi(temp.c_str()); // se citeste V

  getline (fileIn, temp); // line 2
  char * pch = strtok(&temp[0], " ");
  for (int i = 0; pch != NULL; i++) {
    i == 0 ? nrLini = atoi(pch): nrColoane = atoi(pch); // se citeste nr de lini si coloane
    pch = strtok(NULL, " ");
  }

  getline (fileIn, temp); // line 3
  nrMine = atoi(temp.c_str()); // se citeste nr de mine

  int matrice[nrLini][nrColoane];

  for (int i = 0; i < nrLini; i++)
    for(int j = 0; j < nrColoane; j++)
      matrice[i][j] = 0;

  int tempX, tempY;
  while(getline(fileIn, temp)){
    char * pchTemp = strtok(&temp[0], " ");
    for (int i = 0; pchTemp != NULL; i++) {
      i == 0 ? tempX = atoi(pchTemp) : tempY = atoi(pchTemp); // se citeste nr de lini si coloane
      pchTemp = strtok(NULL, " ");
    }
    matrice[tempX - 1][tempY - 1] = 1;

  }

  for (int i = 0; i < nrLini; i++){
    for(int j = 0; j < nrColoane; j++){
      cout << matrice[i][j] << " ";
    }
    cout << endl;
  }
  
  fileIn.close();

  if (nrCerinta == 1) {
    for (int i = 0; i < nrLini; i++) {
      for (int j = 0; j < nrColoane; j++) {
        if (matrice[i][j] == 1)
          minCtrMine++;
      }
      if (minCtrMine > maxCtrMine) {
        maxLinie = i;
        maxCtrMine = minCtrMine;
      }
      minCtrMine = 0;
    }
  }
  maxLinie++;

  fstream fileOut;
  fileOut.open("deminare.out", ios::out);
  fileOut << maxLinie;
  fileOut.close();

  return 0;
}