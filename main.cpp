#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  vector<long long int> nums;
  bool pCurr, pPrev;
  long long int n, controlDigit = 0, st = 0, dr = 0;
  int c, pDifLen = 0, pDifMaxLen = 0, pDifCount = 0;
  string temp;
  fstream input;

  input.open("pdif.in", ios::in);
  if (!input.is_open()) {
    return -1;
  }

  getline(input, temp);
  char * firstLine = strtok(&temp[0], " ");
  for (int i = 0; firstLine != NULL; i++) {
    i == 0 ? n = atoi(firstLine) : c = atoi(firstLine); 
    firstLine = strtok(NULL, " ");
  }

  getline(input, temp);
  char * secondLine = strtok(&temp[0], " ");
  for (int i = 0; secondLine != NULL; i++) {
    nums.push_back(atoi(secondLine));
    secondLine = strtok(NULL, " ");
  }
  input.close();

  for (int i = 0; i < nums.size(); i++) {
    while (nums[i] > 0) {
      controlDigit += nums[i]%10;
      nums[i] /= 10;
    }
    nums[i] = controlDigit;
    controlDigit = 0;
    if (nums[i] > 10)
      i--;
  }

  nums[0]%2 == 0 ? pPrev = 0 : pPrev = 1;
  nums[1]%2 == 0 ? pCurr = 0 : pCurr = 1;

  for (int i = 1; i < nums.size(); i++) {
    if(pCurr != pPrev) {
      
      if (pDifCount == 0)
        pDifCount++;
      pDifLen++;
      
      if (pDifCount < 2)
        st = i;
      
      if(pDifLen > pDifMaxLen)
        pDifMaxLen = pDifLen;
    } else if (pDifLen == pDifMaxLen) {
      pDifCount++;
    } else {
      pDifLen = 0;
      if (pDifCount < 2) 
        dr = i;
    }

    nums[i]%2 == 0 ? pPrev = 0 : pPrev = 1;
    nums[i + 1]%2 == 0 ? pCurr = 0 : pCurr = 1;
  }

  if (c == 1) {
    cout << pDifMaxLen << endl;
    cout << pDifCount;
  }

  if (c == 2) {
    cout << st << " " << dr;
  }

  // for (int digit : nums) {
  //   cout << digit << endl;
  // }

  return 0;
}