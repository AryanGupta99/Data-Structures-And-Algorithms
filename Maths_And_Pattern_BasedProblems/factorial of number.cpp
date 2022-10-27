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
int n;
cin>>n;
int fact=1;
if(n==0){
    return 1;
}
if(n==1){
    return 1;
}
for(int i=2;i<=n;++i){
fact=fact*i;
}
cout<<"The Factorial is = "<<fact<<endl;
}