#include <bits/stdc++.h>
using namespace std;
#include<math.h>
#include <string>
#define ll long long
#define ONLiNE_JUDGE                  \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);


int add(int n);
int main() {
ONLiNE_JUDGE
int n;
cout << "Enter a positive integer: "<<endl;
cin >> n;
cout << "Sum = " << add(n);
return 0;
}
int add(int n) {
if(n != 0)
return n + add(n - 1);
return 0;
}