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

char a;
cin>>a;
if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u'){
cout<<"Character is a Vowel"<<endl;
}
else{
    cout<<"Its a Consonant"<<endl;
}
}
