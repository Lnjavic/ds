#include<iostream>
using namespace std;

int main(){
	bool x = false;
	bool y = true;
	bool b = x |= y;
	cout << b;
	return 0;
}