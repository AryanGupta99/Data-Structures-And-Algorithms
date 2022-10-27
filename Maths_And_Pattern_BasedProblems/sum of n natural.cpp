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

int sum=0;
for(int i=0;i<=n;++i){
    sum+=i;
}

cout<<"The Sum is = "<<sum<<endl;
}