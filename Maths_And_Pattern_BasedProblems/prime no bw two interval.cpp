#include <bits/stdc++.h>
using namespace std;
#include<math.h>
#include <string>
#define ll long long
#define ONLiNE_JUDGE                  \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int checkprimeNumber(int n){
    bool isprime=true;
    if(n==0 || n==1){
        return false;
    }
    else{
        for(int j=2;j<=n/2;++j){
            if(n%j==0)
            isprime=false;
            break;
        }
    }
    return isprime;
}


int main(){
ONLiNE_JUDGE
int n1, n2;
bool flag;
cout << "Enter two positive integers: "<<endl;
cin >> n1 >> n2;
// swapping n1 and n2 if n1 is greater than n2
if (n1 > n2) {
n2 = n1 + n2;
n1 = n2 - n1;
n2 = n2 - n1;
}
cout << "Prime numbers between " << n1 << " and " << n2 << " are: "<<endl;
for(int i = n1+1; i < n2; ++i) {
// If i is a prime number, flag will be equal to 1
flag = checkprimeNumber(i);
if(flag)
cout << i << " ";
}
return 0;
}





