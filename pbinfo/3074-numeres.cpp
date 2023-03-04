#include<iostream>
#include <utility>  // std::forward
using namespace std;

template<typename ...Args>
constexpr void print(Args&&... args) noexcept
{
   ((std::cout << std::forward<Args>(args) << " "), ...);
}

void newLine() {
    cout<<endl;
}

// function that counts the digits of given number
int digitCount(int number) {
   int count = 0;
   while(number != 0) {
      number = number / 10;
      count++;
   }
   return count;
}

// function that calculates the sum of the digits of a given number
int digitSum(int number) {
    int sum=0;
    while (number>0) {
        sum+=number%10;
        number/=10;
    }
    return sum;
}

int main(){

    int n, s, copieS, contorS=0, contorNr=0;

    print("n="); cin>>n;
    print("s="); cin>>s;

    copieS=s;

    if(n>7 || n<1){
        print("n este invalid");
        return 0;
    }
    else if (s>63 || s<1){
        print("s este invalid");
        return 0;
    }

    while (digitCount(contorS*10+s)<=n)
    {
        if(digitCount(contorS*10+s)==n && digitSum(contorS*10+s)==copieS){
            print(contorS*10+s);
            contorNr++;
        }
        contorS++;
        s--;
    }
    print("Nr total de numere afisate:", contorNr);

    return 0;
}