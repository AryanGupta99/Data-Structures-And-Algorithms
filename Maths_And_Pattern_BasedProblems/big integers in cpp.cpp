#include <bits/stdc++.h>
using namespace std;
#include<math.h>
#include <string>
#define ll long long
#define ONLiNE_JUDGE                  \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);






vector<ll> add(vector<ll>x,vector<ll>y){
    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());
    ll len=min(x.size(),y.size());
    ll carry=0;
    vector<ll> ans;
    for(int i=0;i<len;++i){
        ll val=x[i]+y[i]+carry;
        carry=val/10;
        ans.push_back(val%10);
    }
    if(x.size()>len){
        for(int i=len;i<x.size();++i){
             ll val=x[i]+carry;
        carry=val/10;
        ans.push_back(val%10);
        }
    }
    if(y.size()>len){
        for(int i=len;i<y.size();++i){
         ll val=y[i]+carry;
        carry=val/10;
        ans.push_back(val%10);
    }
    }
    while(carry){
      ans.push_back(carry%10);
      carry=carry/10;
    }
    reverse(ans.begin(),ans.end());
    return ans; 
}

vector<ll> divisionby2(vector<ll> x){
    vector<ll> ans;
    ll rem=0;
    for(int i=0;i<x.size();++i){
        if(rem){
            rem=rem*10+x[i];
            ans.push_back(rem/2);
            rem=rem%2;
        }
        else{
            if(x[i]<2){
                rem+=x[i];
                ans.push_back(0);
            }
            else{
            rem=x[i]%2;
            ans.push_back(x[i]/2);
        }
        }
    }
    vector<ll> result;
    int i=0;
    while(ans[i]==0) i++;
        for(;i<ans.size();++i){
        result.push_back(ans[i]);
        }

    return result;
}

vector<ll> subtraction(vector<ll> x ,vector<ll> y){
    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());
    vector<ll> ans;
    ll borrow=0;
    int len=y.size();
    for(int i=0;i<len;++i){
         if(x[i]<y[i]){
              x[i+1]--;
             ans.push_back(x[i]+10-y[i]);
         }
         else{
             ans.push_back(x[i]-y[i]);
         }
    }
    if(x.size()>len){
        for(int i=len;i<x.size();++i){
            if(x[i]<0){
            x[i+1]--;
            ans.push_back(10*x[i]);
            }
            else{
                ans.push_back(x[i]);
            }
        }
    }
    reverse(ans.begin(),ans.end());
     vector<ll> result;
    int i=0;
    while(ans[i]==0){
        i++;
        for(;i<ans.size();++i){
    result.push_back(ans[i]);
        }
    }

    return result;
}

void multiply(vector<ll> &ans, int num){
int carry=0;
for(int i=0;i<ans.size();++i){
ll val=ans[i]*num+carry;
carry=val/10;
ans[i]=val%10;
}
while(carry){
    ans.push_back(carry%10);
    carry=carry/10;
}
}

void factorial(int n){
vector<ll> ans;
ans.push_back(1);
for(int i=2;i<=n;i++){
    multiply(ans,i);
}
reverse(ans.begin(),ans.end());
for(int i=0;i<ans.size();++i){
    cout<<ans[i]<<"";
}
cout<<endl;
}
int main() {
ONLiNE_JUDGE
int t;
cin>>t;
while(t--){
    string a,b;
    cin>>a>>b;
    vector<ll>c;
    vector<ll>d;
    for(int i=0;i<a.size();++i){
    c.push_back(a[i]-'0');
    }
    for(int i=0;i<b.size();++i){
    d.push_back(b[i]-'0');
    }
    vector<ll> temp_sum=add(c,d);
   vector<ll>div=divisionby2(temp_sum);

   vector<ll> diff=subtraction(c,div);
    for(int i=0;i<div.size();++i){
        cout<<div[i]<<"";

    }
    cout<<endl;
    for(int i=0;i<diff.size();++i){
        cout<<diff[i]<<"";
    }
int n;
cin>>n;
factorial(n);
}
}



