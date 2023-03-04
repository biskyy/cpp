#include <iostream>
#include <vector>

using namespace std;

int main(){
  
  vector<int> topPlr, plr;
  int n, r, temp;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    topPlr.push_back(temp);
  }
  cin >> r;
  for (int i = 0; i < r; i++) {
    cin >> temp;
    plr.push_back(temp);
  }

  for(unsigned int i = 0; i < topPlr.size(); i++)
    if(topPlr[i] == topPlr[i + 1]) topPlr.erase(topPlr.begin() + i);

  int st = 0, dr = topPlr.size();
  int mij = (st + dr) / 2;

  for (int val : plr){
    while (st < dr) {
      if (val < topPlr[mij]) st++;
      else dr--;
      mij = (st + dr) / 2;
    }
    cout << st + 1 << endl;
    st = 0;
    dr = topPlr.size();
  }

  return 0;
}
