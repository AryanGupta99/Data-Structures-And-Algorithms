#include <bits/stdc++.h>
using namespace std;
#include<math.h>
#include <string>
#define ll long long
#define ONLINE_JUDGE                  \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);


int main()
{
ONLINE_JUDGE
int i,j,n,m;
cin>>n>>m;
for (i = 1; i <= n; i++)
{
for (j = 1; j <= m; j++)
{
if (i==1 || i==n || j==1 || j==m)
cout <<"*";
else
cout <<" ";
}
cout << endl;
}
}