#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793238462
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" = "; print(x); cerr << endl;
#else
#define debug(x);
#endif
#define mod int(1e9+7)
typedef long long ll;
//print statements
void print(ll x) {cerr<<x;}
void print(int x){cerr<<x;}
void print(string x){cerr<<x;}
void print(char x){cerr<<x;}
void print(double x){cerr<<x;}
//templates for print statements
template<class T,class V> void print(pair<T,V> p);
template<class T> void print(set<T> v);
template<class T> void print(vector<T> v);
template<class T,class V> void print(map<T,V> v);
template<class T> void print(multiset<T> v);
//template code for debugging
template<class T,class V> void print(pair<T,V> p) { cerr<<"{"; print(p.first); cerr<<" , "; print(p.second);cerr<<"}";}
template <class T> void print(vector <T> v) {cerr << "[ "; for (T i : v) {print(i); cerr << " ";} cerr << "]";}
template <class T> void print(set <T> v) {cerr << "[ "; for (T i : v) {print(i); cerr << " ";} cerr << "]";}
template <class T> void print(multiset <T> v) {cerr << "[ "; for (T i : v) {print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void print(map <T, V> v) {cerr << "[ "; for (auto i : v) {print(i); cerr << " ";} cerr << "]";}

bool ispalindrome(string s){
	int si=0;
	int ei=s.length()-1;
	while(si<ei){
		if(s[si]!=s[ei]){
			return false;
		}
		si++;
		ei--;
}
return true;
}

int factorial(int n){
	int fact=1;
	for(int i=1;i<=n;++i){
		fact=fact*i;
	}
return fact;
}
int getdecimal(int n){
	int decimal=0;
	int e=0;
	while(n>0){
		int d=n%10;
		debug(d)
		decimal+=d*pow(2,e);
		debug(decimal)
		e++;
		debug(e)
		n=n/10;
		debug(n)
	}
	return decimal;
}
int getbinary(int n){
	int binary=0;
	int e=0;
	while(n>0){
		int d=n%2;
		debug(d);
		binary+=d*pow(10,e);
		debug(binary)
		e++;
		n/=2;

	}
	return binary;
}

bool ispowerof2(int n){
	int cnt=0;
	while(n>0){
		cnt+=(n&1);
		debug(cnt)
		n>>=1;
	}
	if(cnt==1) return true;
	else return false;
}
//Learning Recursion

void printhw(){
	cout<<"HELLO WORLD!"<<endl;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("error.txt","w",stderr);
#endif

int t;
cin>>t;
cout<<t;

}