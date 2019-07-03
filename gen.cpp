#include<bits/stdc++.h>

using namespace std;

int32_t main(){
	srand(time(0));
	int n=rand()%10000+1;
	cout << n << endl;
	while(n--)
		cout << rand()%2;
}