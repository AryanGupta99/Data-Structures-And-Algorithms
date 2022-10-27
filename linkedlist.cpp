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


//linked list implementation.

class node{
public:
	int data;
	node* next;

	node(int val){
		data=val;
		next=NULL;
	}
};
//insert at head of linked list

void insertathead(node* & head,int val){
node* newnode=new node(val);
// if(head==NULL){
// 	head=newnode;
// }
newnode->next=head;
head=newnode;

}

//insert at last position of linked list

void insertAtTail(node* &tail,int val){
node *temp = new node(val);
tail->next=temp;
tail=tail->next;
}

//insert at particular position

void insertatposition(node* &head,node* &tail,int position,int val){
	if(position==1){
		insertathead(head,val);
		return;
	}
	node *temp=head;
	int cnt=1;

	while(cnt<position-1){
		temp=temp->next;
		cnt++;
	}
	//if you have reached end i.e at tail position just call the insertattail function
	if(temp->next==NULL){
		insertAtTail(tail,val);
		return;
	}

	//create a node to insert
	node* nodetoinsert=new node(val);
	nodetoinsert->next=temp->next;
	temp->next=nodetoinsert;
}

//after academy notes way
//insert after given node or in middle
// void insertatposition(node* &head,node prevNode,int item){
// 	node* newnode= new node(item);
// 	if(head==NULL){
// 		head=newnode;
// 	}
// 	newnode->prevNode->next;
// 	prevNode->next=newnode;
// }
//deletion in Linked List
//delete node by value
//delete node by position
void deleteinlinkedlist(node* &head,int position){

	if(position==1){
		node* temp=head;
		head=head->next;
		delete temp;
	}
	node* temp=head;
	int cnt=1;
	while(cnt<position-1){
		temp=temp->next;
		cnt++;
	}
	temp->next=temp->next->next;

}

//searchig in a linked list

bool searchLL(node* & head, int val)
{
    node* temp = head; // creating a temp variable pointing to the head of the linked list
    while( temp != NULL) // traversing the list
    {
        if( temp->data == val )
            return true;
        temp = temp->next;
    }
    return false;
}
//to update node's value in a linked list

void updateLL(node* & head, int val, int newVal)
{
    node* temp = head;
    while(temp != NULL)
    {
        if( temp->data == val)
        {
            temp->data = newVal;
            return;
        }
        temp = temp->next;
    }
}
// display a linked list.
void displaylinkedlist(node* head){
	node* temp=head;
while(temp!=NULL){
	cout<<temp->data<<"->";
	temp=temp->next;
}
cout<<"END"<<endl;
}

//Doubly Linked List

class doublyll{
public:
int data;
doublyll* next;
doublyll* prev;
//constructor
doublyll(int val){
data=val;
next=NULL;
prev=NULL;
}
};
//display a doubly linked list
void doublydisplay(doublyll* &head){
	doublyll* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"END"<<endl;
}
// //insertion at head;
void doublyinsertathead(doublyll* &head,int val){
	doublyll* newnode=new doublyll(val);
	if(head==NULL){
		head=newnode;
	}
	
	newnode->next=head;
	head->prev=newnode;
	head=newnode;
}

// //insertion at tail;
void doublyinsertattail(doublyll* &tail,int val){
	doublyll* newnode=new doublyll(val);
	tail->next=newnode;
	newnode->prev=tail;
	tail=newnode;

}
//insert in middle position
void doublyinsertatposition(doublyll* &head,doublyll* &tail,int position,int val){
if(position==1){
	doublyinsertathead(head,val);
}
doublyll* temp=head;
int cnt=1;
while(cnt!=position){
	temp=temp->next;
	cnt++;
}
if(temp->next==NULL){
doublyinsertattail(tail,val);
}

doublyll* newnode = new doublyll(val);
newnode->next=temp->next; 
temp->next->prev=newnode;
temp->next=newnode;
newnode->prev=temp;
}

//deletion in doubly linked list.

void doublylldelete(doublyll* &head,int position){
	if(position==1){
		doublyll* temp=head;
		temp->next->prev=NULL;
		head=temp->next;
		temp->next=NULL;
		delete temp;
	}
	doublyll* curr=head;
	doublyll* prev=NULL;
	int cnt=1;
	while(cnt<position-1){
		prev=curr;
		curr=curr->next;
		cnt++;
	}
	curr->prev=NULL;
	prev->next=curr->next;
	curr->next=NULL; 
	delete curr;
	
}

//Reverse a linked list 
//types -> display the content of linked list data wise can by done by array way.
//2.pointer wise reversal is difficult.
//for doing this pointers reversal just think of the possible ways for changing the pointers
// take two pointer to achieve this reversal
//take extra pointer for easy of the task
void reversell(node* &head,node* &tail){
node* curr=head;
node* prev=NULL;
while(curr!=NULL){
	node* next=curr->next;
	curr->next=prev;
	prev=curr;
	curr=next;
}
swap(head,tail);
}

//question -> kth node from the end of the linked list.
//aryan approach was to run the for loop (size-k) times to get the value from the last point
//but we have to do it without help of size of linked list.
//pepcoding approach.-> take two pointer slow and fast . 2.move fast pointer k step away from slow.
//3. now keep increaseing till fast reaches the null then slow will be your answer.
  int kthFromEnd(node* &head,int k) {
    
    node* slow=head;
    node* fast=head;
    int cnt=0;
    while(cnt<k){
    	cnt++;
    	fast=fast->next;
    }

    while(fast!=NULL){
    	fast=fast->next;
    	slow=slow->next;
    }
    return slow->data;

  }

  //question -> middle of linked list
  //aryan approach - > just get the (si+ei)/2 and return the node;
  //but we are not alloweed To Use Size Function.
  //maybe it can done by two pointer approach
  //pep approach is run slow and fast pointer by one and two step respectively.when fast reach end i.e ans.
  //in case of even linked list make conditin when fast->next->next ==null then stop
  int middleoflinkedlist(node* &head) {
  	node* slow=head;
  	node* fast=head;
  	while(fast->next!=NULL and fast->next->next!=NULL){
  		slow=slow->next;
  		fast=fast->next->next;
  	}
  	return slow->data;
  }

  //merge two sorted linked list.
  //aryan approach is two use two pointer f.p at first ll and s.p at second ll.
  //keep comparing the values and insert them in their correct position.

//    void mergeTwoSortedLists(node* & head,linkedlist l1, node* head2,linkedlist l2) {
//    int fp=0;
//    int sp=0;
//    while(fp<llsize-1 && sp<llsize-1){
//    	if(fp->data<sp->data){
//    		node* toinsert=new node(fp->data);
//    		insertattail(toinsert);
//    	}
//    	else{
// node* toinsert=new node(fp->data);
//    		insertattail(toinsert);
//    	}
//    }
//    while(fp<llsize-1){
//    	insertattail(tail,fp->data);
//    }
//    while(sp<llsize){
//    	insertattail(tail,sp->data);
//    }
//   } 

//question->merge sort a linked list
 //approach is simple just use the logic of mergetwosortdlinkedlist part.
  //and recursively sort the linked list.

//   linkedlist mergeSort(Node* head, Node* tail ) {
//   //write your code here
//   	if(head==tail){
//   		node* base=new node(head->data);
//   		return base;
//   	}
//   	//this below will keep finding the middle of linked list every time until you get single head or tail.
//   	node* mid=middleoflinkedlist(head,tail);
//   	//first head of linked list just we did in merge sort of array by taking first pointer.
//   	node* firsthead=mergeSort(head,tail);
//   	//second head of linked list just we did in merge sort of array by taking second pointer.
//   	node* secondhead=mergeSort(mid->next,tail);
//   	//finally this will sort the two linked list.
//   	return mergetwosortdlinkedlist(firsthead,secondhead);
 
// 

//question -> remove duplicates from the linked list
//aryan appraach is to keep two pointers within while loop until the next pointer of second is null.
//keep comparing the data values of both the pointers.

void removeduplicates(node* &head){
	node* first=head;
	node*  next_ka_next;

	if(first==NULL){
		cout<<"there is no item present "<<endl;
		return;
	}
		while(first->next!=NULL){
		if(first->data==first->next->data){
			//delete the second node.
			next_ka_next=first->next->next;
			delete first->next;
			first->next=next_ka_next;

		}
		else{
			//only jump if there is no deletion
			first=first->next;
		}
	}
}

//question -> odd even linked list.
//aryan approach-> make two linked list for odd and even linked list and merge them by joining next pointer of odd node to even node.
  // void oddEven() {
  //   linkedlist odd;
  //   linkedlist even;

  //   while (this->size > 0) {
  //     int val = this->getFirst();
  //     this->removeFirst();

//check for even and odd value
  //     if (val % 2 == 0) {
  //       even.addLast(val);
  //     } else {
  //       odd.addLast(val);
  //     }
  //   }
//check for even and odd elements that exist for both of them
  //   if (odd.size > 0 && even.size > 0) {
  //     odd.tail->next = even.head;
//make head and tail at proper postions.
  //     this->head = odd.head;
  //     this->tail = even.tail;
  //     this->size = odd.size + even.size;
  //   }
  //when only odd number of elements are presenet.
  // else if (odd.size > 0) {
  //     this->head = odd.head;
  //     this->tail = odd.tail;
  //     this->size = odd.size;
//when only even number of elements are present.
  //   } else if (even.size > 0) {
  //     this->head = even.head;
  //     this->tail = even.tail;
  //     this->size = even.size;
  //   }
  // }

//question-> reverse a linked list by size k
//aryan approach -> go till k size and then reverse it.
//checks -> if size of linked list is less than k then simply leave it.

void reversebyksize(node* &head,node* &tail,int k){
	// if(k<size of linked list){
	// 	return;
	// }

	for(int i=0;i<k;++i){
		node* curr=head;
		node* prev=NULL;
		while(curr!=NULL){
			node* next=curr->next;
			curr->next=prev;
			prev=curr;
			curr=next;
		}
	}
}

//insertion in linked list using recursion.
//aryan approach - recursively find the index where you want to insert the value.
//then insert it by linking the pointers of the linked list

// void recusivelyinsert(int index,int value){
// node head=insertusingrecursion(mynode,2,2);
// }

// //make a node type return function to use the recursion concept.
// //use this function in the actual function

// node* insertusingrecursion(node* mynode,int index,int value){
// 	if(index==0){
// 		node* newnode=new node(value);
// 		newnode->next=mynode;

// 		return newnode;
// 	}
// 	mynode->next=insertusingrecursion(mynode,index--,value);
// 	return mynode;
// }  

//question -> detect a cycle in the linked list.
//aproach -> take two Pointers and then traverse them using their speed.
//try to check if at some point they are meeting or equal then there is a cycle in ll.
//else there is no cycle in it.

// void hascycle(node* &head){
// 	node* slow=head;
// 	node* fast=head;
// 	int cnt=0;
// 	while(fast!=NULL and fast->next!=NULL){
// 		slow=slow->next;
// 		fast=fast->next->next;
// 		if(slow==fast){
// 			cout<<"Yes it has a cycle"<<endl;
// 			//if you want to find the length of the cycle.
// 			//keep the fast pointer there itself and start moving slow pointer.
// 			//until it again reaches the fast pointer.
// 			//keep counting it.
// 			node* temp=slow;
// 			//use do while loop bcoz loop will not run if you use while loop
// 			do{
// 				temp=temp->next;
// 				cnt++;
// 			}
// 			while(temp!=slow)
// 		}
// 	}
// 	cout<<"No! there is no cycle."<<endl;
// 	return;
// }

//question -> find starting point of the cycle.
//approach.-> 1.find the length of cycle. 2.move second pointer length times. 3.keep moving both pointer until they meet again.

// void startofcycle(node* &head){
// 	//first find the length of cycle of linkd list
// 	int cyclelength=hascycle(length);
// 	//check for a condition if lentht is zero i.e there is no cycle

// 	if(cyclelength<=0){
// 		return;
// 	}
// 	node* f=head;
// 	node* s=head;
// 	//move the second pointer length times
// 	while(cyclelenght>=0){
// 		s=s->next;
// 		cyclelength--;
// 	}
// 	//keep moving both pointers until they meet again.

// 	while(f!=s){
// 		f=f->next;
// 		s=s->next;
// 	}

// }

//google question happy number -
//appraoch -> use two pointer method just we use to detect the cycle in a linked list.
//create a square calculation function separately.

int square(int n){
	int s=0;
	while(n>0){
		int d=n%10;
		s+=d*d;
		n/=10;
	}
	return s;
}

bool happy(int n){

int slow=n;
int fast=n;
do{
	//slow pointer will square one time
	slow=square(slow);
	debug(slow)
//fast pointer will run two time by squarin two time
	fast=square(square(fast));
	debug(fast)
}
while(slow!=fast);
//if square becomes one then its a happy number
	if(slow==1){
	return true;
		}
	else{
		return false;
	}

}

//sort the linked list.

void sortlinkedlist(){
	//keep comparing the data of nodes till the end
	//use merge sort for sorting.
}

//recursively reverse the linked list.
// void recursivelyreverse(node* &head){
// 	node* head
// 	if(head->next=NULL){
// 			tail=head;
// 		return;
// 	}
// 	//this will take care of the smaller part of the linked list.
		
// 	recursivelyreverse(head->next);
// 	tail->next=head;
// 	tail=head;
// 	tail->next=NULL;
// }

//question -> reverse linked list from left to right (sub linked list)
//approach -> just try to find the (left-1)th node and (right+1)th node.
//reverse the linked list in the usual way.
//********************************
//(reverse k nodes in group and reverse k nodes in group skipping the next k nodes ) is exactly similar to this problem just a little twist.
//use your brain to solve it.
void reverseinrange(node* & head,int left,int right){
	//initial check
	if(left==right){
		return head;
	}
	//we need to go to the (left-1 node)
	node* curr=head;
	node* prev=NULL;
	for(int i=0;curr!=NULL and i<left-1;++i){
		debug(i)
		prev=curr;
		curr=curr->next;
	}
//store the unconnected nodes
	node* last=prev;
	node* newend=curr;

	//now reverse the linked list
	node* next=curr->next;
	for(int i=0;i<curr!=NULL and i<(right-left)+1;++i){
		 curr->next=prev;
		prev=curr;
		curr=next;
		if(next!=NULL){
			next=next->next;
		}
	}

	//making right connections.
//check if prev is the last node
	if(last!=NULL){
		last->next=prev;
	}
	else{
		head=prev;
	}
	newend->next=curr;
	//return head;
}

//question-> palindrome linked list
//aryan approach -> keep two pointers first at starting and second at last
//keep comparing the data till these pointers overlap if the data is not equal at any point of time then
//return falsr else return true;
//kunal approach
//find the middle of linked list
//reverse the second half of linked list from middle
//keep two pointers for checking the data until second pointer is null
void palindromelinkedlist(node* & head){
	//get middle of linked list
	node* middle=middleoflinkedlist(head);

	//reverse the second half
	node* secondhead=reversell(middle);
	node* reversehead=secondhead;
//keep checking the data
	while(head!=NULL and secondhead!=NULL){
		if(head->data!=secondhead->data){
			break;
		}
		head=head->next;
		secondhead=secondhead->next; 
	}
//re reverse the linked list from second head;
	reversell(reversehead);
	if(head==NULL or secondhead==NULL){
		cout<<"it is a palindrome"<<<endl;
	}
	cout<<"NOT a palindrome"<<endl;
}


//question -> reorder linked list in certain way (leetcode)
//approach -> find the middle of linked list and then star traversing by two pointers and then merge it

void reorderll(node* & head){
	if(head==NULL or head->next==NULL){
		return ;
	}
	node* middle=middleoflinkedlist(head);
	node* hf=head;
	node* hs=middle;
	while(hf!=NULL and hs!=NULL){
		node* temp=hf->next;
		hf->next=hs;
		hf=temp;
		temp=hs->next;
		hs->next=hf;
		hs=temp;
	}
	if(hf!=null){
		hf->next=NULL;
	}
}


//rotate the linked list k times to the right.
//approach -> k value greater than k will be just (size%k) times rotate.
 void rotatelinkedlist(node* & head,int k){
 	//if k  is greater than size
 
 	//find the size of linked list
 	//skip size-k nodes
 	//connect the nodes in their order
 
 	if( k <=0 or head==NULL or head->next==NULL){
 		return;
 	}
 		node* last=head;
 	int length=1;
 	while(last!=NULL){
 		last=last->next;
 		length++;
 	}
 	last->next=head;
 	node* newlast=head;
 	int rotation=k%length;
 	int skip=length-rotation;
 	for(int i=0;i<skip-1;++i){
 
 		newlast=newlast->next;
 	}
 	//the new head will become newlast of next
 	//and newlast of next will point to null now.

 	head=newlast->next;
 	newlast->next=NULL;
 }

int main(){
#ifndef ONLINE_JUDGE
	freopen("error.txt","w",stderr);
#endif

	node* head=new node(1);
	insertathead(head,2);
	insertathead(head,3);
	insertathead(head,4);
	insertathead(head,5);

}