#include <bits/stdc++.h>
using namespace std;
#include<math.h>
#include <string>
#define ll long long
#define ONLiNE_JUDGE                  \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);


int gcd(int n,int m);
int main() {
ONLiNE_JUDGE
int n,m;
cin>>n>>m;
cout << "Enter two positive integer: "<<endl;
cout << "gcd "<< " = " << gcd(n,m);
return 0;
}
int gcd(int n, int m)
{
if(m!=0){
    return gcd(m,n%m);
}
else{
    return n;
}
}