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

int a,b,c;
cin>>a>>b>>c;
if(a>b && a>c){
    cout<<a<<endl;
}
else if(b>a && b>c){
    cout<<b<<endl;
}
else{
    cout<<c<<endl;
}
}
