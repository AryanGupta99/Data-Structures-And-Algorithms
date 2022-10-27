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


//stack has only limited number of functionality in it.
// you cannot directly print stack in cpp but it can be printed in java.
//there are two ways to implement stack 1. arrays 2. linked list.
int n=100;
class sstack{
int *arr;
int top;
public:
	//constructor of stack class.
	sstack(){
		arr=new int[n];
		top=-1;

	}
//major operations of stack.
void push(int x){
	if(top==n-1){
		cout<<"stack overflow"<<endl;
		cout<<"memory will not be able to assigned"<<endl;
		return;
	}
	else{
		top++;
		arr[top]=x;
	}
}
void pop(){
	if(top==-1){
		cout<<"stack is empty"<<endl;
		cout<<"There are no element to delete"<<endl;
		return;
	}
	else{
		top--;
	}
}
int Top(){
	if(top==-1){
		cout<<"stack is empty"<<endl;
		cout<<"no element present"<<endl;
		return -1;
	}
	return arr[top];
}
bool isempty(){
	return top==-1;
}
void printstack(){
	for(int i =0;i<4 ;++i){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
};
//duplicate elements or brackets
//approach -> the idea is to push all the elements into the character stack.
// start popping the elements once you find the closing bracket Bracket and keep popping till you find the opening bracker.
// if you find opening bracket without popping anything //.
//i.e means that pair of bracket are duplicate as it doesn't Contain Anything of its own.

bool DuplicateBracket(string a){
	stack<char> s;
	for(int i=0;i<a.size();++i){
		if(a[i]==')'){
			if(s.top()=='('){
				cout<<"duplicate brackets found as it doesn't containg its own contents"<<endl;
				return true;
			}
			else{
				while(s.top()!='('){
					s.pop();
				}
				s.pop();
			}
		}
		else{
			s.push(a[i]);
		}
}
cout<<"string has reached end and doesn't contain duplicate bracket"<<endl;
return false;
}
//balanced brackets or valid brackets or valid string expressions
//approach -> the idea is similar to above  duplicate brackets question
// push each character into the stack and start popping it until you find the same opening bracket
// if the stack is not empty at the end of string then it is not balanced
// if the popped bracket is not similar to the last popped bracket then also it is not balanced
//handleclosing function will handle the similarity of code;
bool handleclosing(stack<char> b,char c){
	if(b.size()==0){
				return false;
			}
			else if(b.top()!=c){
				return false;
			}
			else{
				b.pop();
				return true;
			}
		}		
bool BalanceBracket(string a){
	stack<char> b;
	for(int i=0;i<a.size();++i){
		if(a[i]=='(' || a[i]=='{' || a[i]=='['){
			b.push(a[i]);
		}
		else if(a[i]==')'){
			//handle closing function will handle the opening and closeing of bracket
			bool val = handleclosing(b,'(');
			if(val==false){
				return val;
			}
		}
		else if(a[i]=='}'){
				bool val=handleclosing(b,'{');
				if(val==false){
					return val;
				}
		}
		else if(a[i]==']'){
			bool val =handleclosing(b,'[');
			if(val==false){
				return val;
			}
		}
		else{
			
		}
	}
	if(b.size()==0) {
		return true;
	}
	else{
		return false;
	}
	
}

//implementing two stacks in a single array.
//the idea is to keep track of two tops and their values.
// make one stack array . and make two push and pop functions.
// 
void twostack(int arr[],int n){
	int stack[n];
	int top1=-1;
	int mid=n/2;
	int top2=mid-1;
	//u can do it 
}
//sort stack (easy-medium gfg)
//the idea is to pop the elements of stack and push it to new stack by comparing the elements.
//insert at proper postion in the stack is the real deal in this question. 
void insert_in_stack(stack<int> s,int a){
	if(s.empty() || a>s.top()){
		s.push(a);
		return;
	}
	int y=s.top();
	s.pop();
	insert_in_stack(s,a);
	s.push(y);
}
void sortStack(stack<int> s){
if(s.empty()){
return;
}
int a=s.top();
s.pop();
sortStack(s);
insert_in_stack(s,a);
}

//reverse a string using stack.
// the idea is simple just keep pushing the characters on the top of stack.
// automatically the last character will come at the top of stack.
// keep popping and keep printing the characters it will be reversed.

void stringrev(string s,stack<char> st){
	for(int i=0;i<s.size();++i){
		st.push(s[i]);
	}
	while(!st.empty()){
		cout<<st.top()<<"";
		st.pop();
	}
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("error.txt","w",stderr);
#endif

string a;
cin>>a;
stack<char>st;
stringrev(a,st);
}