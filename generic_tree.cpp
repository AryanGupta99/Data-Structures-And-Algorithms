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


//generic tree class

struct node{
int data;
vector<node*>children;
};

node* newnode(int val){
	node* mynode=new node();
	mynode->data=val;
	return mynode;
}

node* constructor(vector<int> arr,int  n){
	node * root=NULL;
	stack<node*> st;
for(int i=0;i<n;++i){
if(arr[i]==-1){
	st.pop();
}
else{
	node* t=newnode(arr[i]);
	if(st.size()==0){
			root=t;
	}
	else{
	st.top()->children.push_back(t);
	}
	st.push(t);
	
}
}
return root;
}

//for displaying of generic tree

void display(node* mynode){
string str=to_string(mynode->data)+"->";
for(node* child : mynode->children){
	str+=to_string(child->data)+" ";
}
str+=".";
cout<<str<<endl;
for(node* child : mynode->children){
	display(child);
}
}

//question -> size of a generic tree
//appraoch -> do it with recursion have faith that your function will return the size of smaller subtree.
//just add it to the top root with +1;

int sizeoftree(node* &root){
	//recurrence relation will be-> size of tree(child)+1;
	if(root==NULL){
		return 0;
	}
	int result=0;
	//have faith that below will give you child size or size of smaller subtree;
	for(node* child: root->children){
		int childsize=sizeoftree(child);
		result+=childsize;
	}
	return result+1;
}

//question -> find max in a generic tree of multiple child nodes.
//aryan approach - > try to have faith that subtree will give you max value 
//just compare with the root value then your answer will be there.

int maxoftree(node* &root){
	// if(root==NULL){
	// 	return 0;
	// }
	int max=-1;
	for(node* child : root->children){
		int maxinchildren=maxoftree(child);
			if(maxinchildren>max){
		max=maxinchildren;
	}
}
	if(root->data>max){
		max=root->data;
		return max;
	}
	return max;
}

//question-> height of generic tree.
//aryan approach-> use the stack method when you hit -1 that means you have reached the leaf node.
//keep increasing the counter by 1 till you reach the leaf node and then try to compare it with the next leaf height.

int heightoftree(node* & root){
	int ht=-1;
	//-1 is initialized bcoz if there is only one node then it will give good result
	for(node* child: root->children){
		int cht=heightoftree(child);
		if(cht>ht){
			ht=cht;
		}
	}
	ht=ht+1;
	return ht;
}

//question -> preorder and postorder traversal
//aryan approach -> pre order means going in to recursion i.e filling the stack i.e code before functin call.
//postorder means coming out of recursion i.e removal of stack i.e code after function call.

void traversaloftree(node* & root){
	//area 1 i.e node's pre area or befor the recursive call.
	cout<<"Node Pre " << root->data<<endl;
	for(node* child: root-> children){
		//this will be edge pre area i.e just before the call
		cout<<"Edge Pre"<<root->data<<"--"<<child->data<<endl;
		traversaloftree(child);
		//this willl be edge post area i.e just after the call.
		cout<<"Edge Post"<<root->data<<"--"<<child->data<<endl;
	}
	//area2 i.e node's post area or after the recursive call.
	cout<<"Node Post"<<root->data<<endl;
}

//question -> level order traversal of generic tree.
//use a queue of nodes and repeat the three processs like {remove,print,add}

void levelordertraversal(node* &root){
		queue<node*> q;
		q.push(root);
		while(q.size()>0){
			node* temp=q.front();
			//remove
			q.pop();
			//print
			cout<<temp->data<<" ";
			//add its' children
		for(node* child: temp->children){
			q.push(child);
		}

		}
}

//question-> level order traversal line wise
//use extra queue to store child nodes.

void levelorderlinewise(node* & root){
	if(root==NULL or root->children.size()==0){
		return;
	}
	queue<node*> mq;
	queue<node*> chq;
	mq.push(root);
	while(!mq.empty()){
		node* temp=mq.front();
		mq.pop();
		cout<<temp->data<<" ";
		for(node* child : temp->children)
			chq.push(child);
			if(mq.size()==0){
			swap(mq,chq);
			cout<<endl;
		}
}
}

//question -> level order zig zag

void levelorderzigzag(node* &root){
if(root==NULL){
	return;
}

stack<node*> ms,chs;
ms.push(root);
int level=1;
while(ms.size()!=0){
	//this temp node was making the mistake
node* temp=ms.top();
ms.pop();
cout<<temp->data<<" ";
if(level%2==1){
	//i was using root instead of temp node children.
	for(node* child: temp->children)
		chs.push(child);
}
	else{
		for(int i=temp->children.size()-1;i>=0;i--)
			chs.push(temp->children[i]);
	}
	if(ms.size()==0){
		swap(ms,chs);
		cout<<endl;
		level++;
	}
}
}

//level order traversal with just one queue and with help of dummy node.
//dummy node is null you have to insert two null at the end of queue 
//these null values will determine the level of tree.

void levelorderlinewise2(node* & root){
	queue<node*> mq;
	mq.push(root);
	mq.push(NULL);
	while(mq.size()>0){
		node* temp=mq.front();
		mq.pop();
		if(temp==NULL){
			cout<<endl;
			if(mq.size()>0) mq.push(NULL);
		}
		else{
		cout<<temp->data<<" ";
		for(node* child : temp->children){
			mq.push(child);
		}
		}
	}
}

//question -> level order traversal 3 
//without extra node we can use size of queue to print level order traversal.
void levelorderlinewise3(node* & root){
	queue<node*> mq;
	mq.push(root);
	while(mq.size()>0){
		int size=mq.size();
		while(size-->0){
		node* temp=mq.front();
		mq.pop();
		cout<<temp->data<<" ";
		for(node* child : temp->children)
			mq.push(child);
		}
		cout<<endl;
	}
	}


//question-> mirror image of generic tree.
//aryan approach -> just do the level order traversal while doing the level order traversal
//just reverse the nodes

void mirrorimage(node* & root){
//we don't have to work with the root node 
//bcoz root node is simply going to be printed.
for(node* child: root->children){
	//this will reverse the below every level
	//you just solve the one level by reversing it.
	mirrorimage(child);
}
//reverse the array or chilreen size array
for(int i=0,j=root->children.size()-1;i<j;++i,--j){

node* temp=root->children[i];
 root->children[i]=root->children[j];
 root->children[j]=temp;
}

//short form of above code
//int i=0;int j=root->children.size()-1;
//while(i<j){
	//swap(root->children[i++],root->children[j--])
// }//
}


//question -> remove  leaves in a generic tree.
//approach -> have faith that leaves of sub children will be delted by recursive call.

void removeleaves(node* &root){
//we run the for loop from the back side because we will lose some nodes if we find leaf node in the arraylist.
//so to avoid this problem we will be traversing from right to left.

for(int i=root->children.size()-1;i>=0;i--){
	node* child=root->children[i];
	if(child->children.size()==0){
		root->children.erase(root->children.begin()+i);
	}
}
//here the recursive call is made in the post order because it will consider every node as leaf node.
//so we will first remove the leaf nodes and then we will make recursive calls;
for(node* child : root->children){
	removeleaves(child);
	}
}

//question->we have to linearize the tree i.e every node must Have Only One Child.
//approach of aryan Is To use queue and then use RPA method to do it.
//make the next node as the Child of previouse node.
node* gettailoflinearize(node* &root){
	while(root->children.size()>0){
		root=root->children[0];
	}
	return root;
}
//wrong approach of aryan as always.
//pec approach->have faith that children will be linerize by themselves with the help of recursion
//you just need to linearize the main root to children nodes.
void linearize(node* & root){
	//this will solve for every nodes children
	for(node* child: root->children){
		linearize(child);
	}
	//just solve the one case
	while(root->children.size()>1){
		node* last=root->children.back();
		root->children.pop_back();
		node* secondlast=root->children.back();
		//the below function is making the time complexity of this question to be O(n2);
		//to optimize this we can reduce the get tail method by getting the teil while traversing above.
		//code->
		//if(root->children.size()==0) return root;
		//node* lastkatail=linearize(root->children[root->children.size()-1])
		//while(root->children.size()>1){
		//node* last=root->chidren.back();
		//root->children.pop_back();
		//node* secondlast=root->children[root->children.size()-1]
		//node* secondlasttail=linearize(secondlast);
		//secondlasttail->children.push_back(last)
		//}
		node* tail=gettailoflinearize(secondlast);
		tail->children.push_back(last);
	}
} 

//question-> find in a generic tree.
//aryan approach -> keep searching the data in root's children and then recursively call function.

bool finddata(node* & root,int data){
	if(root->data==data){
		return true;
	}
	for(node* child: root->children){
		bool recursion_result=finddata(child,data);
		if(recursion_result==true){
			return true;	
		}
	}	
	return false;
}

//question->print or return vector of node to root path in generic tree
//approach-> find the data and if you have found the data then start.
//then start pushing the children of root node to the searched data.

vector<int> nodetoroot(node* &root,int item){
if(root->data==item){
	vector<int> bres;
	bres.push_back(root->data);
}

vector<int> ans;
for(node* child: root->children) {
	vector<int> recres=nodetoroot(child,item);
	if(recres.size()>0){
		recres.push_back(root->data);
		return recres;
	}
}
return ans; 
}


//question-> lowest common ancestor
//approach -> store the path of root to node d1 and store path to node d2
//start traversing from the back of path till you find unequal nodes.

int lca(node* &root,int item1,int item2){
	//use the node to root path logic.
	vector<int> path1=nodetoroot(root,item1);
	vector<int> path2=nodetoroot(root,item2);
	int i=path1.size()-1;
	int j=path2.size()-1;
	while(i>=0 and j>=0 and path1[i]==path2[j]){
		i--;
		j--;
	}
	//here we would have moved to unequal element
i++;
j++;
return path1[j];
	}

//distance between two nodes
//approach -> find the lca of both nodes calculate the nodes from that point to end

int distancebwnodes(node* & root,int item1,int item2){
vector<int> path1=nodetoroot(root,item1);
	vector<int> path2=nodetoroot(root,item2);
	int i=path1.size()-1;
	int j=path2.size()-1;
	while(i>=0 and j>=0 and path1[i]==path2[j]){
		i--;
		j--;
	}
	//here we would have moved to unequal element
	i++;
	j++;
	return i+j;
	}

//question-> are trees similar in shape 
//aryan approach -> criteria of similarity is that no of nodes in both tree should be same.
//every subtree must have same number of children in every parent node.

bool istreesimiliar(node* &root1,node* &root2 ){

	if(root1->children.size()!=root2->children.size()){
		return false;
	}

	for(int i=0;i<root1->children.size()-1;++i){
		node* c1=root1->children[i];
		node* c2=root2->children[i];
		if(istreesimiliar(c1,c2)==false){
			return false;
		}
	}
	return true;

}

//question-> are tree mirror image of each other.
//approach -> check if every children from first child of root node is similar to last child of another root node.
// do it for rest of the child.

bool istreemirror(node* & root1,node* &root2){
	//children must  be same.
	if(root1->children.size()==root2->children.size()){
		return false;
	}
	for(int i=0;i<root1->children.size()-1;i++){
		int j=root2->children.size()-1-i;
		node* firstchild=root1->children[i];
		node* lastchild=root2->children[j];
		if(istreemirror(firstchild,lastchild)==false){
			return false;
		}
	}
	return true;
	
}
//question-> is tree symmetric
//approach-> just check that nodes of every child must be equal to nodes of last child
//just check if two nodes are mirror image of each other then it is symmetric also.
bool istreesymmetric(node* &root){
	if(istreemirror(root,root)==true){
		return true;
	}
	return false;
	}
	int size_tree=0;
	int min_val=INT_MAX;
	int max_val=INT_MIN;
	int height=0;
void multisolver(node* &root,int depth){
		size_tree=size_tree+1;;
		min_val=min(root->data,min_val);
		max_val=max(root->data,max_val);
		height=max(height,depth);
	for(node* child:root->children){
		multisolver(child,depth+1);
	}
}

//predecessor and successor of node.
//aryan approach-> just store the preorder traversal of tree and return previous and next element of node,


void pre_and_succ(node* &root,int data){
	node* predecessor;
	node* successor;
	int state=0;
	if(state==0){
		if(root->data==data){
			state=1;
		}
		else{
			predecessor=root;
		}
	}
		else if(state==1){
			successor=root;
			state=2;
		}
	for(node* child: root->children){
		pre_and_succ(child,data);
	}
}

//question-> ceil and floor of particular node
//approach -> keep comparing the data of root node till the data of ceil and floor


void ceilandfloor(node* & root,int data){
int ceil_val=INT_MAX;
int floor_val=INT_MIN;
if(root->data>data){
//just larger than given data=ceil
	if(root->data<ceil_val){
		ceil_val=root->data;
	}
}
if(root->data<data){
	//just smaller than given data=flooor
if(root->data>floor_val){
	floor_val=root->data;
}
}
for(node* child:root->children){
	ceilandfloor(child,data);
}

}


//question-> kth largest element in a tree or array.
//just find the floor k times in the function 
//if you want to find the kth smallest then find the ceil of function k times.

// void kth_largest(node* &root,int k){
// 	//floor =largest among smallers
// 	//ceil=smalles among largers
// 	int floor_val=INT_MIN;
// 	//we have to find floor of infinity
// 	int factor=INT_MAX;
// 	for(int i=0;i<k;++i){
// 		floor_val=ceilandfloor(root,factor);
// 		//next time my floorval will be changes
// 		factor=floor_val;
// 		//and default floor will be resetted.
// 		floor_val=INT_MIN;
// 	}
// }


//question-> max subtree sum;
//aproach-> just find the maxsum of root subtree and leave the rest to recursion
//and finally compare the maxsum to root subtree max sum.
	int max_sum_node=0;
	int curr_max=INT_MIN;
int  maxsumsubtree(node* &root){

	int sum=0;
	for(node* child: root->children){
		int child_sum=maxsumsubtree(child);
		child_sum+=sum;
	}
	sum+=root->data;
	if(sum>curr_max){
		curr_max=sum;
		max_sum_node=root->data;
	}
	return sum;
}

//diamter of tree
//approach-> har ek child ko bolo ki vo apni max height lekr aa jaye.
//fir second max height nikal krlayo
//or usme + 2 krdo. 2 edge extra lgane ke liye. 

int dia = 0;
int diameter(node* root) {
  int ht = -1;
  int sh = -1;
  for (auto child : root->children) {
    int ch = diameter(child);
    if (ch >= ht) {
      sh = ht;
      ht = ch;
    } else if (ch >= sh) {
      sh = ch;
    }
  }
  if (sh + ht + 2 > dia) {
  	//+2 describes that there are two extra edges for root node.
    dia = sh + ht + 2;
  }
  //us node ki height ke liye ek add krdiya
  ht += 1;
  return ht;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("error.txt","w",stderr);
#endif


vector<int> arr;
arr.assign({10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1});
int n=arr.size();

node* root=constructor(arr,n);
cout<<sizeoftree(root)<<endl;
pre_and_succ(root,20);
levelorderlinewise(root);
ceilandfloor(root,30);
maxsumsubtree(root);

cout<<diameter(root);
}