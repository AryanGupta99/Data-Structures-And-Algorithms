#include <bits/stdc++.h>
using namespace std;
#include<math.h>
#include <string>
#define ll long long
#define ONLiNE_JUDGE                  \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);


int main() {
ONLiNE_JUDGE

int n;
cin>>n;
for(int row=1;row<=n;++row){

    int space=n-row;
    for(int k=1;k<=space;++k){
        cout<<" ";
    }
    for(int col=1;col<=2*row-1;++col){
        if(col==1 || col==2*row-1 || row==n){
            cout<<"*";
        }
        else{
            cout<<" ";
        }
    }
    cout<<endl;
}
}