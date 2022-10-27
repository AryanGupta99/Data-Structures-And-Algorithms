#include <bits/stdc++.h>
using namespace std;
#include <string>
#define ll long long
#define ONLINE_JUDGE                  \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int main()
{
ONLINE_JUDGE

int number1,number2;
cin>>number1>>number2;
cout<<"before swapping "<< number1<< " "<<number2<<endl;
int temp=number1;
number1 = number2;

number2=temp;
cout<<"After swapping " << number1<<" "<<number2<<endl;
}
