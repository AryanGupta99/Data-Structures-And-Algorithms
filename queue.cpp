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

//implementing queue using arrays.
//it also uses similar implementation but just the difference is that in stack insertion and deletion.
//both were happening at the top only
// but in queue insertion and deletion happend at rear and front end.
#define n 5 
class myQClass{
private:
	int items[n];
	int front,rear;
public:
	myQClass(){
			front=-1;
		rear=-1;
	}

void qpush(int val){
	if(rear==n-1){
		cout<<"queue is emtpy"<<endl;
		return;
	}
	if(front==-1){
		front++;
	}
	rear++;
	items[rear]=val;
}
void qpop(){
	if(front==-1){
		cout<<"queue is emtpy"<<endl;
		return;
	}
	int element=items[front];
	if(front==rear){
		front=-1;
		rear=-1;
	}
	else{
		front++;
	}
}
bool isfull(){
	if(front==0 && rear==n-1){
		return true;
	}
	else{
		return false;
	}
}
bool isempty(){
	if(front==-1){
		return true;
	}
	else{
		return false;
	}
}

void qdisplay(){
	for(int i=front;i<=rear;++i){
		cout<<items[i]<<" ";
	}
}
};

//queue using linked list.
class linknode
{
public:
	int  data;
    linknode *next;

linknode(int val){
	data=val;
	next=NULL;
}
};	
class qlink{
linknode * front;
linknode * rear;

public: 
	qlink(){
		front=NULL;
		rear=NULL;
	}

	void lpush(int val){
	
	linknode *newnode=new linknode(val);
	if(front==NULL && rear==NULL){
		front=rear=newnode;
	}
	else{
		rear->next=newnode;
		rear=newnode;
	}
}
void lpop(){
	if(front==NULL){
		cout<<"quueue is emtpy"<<endl;
		return;
	}
	qlink *todelete;
	front=front->next;
	free(todelete);
	}

	int ltop(){
	if(front==NULL){
		return -1;
	}
	return rear->data;
}

bool lemtpy(){
	if(front==NULL){
		return true;
	}
return false;
}

void ldisplay(){
	if(front==NULL && rear==NULL){
		cout<<"your queue is empty"<<endl;
		return;
	}

	while(front->next!=NULL){
		cout<<front->data<<" ";
		front=front->next;
	}
}
};
//i will implement these questions after doing all concepts.
//queue using two stacks (imp) 
// stack using two queue (imp)

//question -> implement queue using single pointer/counter;
//approach is simple that insertion will happen at one step in O(1);
//removal will happen in O(n);
// just shif all the elements to the left by 1 the first element will get removed.
 
 int removalinqueue(){
 	if(isempty()){
 		return 0;
 	}
 	//store the removed element from array.
 	int removed=a[0];
 	for(int i=1;i<a.length();++i){
 		data[i-1]=data[i];
 	}
 	a.length()--;
 	return removed;
 }

 //question => circular queue.
 //the different thing is just the insertion and deletion part.
 //when element gets deleted front pointer increases.
 //when element gets inserted end pointer gets increases.
//for insertion in circular see below
void insertcircular(int item){
	if(isfull()){
		return false;
	}
	a[end++]=item;
	end=end%a.length();
	a.length()++;
}

//for deletion in ciruclar queue.
int removecircular(){
	if(isempty()){
		return false;
	}
	int removed=a[front];
	front++;
	front=front%a.length();
	size--;
	return removed;
}

//for front element
int showfront(){
	if(isempty()){
		return false;
	}
	return a[0];
}

//for display circular queue.
//display is also crucial 
//try to print queue first the remove element then again print it.
void displaycircular(){
	if(isempty()){
		cout<<"circular queue is empty"<<endl;
		return;
	}
	int i=front;
	do{
		cout<<a[i]<<endl;
		i++;
		i%=a.length();
	}
	while(i!=end){
		cout<<"its the end"<<endl;
	}
}

//dynamic circular queue is similar to dyanmic stack and vector
// it is just goint to create temp queue and copy the elements and double the size.
//for(int i=0;i<a.length();++i){
	
int main(){
#ifndef ONLINE_JUDGE
	freopen("error.txt","w",stderr);
#endif

cout<<"Welcome Back"<<endl;

}