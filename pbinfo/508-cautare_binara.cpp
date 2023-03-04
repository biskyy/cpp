#include <iostream>
#include <vector>

using namespace std;

int main() {

  vector<int> x = {1, 2, 5, 6, 9, 10, 14};
  vector<int> y = {8, 14, 9, 14, 16, 15, 4, 2};
    
  int low = 0;
  int high = x.size();
  int mid = (high + low) / 2;

  for (int i = 0; i<y.size(); i++) {
    while (low <= high) {
      if (y[i] == x[mid]) {
        cout<<"1 ";
        break;
      }
      if (y[i] < x[mid]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
      mid = (high + low) / 2;
    }
 
    if (y[i] != x[mid]) cout<<"0 ";
    low = 0;
    high = x.size();

  }

  return 0;
}