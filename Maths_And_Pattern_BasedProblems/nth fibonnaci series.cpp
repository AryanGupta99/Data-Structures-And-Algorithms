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
int a=0;
int b=1;
int next_term=a+b;
cout<<a<<endl;
cout<<b<<endl;
for(int i=3;i<=n;++i){
    cout<<next_term<<endl;
    a=b;
    b=next_term;
    next_term=a+b;
}
}