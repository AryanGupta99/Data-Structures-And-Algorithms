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
int n,temp,sum=0,digit=0,last=0;
cin>>n;
temp=n;
while(temp>0){
    temp=temp/10;
    digit++;
}
temp=n;
while(temp>0){
    last=temp%10;
    sum=sum+(pow(last,digit));
    temp=temp/10;
}
if(n==sum)
cout<<"it is a armstrong number"<<endl;
else 
cout<<"Not a armstrong number"<<endl;
}
