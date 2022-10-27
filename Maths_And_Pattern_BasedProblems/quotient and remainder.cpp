#include <bits/stdc++.h>
using namespace std;
#include <string>
#define ll long long
#define ONLINE_JUDGE                  \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int main()
{
ONLINE_JUDGE

int divisor,dividend,quotiont,remainder;
cin>>divisor>>dividend;
quotiont = divisor / dividend;
remainder = dividend % divisor;
cout<<"The quotiont is = " << quotiont<<endl;
cout<<"The remainder is = " << remainder<<endl;
}
