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

//let's create a class for binary tree.

class node{
public:
	//data which will be store in node
int data;
//in generic tree we don't know how many nodes will be there in parent or root so we have to store them in vector.
//but her in binary tree we know there will not be more than Two Nodes in Binary tree.
//that's why we are storing them in pointers.
node* left;
node* right;
//let's make a constructor of binary tree.
public:
	node(int d){
		data=d;
		left=NULL;
		right=NULL;
	}
};


// void construct_tree(node* &root){
// 	stack<pair<node*,int>> s;
// 	s.push({root,-1}); 	
// 	while(s.size()>0){
// 		pair<node*,int> top=s.top();
// 		s.pop();
// 		if(top->state==-1){

// 		}
// 		else if(top->state==top->first->size())

// 	}

//question-> display a binary tree.
// void display(node* &root){
// 	if(root==NULL)
// 	{
// 		return;
// 	}
// 	//just ek root node ke  liye display karva do 
// 	//and then leave the rest to the recursion
// 	string ans="";
// 	 ans+="<-" + root->data + "->";
// 	ans+= (root->left==NULL) ?  "." : " " + root->left->data; 
// 	ans+= (root->right==NULL) ? "." : " " + root->right->data;
// 	cout<<ans;

// 	//just call for left subtree.
// 	//just call for right subtree.
// 	display(root->left);
// 	display(root->right);	

// }

int sizeoftree(node* &root){
	if(root==NULL){
		return 0;
	}
	int leftsize=sizeoftree(root->left);
	int rightsize=sizeoftree(root->right);
	int totalsize=leftsize+rightsize+1;
	return totalsize;
}
//sum of nodes.
int sumoftree(node* &root){
	if(root==NULL){
		return 0;

	}
	int leftsum=sumoftree(root->left);
	int rightsum=sumoftree(root->right);
	int totalsum=leftsum+rightsum+root->data;
	return totalsum;
}

//max of tree.
int maxoftree(node* &root){
	if(root==NULL){
		return 0;
	}
	int lm=maxoftree(root->left);
	int rm=maxoftree(root->right);
	int m=max(lm,rm);
	
	return m > root->data ? m : root->data;

}

//height of tree
int heightoftree(node* &root){
	if(root==NULL){
		return 0;
	}
	int lh=heightoftree(root->left);
	int rh=heightoftree(root->right);
	int res=max(lh,rh);
	return res+1;
}

//preorder
void preorder(node* &root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
//inorder
void inorder(node* &root){
	if(root==NULL){
		return;
	}
	preorder(root->left);
	cout<<root->data<<" ";
	preorder(root->right);
}
//postorder
void postorder(node* &root){
	if(root==NULL){
		return;
	}
	preorder(root->left);
	preorder(root->right);
	cout<<root->data<<" ";
}


//level order traversal
//use remove print add algo.
void levelorder(node* &root){
queue<node*> mq;
mq.push(root);
while(mq.size()>0){
	int cnt=mq.size();
	for(int i=0;i<cnt;++i){
		node* temp=mq.front();
		mq.pop();
		cout<<temp->data<<endl;
		if(temp->left!=NULL){
			mq.push(temp->left);
		}
		if(temp->right!=NULL){
			mq.push(temp->right);
		}
	}
	cout<<endl;
}
}

//iterative pre order inorder levelorder
void iterativetraversal(node* &root){

	// string pre="";
	// string in="";
	// string post="";
	// stack<pair<node*,int>>s;
	// pair mp={root,1};
	// s.push(mp);
	// while(s.size()>0){
	// 	if(s.top->state==1){
	// 		if(s.top->left!=NULL){
	// 			s.push(top->left);
	// 		}
	// 		state++;
	// 	}
	// 	else if(s.top->state==2){

	// 	}
	// 	else{

	// 	}
	// }
}

//question->node to root path
vector<node*> path;
bool findandprintnodetoroot(node* & root,int data){
	if(root==NULL){
		return false;
	}
	if(root->data==data){
		path.push_back(root);

	}	
	bool filc=findandprintnodetoroot(root->left,data);
	if(filc){
		path.push_back(root);
		return true;
	}
		bool firc=findandprintnodetoroot(root->right,data);
	if(firc){
		path.push_back(root);
		return true;
	}
	return false;
}

//question-> print k levels down
//approach -> just think  how far that level is from the root itself.
//go to that level 
//print the Nodes of that Level.

void kleveldown(node* &root,int k,node* blocker){
	if(root==NULL or k<0 or root==blocker){
		return;
	}
	if(k==0){
	cout<<root->data<<" ";
}
	kleveldown(root->left,k-1,blocker);
	kleveldown(root->right,k-1,blocker);
}
//question nodeto root path for binary treee

vector<node*> nodeToRootPath(node* &root, int data) {
  vector<node*> temp;
  if (root == nullptr) {
    return temp;
  }

  vector<node*> ans;
  if (root->data == data) {
    ans.push_back(root);
    return ans;
  }
  vector<node*> left = nodeToRootPath(root->left, data);
  if (left.size() > 0) {
    left.push_back(root);
    return left;
  }
  vector<node*> right = nodeToRootPath(root->right, data);
  if (right.size() > 0) {
    right.push_back(root);
    return right;
  }
  return temp;
}


//question->print k nodes away.
//approach -> use k level down function and node to root path.

void nodeskdistanceaway(node* &root,int data,int k){
//this will fetch node to root path 
bool s=findandprintnodetoroot(root,data);

//now use k level down just take care of node which is already visited.

for(int i=0;i<path.size();++i){
	if(i==0){
		kleveldown(path[i],k-i,NULL);
	}
	kleveldown(path[i],k-i,path[i-1]);
}

}

//question->transform to left cloned tree.
//approach -> start from root node and check for left child only.

node* transformleftclone(node* &root){
	if(root==NULL){
		return NULL;
	}
	node* nln=transformleftclone(root->left);
	node* rln=transformleftclone(root->right);
	node* ln=new node(root->data);
	root->right=rln;
	root->left=ln;
	return root;
}

//question->transform back a cloned tree to its Normal Form
//have faith the your left child and right child will bring you normal tree.
//just think of the root 
node* transformleftclonetonormal(node* &root){
//base case;
	if(root==nullptr){
		return nullptr;
	}
node* ol=transformleftclonetonormal(root->left->left);
node* orr=transformleftclonetonormal(root->right);
root->left=ol;
root->right=orr;
return root;
}


//question ->print only child of parent.
//check for root if it has more two children
void printsinglechild(node* &root,node* parent){
if(root==nullptr){
	return ;
}
//check if current parent has 1 child
if(parent!=nullptr and parent->left==root and parent->right==nullptr){
cout<<root->data<<" ";
}
//either there will be no left child or no right child
//if it is like this then print that node data
else if(parent!=nullptr and parent->left!=nullptr and parent->right==root){
cout<<root->data<<" ";
}

printsinglechild(root->left,root);
printsinglechild(root->right,root);

}

//remove leaves node
///aryan apprach->first reach tothe leaf node and delete it.

node* removeleaves(node* &root){
	if(root==nullptr){
		return nullptr;
	}
		if(root->left==nullptr and root->right==nullptr){
		//delete the node
		return nullptr;
	}

	root->left=removeleaves(root->left);
	root->right=removeleaves(root->right);
	
	return root;
}

//question->diamter of binary tree
//approach -> find max height of left child 

int diameter(node* &root){
	if(root==nullptr){
		return 0;
	}
	int ld=diameter(root->left);
	int rd=diameter(root->right);
	int rh=heightoftree(root->left)+heightoftree(root->right)+1;

	int ans=max(rh,max(ld,rd));
	return ans;
}

//optimized diameter
//lovebabbar
pair<int,int> diamterfast(node* &root){
	if(root==nullptr){
		pair<int,int> basepair =make_pair(0,0);
		return basepair;
	}

	pair<int,int> left=diamterfast(root->left);
	pair<int,int> right=diamterfast(root->right);
	int op1=left.first;
	int op2=right.first;
	int op3=left.second+right.second+1;

	pair<int,int> ans;
	ans.first=max(op1,max(op2,op3));
	ans.second=max(left.second,right.second);
	return ans;
}

//diameter by sumeet sir.
//sumeet sir was returning vector but i can return vector
// static class diameter_pair{
// 	int ht;
// 	int dia;
// };

// static diameter_pair diamterfast2(){
// 	pair<int,int> m;
// 	return m;
// // }
// //above was erorr full code.
// class diapair{
// public:
// int ht;
// int dia;

// };
//  diapair diamterfast2(node* &root){
//  	if(node==nullptr)
//  	diapair bp =new diapair();
//  	bp->ht=-1;
//  	bp->dia=0;
//  	return bp;
// 	}
//question->tilt of tree.
//aryan approach->just find the tilt of root subtree and return total tilt sum
static int tilt=0;
int tiltoftree(node* &root){
if(root==nullptr){
	return 0;
}
	//will return sum but after changing the tilt for left subtree
	int ls=tiltoftree(root->left);
	//will return sum but after changing the tilt for right subtree
	int rs=tiltoftree(root->right);
	int local_tilt=abs(ls-rs);
	tilt+=local_tilt;
	int ts=ls+rs+root->data;
	return ts;
}

//question -> is binary tree a bst
//aryan approach -> Check for the first subtree and recursively call for others to do the same thing
//pep approach -> you should also bring left max and left min and right max and right min for checking of
//the root node bst

//bcoz above you there are also some parent of that node

class bst{
public:
	bool isbst=true;
	int min_val=INT_MAX;
	int max_val=INT_MIN;
};

bst isvalid(node* &root){
	if(root==nullptr){
		bst bres;
		bres.isbst=true;
		bres.min_val=INT_MAX;
		bres.max_val=INT_MIN;
		return bres;
	}
	bst ans;

	bool ln=isvalid(root->left);
	bool rn=isvalid(root->right);
	ans.max=max(root->data,max(ln.max,rn.max));
	ans.min=min(root->data,min(rn.min,rn.max));
	if(ln.isbst and rn.isbst) and (root->data>ln.max and root->data<rn.min){
		return true;
	}
return ans;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("error.txt","w",stderr);
#endif

cout<<"hello Aryan"<<endl;

node* root = new node(10);
    root->left = new node(8);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(5);
    root->right->left = new node(2);
cout<<sizeoftree(root)<<endl;
cout<<sumoftree(root)<<endl;
cout<<maxoftree(root)<<endl;


}