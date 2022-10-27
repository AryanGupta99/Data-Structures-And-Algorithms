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

for(int i=1;i<=10;++i){
    cout<< n <<" X "<< i << " = " << n*i<<endl;
}
}