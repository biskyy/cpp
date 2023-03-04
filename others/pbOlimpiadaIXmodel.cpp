#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

  int n, k, p = 0;
  vector<int> factPrimN, factPrimK, copieK;
  cin >> n;
  cin >> k;
  int copieI;
  for (int i = 2; i <= n; i++) { 
    copieI = i;
    for (int j = 2; i != 1; j++) {
      if (i % j == 0) {
        factPrimN.push_back(j);
        i /= j;
        j = 1;
      }
    }
    i=copieI;
  }

  for (int i = 2; i <= k; i++) {
    if (k % i == 0) {
      factPrimK.push_back(i);
      k /= i;
      i = 1;
    }
  }

  sort(factPrimN.begin(), factPrimN.end());
  sort(factPrimK.begin(), factPrimK.end());

  copieK = factPrimK;

  int st = 0, dr = factPrimN.size(), mij = (st + dr) / 2;

  while (st <= dr) {
    if (factPrimK[0] < factPrimN[mij]) {
      dr--;
    } else {
      st++;
    }
    if (factPrimK[0] == factPrimN[st]) {
      factPrimK.erase(factPrimK.begin());
      factPrimN.erase(factPrimN.begin() + st);
    }
    if (factPrimK.size() == 0) {
      p++;
      factPrimK = copieK;
      st = 0;
      dr = factPrimN.size();
      mij = (st + dr) / 2;
    }
    mij = (st + dr) / 2;
  }
  
  cout << p;

  return 0;
}
