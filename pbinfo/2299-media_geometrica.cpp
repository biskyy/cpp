#include <iostream>
#include <cmath>
#include <utility>
using namespace std;

template<typename ...Args>
constexpr void print(Args&&... args) noexcept
{
   ((std::cout << std::forward<Args>(args) << " "), ...);
}

double multiply(double number, int n) {
    double ans = 1.0;
    for(int i = 1;i<=n;i++) {
        ans = ans * number;
    }
    return ans; 
}

// function using binary search to find the nth root of given number. n=root, m=number
// https://takeuforward.org/data-structure/nth-root-of-a-number-using-binary-search/
void getNthRoot(int n, int m) {
    double low = 1;
    double high = m;
    double eps = 1e-7; 
    
    while((high - low) > eps) {
        double mid = (low + high) / 2.0; 
        if(multiply(mid, n) < m) {
            low = mid; 
        }
        else {
            high = mid; 
        }
    }
    
    cout <<n<<"th root of "<<m<<" is "<<low<<endl; 
    
}

int main(){
    
    int n, p=1;

    print("n="); cin>>n;

    if(n<1 || n>10) {
        print("n este invalid");
        return 0;
    }

    int numbers[n];

    for (int i = 0; i < n; i++){
        cin>>numbers[i];
        if(numbers[i]<1 || numbers[i]>50) {
            print("numarul introdus este invalid");
            return 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        p=p*numbers[i];
    }
    
    getNthRoot(n, p);

    return 0;
}