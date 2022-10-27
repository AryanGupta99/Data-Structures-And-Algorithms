#include <bits/stdc++.h>
using namespace std;
#include<math.h>
#include <string>
#define ll long long
#define ONLiNE_JUDGE                  \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);


int calculatePower(int base,int powerRaised);
int main() {
ONLiNE_JUDGE
int base, powerRaised, result;
cout << "Enter base number: ";
cin >> base;
cout << "Enter power number(positive integer): "<<endl;
cin >> powerRaised;
result = calculatePower(base, powerRaised);
cout << base << "^" << powerRaised << " = " << result;
return 0;
}
int calculatePower(int base, int powerRaised)
{
if (powerRaised != 0)
return (base*calculatePower(base, powerRaised-1));
else
return 1;
}