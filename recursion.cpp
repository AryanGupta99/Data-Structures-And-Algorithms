#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793238462
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" = "; print(x); cerr << endl;
#else
#define debug(x);
#endif
#define mod int(1e9+7);
#define ll long long int

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
// THESE ARE FOLLOWING RECURSIONS PROBLEMS ONLY
//nth fibonacci number 
//recurrrence relation -> fib(n)=fib(n-1)+fib(n-2)
// try to draw recursion tree/ euler tree of value 4 bcoz its easy.
int nthfib(int n){
	if(n<2){
		return n;
	}
	int fib=nthfib(n-1)+nthfib(n-2);

	 return fib; 
}

//print decreasing
//function call will be like for n= 5-> f(5)->f(4)->f(3)->f(2)->f(1) then return back;

void printDecreasing(int n){
    if(n==0){
        return;
    }
    cout<<n<<endl;
    printDecreasing(n-1);
    
}

//factorial of number through recursion
// factorial = multiplication of numbers from n to 1;
// eg fact(5)-> 5 * 4* 3 * 2 *1=120
int factorial(int n){
	if(n<2){
		return 1;
	}
	return n*factorial(n-1);
}
//calculate pow(a,b) through recursin by logn complexity.
//idea is that pow(a,1024)=pow(a,512)*pow(a,512) if n is even;
//else if n is odd then multiply extra x at the end .
int powerLogarithmic(int x,int n){
    // write your code here
    //base wala recursion
    if(n==0){
        return 1;
    }
    //faith it will return half power
    int xpnb2=powerLogarithmic(x,n/2);
    //meet faith with expectation
    int xn=xpnb2*xpnb2;
    if(n%2==1){
        xn=xn*x;
    }
    return xn;
}

//Tower of Hanoi through recursion
//try to think that the problem will be solved for the base case n= 1;
//print the instruction for smallest input i.e n=1 just move from a to c;
//so the approach is yout tower of hanoi know to print the instruction of moving (n-1) disk from a to b
// you also know to move nth disk from a to c //so the approach is yout tower of hanoi know to print the instruction of moving (n-1) disk from a to b
// you also know to move nth disk from a to c 
// now you just need to call (n-1) for moving disk from a to b to a to c;
// now you just need to call (n-1) for moving disk from a to b to a to c;
void towerofhanoi(int n,char src,char helper,char dest){
	if(n==0){
		return;
	}

	towerofhanoi(n-1,src,dest,helper);
	cout<<"Disk "<<n<<" is moved from "<<src <<" to "<<dest<<endl;
	towerofhanoi(n-1,helper,src,dest);

}

//count zeroes in a number 
//eg n =30204 ans=2;
// the idea is to extract the last digit and if it found to be 0 increase the count in the argument itsel
// else keep reducing the number;
int zeroescount(int n,int count){
	if(n==0){
		return count;
	}
	if(n%10==0){
		return(n/10,count++);
	}
	return (n/10,count);
}
//subset print /
//for printing elements of subset i have two choices for each element in the array or string
// either i will include the element to the answer subset array or not include the element to answer subset array
//and keep calling the function till size of array finish.
void PrintAllSubsets(int *arr, int i, int n,int *subset, int j){    
    // checking if all elements of the array are traverse or not
    if(i==n){
        // print the subset array
        for(int f=0;f<j;++f){
        	cout<<subset[f]<<" ";
        }
        cout<<endl;
        return;
    }
    // for each index i, we have 2 options
    // case 1: i is not included in the subset
    // in this case simply increment i and move ahead
    PrintAllSubsets(arr,i+1,n,subset,j);
    // case 2: i is included in the subset
    // insert arr[i] at the end of subset
    // increment i and j
    subset[j] = arr[i];
    PrintAllSubsets(arr,i+1,n,subset,j+1);
        
}

//same subset printing through vector
void printss(vector<int>v ,int i ,vector<int>subset){
	if(i==v.size()){
		for(int f=0;f<subset.size();++f){
        	cout<<subset[f]<<" ";
        }
        cout<<endl;
        return;
	}
//if current element is not included
printss(v,i+1,subset);
subset.push_back(v[i]);
printss(v,i+1,subset);
subset.pop_back();
}

bool issorted(int a[],int n){
	if(n==0 or n==1){
		return true;
	}
	if(a[0]<a[1] and issorted(a+1,n-1)){
		return true;
	}
	return false;
}
//first index of array
//start comparing before the function call bcoz you may find the element at the beginning .
//in this way you will be making few number of calls 
// after this just compare your first index with above returned value /
int firstindex(int arr[],int n,int idx,int data){

	if(idx==n){
		return n;
	}
	//first index in smaller array
	if(arr[idx]==data){
		return idx;
	}
	else{
	int fiisa=firstindex(arr,n,idx+1,data);
	return fiisa;
}
}
//last index of array.
//here you compare at the end of the function call
// bcoz you will be comparing from the last so you will get last index pretty fast
// you can also use binary search to find first and last index for optimized code;

int lastindex(int arr[],int n,int idx,int data){

	if(idx==n){
		return -1;
	}
	//last index in smaller array
	int liisa=firstindex(arr,n,idx+1,data);
	if(liisa==-1){
		if(arr[idx]==data){
			return idx;
		}
		else{
			return -1;
		}
	}
	else{	
		return liisa;
	}
}
//bubble sort through recursion
//every sorting algorithm can be done through recursion 
// you just have to think of the basic approach that is done for sub problem and then repeat it though recurision by passing the correct arguments.
//just have faith that your function will sort the n-1 elements of array
// and you just have to sort the remaining element

void bubblesort(int a[], int n){
	if(n==1){
		return;
	}
	for(int i=0;i<n-1;++i){
		if(a[i]>a[i+1]){
			swap(a[i],a[i+1]);
		}
	}
	bubblesort(a,n-1);
}
//selection sort using recursion
//just use the basic concept of selection sort and implement it using recursion variables.
//consider staring element as min_index or max_index 
//put it at the end of the array by swapping in one pass.
//and recursively increase the index through arguments.
void selectionSort(int arr[], int i, int n)
{
    // find the minimum element in the unsorted subarray `[i…n-1]`
    // and swap it with `arr[i]`
    int min = i;
    for (int j = i + 1; j < n; j++)
    {
        // if `arr[j]` is less, then it is the new minimum
        if (arr[j] < arr[min]) {
            min = j;    // update the index of minimum element
           }
    }
    // swap the minimum element in subarray `arr[i…n-1]` with `arr[i]`
    swap( arr[min], arr[i]); 
    if (i + 1 < n) {
      selectionSort(arr, i + 1, n);
    }
}
//approach - just keep fetching the last digit and use digit array to print the spelling.
// imp part is to make the spelling array.
//subproblem is that recursion will print the sub problem spellings.
// i just need to print the last digit.
void printdigits(int n){
string digit[10] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
if(n==0){
return;
}
printdigits(n/10);
int d=n%10;
cout<<digit[d]<<" ";
}

int stringtoint(char *s,int n){
	if(n==0){
		return 0;
	}
	int digit=s[n-1]-'0';
	int ans=stringtoint(s,n-1);
	return ans*10+digit;
}
//the Idea is to keep traversing the character array till end and keep finding the 'p','i';
//imp thing is to do it without extra space;
//you have to also take care of the '3.14' size of the characters
void replacepi(char a[],int i){
//base case
	if(a[i]=='\0' or a[i+1]=='\0'){
		return;
	}
	//now look for 'p' 'i' at current index;
		if(a[i] =='p' and a[i+1]=='i'){
			//now we have to do shifting and replacement of characters
			//first i have to do shifting only then i will be Able to place characters at the right position

			//taken j to end Of The Array.
			int j=i+2;
			while(a[j]!='\0'){
				j++;
			}

			//shifting
			while(j>=i+2){
				a[j+2]=a[j];
			
				j--;
			}
			a[i]='3';
			a[i+1]='.';
			a[i+2]='1';
			a[i+3]='4';
			replacepi(a,i+4);
		}
	replacepi(a,i+1);
}
//the idea is to fill the wall by horizontal tiles + vertical tiles.
// horizontal tiles will take one unit of place.
// vertical tiles will take four unit of places.
// so the recurrence relation will be of  ---> f(n) = f(n-1) +f(n-4).
int placetiles(int n){
	if(n<=3){
		return 1;
	}
	//f(n-1) will fill the walls of brick size (4,1) for one place and rest will be filled in (n-1) ways bcoz
	// only n-1 places are left In The Vertical Direction.
	//f(n-4) will fill the walls of brick size (1,4) for one tile place and rest in (n-4) ways bcoz only n-4
	//places are left in the horizontal direction.
	return placetiles(n-1)+placetiles(n-4);
}
//Ladder jump Problem.
//question is that i have to return the total number of ways to reach the top.
// i can take three kind of jump i.e 1 step, 2 step, 3 step jump.
// so if i know the answer for (n-1) ladders then i Just Need To Add the one or two or three jumps to it.
//for k number of jumps just run a for loop till k and add ans+=(n-i,k);
int ladderjump(int n,int k){
//base case or smallest possible answer or unit.
if(n==0){
	return 1;
}
if(n<0){
	return 0;
}

int ans=0;
for(int i=1;i<=k;++i){
	ans+=ladderjump(n-i,k);
}
return ans;
}

//question : find the no. of ways friends can go to party. each guy can go as single or couple.there are n friends.
//approach is that when there are less than 3 freinds then there are n ways to go to party.
// if a person is going single then remaining person are (n-1).
// if a person is going with couple then he can choose the couple in (n-1) ways and * with (n-2) bcoz these are
//remaining.

int partyfriends(int n){
	//base case 
	//if there is only one friend or person then answer will be one.
	if(n==0 || n==1 || n==2){
		return n;
	}
	return partyfriends(n-1)+partyfriends(n-2)*(n-1);
}
//question : count the number of Binary string of length N which should not  have consecutive ones ?
// aryan approach is that if i have answer for (n-1) lenght then i just need to add 0 or 1 to the front.
//c.b approach is that if last digit is 0 then (n-1) will be answer for one case.
// if last digit is one then previous digit can be 0 only bcoz 1 is not valid.
// so we must put 0 at the previous digit.
// then (n-2) are remaining in the next case
int count_binary_string(int n){

if(n<=0){
	return 0;
}

if(n==1){
	return 2;
}
return count_binary_string(n-1)+count_binary_string(n-2);

}

//question : Merge Sort using recursion.
//the idea is to divide the array in equal halves until it reduces to one element in array.
//after dividing we will sort the array recursively.
// and then we will merge the array while coming from recursion.
int merging(int *a,int si,int ei){

	if(si>=ei){
		return 0;
	}
	int mid=(si+ei)/2;
	int i=si;
	int j=mid+1;
	//we are taking k variable to copy the merged elements of array.
	// for This We Will Also Need a temp[1000] array.
	int k=si;
	int temp[100];
	//if two arrays are equal in length and sorted in their own ways

	int count=0;
	while(i<=mid && j<=ei){
		if(a[i]<a[j]){
			temp[k++]=a[i++];
		}
		else{
			temp[k++]=a[j++];
			count+=mid-i+1;
		}
	}
//if first sorted array is larger then we need to copy the leftover elements back To The Array .
	while(i<=mid){
		temp[k++]=a[i++];
	}

//if the Second array is larger then we must copy the leftover Elements to the array.
	while(j<=ei){
		temp[k++]=a[j++];
	}
	for(int i=si;i<=ei;++i){
		a[i]=temp[i];
	}
	return count;
}
void mergesort(int a[],int si ,int ei){
	//base case is when we are left with 0 or 1 element 
	if(si>=ei){
		return;
	}

	//3 steps need to follow.
	//1. divide the array
	int mid=(si+ei)/2;
	//2. recursively sort these two divided arrays.
	mergesort(a,si,mid);
	mergesort(a,mid+1,ei);

	//3.merge the sorted arrays.
	//for merging you should write a Separate Merge function.
	merging(a,si,ei);
}


//question : count inversions :
//approach is simple you just need to implement merge sort with a slight change.,
//when you sorting the two arrays just count the inversion by checking( a[i]>a[j]) and add to count.
//count+=mid-i+1; bcoz there are mid-(i-1) elements present in the array which are greater than a[j].

int count_inversions(int a[],int si,int ei){
	int mid=(si+ei)/2;
	//base case is when you have 0 or 1 element .
	if(si>=ei){
		return 0;
	}
	//divide the array and count inversion.
	//this x will give first arrays inversions.
	int x=count_inversions(a,si,mid);
	//this y will give second part arrays inversion.
	int y=count_inversions(a,mid+1,ei);
	//this will give cross inversions.
	int z=merging(a,si,ei);
	return x+y+z;
}

//Recursion with vectors and strings.
//question -> we have to store all subsequences and print them in a vector.
//approach will be that every character of string has either two choices either to come or not come in ssq.
//i will fetch one character and rest string will become question.

vector<string> getsubsequence(string s){

	//base case. when there is no character in the string.
	if(s.length()==0){
			vector<string> base_result;
			base_result.push_back(" ");
		return base_result;
	}
	char ch=s[0];
	string ros=s.substr(1); 
	//recursion will give us the answer for smaller string anyhow.
	vector<string > recursion_result =getsubsequence(ros);
	//then we just need to meet expectation with faith.
	vector<string> ans;
	for(string a: recursion_result){
		ans.push_back("_" + a );
	}
	for(string a: recursion_result){
		ans.push_back(ch+a);
	}
	return ans;
}

//get keypad combination
//aryan approach is that your recursive function will get you result for remaining string.
// you just need to iterate over the remaining last characters and add it to the recursion result.
vector<string> getkpc(string s){

	vector<string> keypad = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};
	//base case 
	//when no character is left in the string.

	if(s.size()==0){
	vector<string> base_result;
	base_result.push_back("");
	return base_result;
	}
	char ch=s[0];
	string ros=s.substr(1);
	vector<string> recursion_result=getkpc(ros);

	vector<string> ans;
	string codeforch=keypad[ch-'0'];
	for(int i=0;i<codeforch.length();++i){
		char cd=codeforch[i];
		for(string sd : recursion_result){
			ans.push_back(cd+sd);
		}
	}
	return ans;
}

//question : get stair path.
//you need to store all the path from top to ground floor.
//you can use recursion to do it by storing it in the vector.
//have faith that your recursive function will give you answer for (n-1) stair paths
vector<string> getstairpath(int n){
	if(n==0){
		vector<string> base_result;
		base_result.push_back("");
		return base_result;
	}
	else if(n<0){
		vector<string> base_result;
		return base_result;
	}
	vector<string> path1=getstairpath(n-1);
	vector<string> path2=getstairpath(n-2);
	vector<string> path3=getstairpath(n-3);
	vector<string> ans;
	for(string i:path1){
		ans.push_back("1"+i);
	}
	for(string i:path2){
		ans.push_back("2"+i);
	}
	for(string i:path3){
		ans.push_back("3"+i);
	}
return ans;
}

//question -> getmazepath.
//aryan approach is that i have expectation that for smaller grid it will give me answers 
// i just need to add the one step extra which is "h" to all horizontal paths 
// and "v" to all the vertical paths.
//for eg for a 3x3 grid i have faith that my 2x2 grid will give me all the paths from top left to top right.
//i just need to add one extra horizontal and vertical step to 2x2 paths.
vector<string> getmazepath(int sr,int sc,int dr,int dc){
//base case is when we complete the grid.
	//horizontal base case
	if(sr==dr && sc==dc){
		vector<string> base_result;
		base_result.push_back("");
		return base_result;
	}

//i have faith that getmazepath(sr,sc+1,dr,dc) will give me all paths for horizontal paths.
vector<string> horizontal_paths;
if(sc<dc){
 horizontal_paths=getmazepath(sr,sc+1,dr,dc);
}
//i have faith that getmazepath(sr+1,sc,dr,dc) will give me all paths for vertical paths.
vector<string>vertical_paths;
if(sr<dr){
vertical_paths=getmazepath(sr+1,sc,dr,dc);	
}

vector<string> ans;
for(string s : horizontal_paths){
	ans.push_back("h"+s);
}
for(string s: vertical_paths){
	ans.push_back("v"+s);
}
return ans;
}
//question -> we need to print path with jumps
//the trick in this questio is that we can go dignolly also.
//also we can make jumps of any size but less than the horizontal and vertica value.
vector<string> mazepathwithjump(int sr,int sc,int dr,int dc){
//base case is when we complete the grid.
	//horizontal base case
	if(sr==dr && sc==dc){
		vector<string> base_result;
		base_result.push_back("");
		return base_result;
	}
vector<string> ans;
//for vertical path each jump size will depend upon the dc-sc
vector<string> horizontal_paths;
for(int movesize=1;movesize<=dc-sc;++movesize){
 horizontal_paths=mazepathwithjump(sr,sc+movesize,dr,dc);
 for(string s:horizontal_paths){
 	ans.push_back("h"+movesize+s);
 }
}
//for vertical path each jump size will depend upon the dc-sc
vector<string>vertical_paths;
for(int movesize=1;movesize<=dr-sr;++movesize){
 vertical_paths=mazepathwithjump(sr+movesize,sc,dr,dc);
 for(string s:vertical_paths){
 	ans.push_back("v"+movesize+s);
 }
}
//for getting diagnoal path i must calculate step size effectively.
vector<string>diagnol_paths;
for(int movesize=1;movesize<=dr-sr&& movesize<=dc-sc;++movesize){
 diagnol_paths=mazepathwithjump(sr+movesize,sc+movesize,dr,dc);
 for(string s:diagnol_paths){
 	ans.push_back("d"+movesize+s);
 }
}
return ans;
}
//why storing of string in vector was enefficient is bcoz it will become a huge value which is  unable to store.
//for eg if length of string is 31= then total space taken is -> pow(2,31) x 31=31gb 
//Print vale questions which are similar to the logic of get vale questions.
//question->just need to print the given question things without storing. it.
// Aryan approch is that you just need to reach the base condition and from coming to that base condtion.
//start printing it rather than storing it in a vector or other data strucutre.

void printss(string ques,string ans){
	//base case.
	if(ques.size()==0){
		cout<<ans<<endl;
		return;
	}
	char ch=ques[0];
	string roq=ques.substr(1);
	//i have faith that printss(s-1) will print the subsequences for smaller substring.
	//in one call add " " to the string
	printss(roq,ans+"");
	printss(roq,ans+ch);

}

//aryan approach is that every chracter has individual choices
//task is do find the remaining string when a character is coming.

void printPermutations(string str, string asf){
    // write your code here
    if(str.size()==0){
    	cout<<asf<<endl;
    	return;
    }
    
    for(int i=0;i<str.size();++i){
    	char ch=str[i];
    	string roq1=str.substr(0,ch);
    	string roq2=str.substr(ch+1);
    	string roq=roq1+roq2;
    	printPermutations(roq,asf+ch);

    }

}

//question -> print encodings that every number is mapped with a charater you have to print it.
//main part is to find the mapped character and check for certain edge cases.
//for eg you cannot have more than 26 length character and 0 does not mapped with any character.
//below ('a' +(character value in int)-1 will give the right position of alphabet)
void printEncoding(string str, string asf){
    // write your code here
       if(str.length() == 0){
        cout<<asf<<endl;
        return;
    }
    
    if(str[0] == '0'){
        return;
    }
//substr(0,1) will fetch you one chracter
    string s1 = str.substr(0,1);
    string ros1 = str.substr(1);
    printEncoding(ros1,asf + (char)(stoi(s1) + 'a' - 1));
//if string is more than two length

    if(str.length() >= 2){
        string s2 = str.substr(0,2);
        string ros2 = str.substr(2);
        if(stoi(s2) <= 26)
        printEncoding(ros2,asf + (char)(stoi(s2) + 'a' - 1));
    }
    
}
int Recur(int n)
   {
       if(n==1)
          return 1;
       else
          return n*Recur(n-1);
   }
  
   int Check(long a)
   {
       if(a%10!=0)
       {
          return (int)a%10;
       }
       a=a/10;
       //a=a%1000000000;
       return (int)Check(a);
     //return a%10;    
   }
int lastNon0Digit(int N){
     long a=Recur(N);
     int p=Check(a);
     return p;
   }
   
  //fact digit sum gfg
//couldn't understood question.
  vector<int> FactDigit(int N)
{
    // Code here
    vector<int>ans;
    vector<int>fact(10,0);
    debug(fact)
    fact[0]=1;
    for(int i=1;i<10;i++){
        fact[i]=i*fact[i-1];
        debug(fact[i])
    }
    for(int i=9;i>=1;i--){
        while(N>=fact[i]){
            ans.push_back(i);
            N-=fact[i];
            debug(N)
            debug(fact[i])
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
} 
//question -> print patter using recursion.
//when (n-5) is calling it will automatially work for a[i]+5;
  void solve(int N, vector<int> &v){
        if(N<=0){
            v.push_back(N);
            return;
        }
        v.push_back(N);
        solve(N-5, v);
        v.push_back(N);
    }
    vector<int> pattern(int N){
        // code here
        vector<int> v;
        solve(N,v);
        return v;
    }
int main(){
#ifndef ONLINE_JUDGE
	freopen("error.txt","w",stderr);
#endif

cout<<1<<endl;
cout<<2<<endl;
}