#include <bits/stdc++.h>
using namespace std;
#include<math.h>
#include <string>
#define ll long long
#define ONLiNE_JUDGE                  \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);


int main(){
ONLiNE_JUDGE
int n;
cin>>n;
for(int row=1;row<=n;++row){
    int totalcol;
    if(row>n){
        totalcol=2*n-row;
    }
    else{
        totalcol=row;
    }
    int spaces=n-totalcol;
    for(int s=1;s<=spaces;++s){
        cout<<" ";
    }
    for(int j=0;j<totalcol;++j){
        cout<<"* ";
    }
    cout<<endl;
}
}



