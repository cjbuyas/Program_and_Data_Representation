// Charles Buyas, cjb8qf, 1-22-17, xToN.cpp
#include <iostream>
using namespace std;

int xton(int n, int x) {
int total = n;
if (n == 0) {
return 1;
}
else {
return x * xton((n-1), x);
 }
}

int main() {
int n, x;
cin >> x;
cin >> n;
cout <<  xton(n, x) << endl;
return 0;
}
