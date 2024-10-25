#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	vector<int> a;
	cin>>n;
	for(int i = 30; i >= 0; i--){
		int power = 1<<i;
		if(n >= power){
			a.push_back(power);

			n -= power;
		}
	}
	for(int i = 0; i <= a.size();i++){
		if(a[i] != 0){
			cout<<a[i];
			cout<<' ';
		}
	}
	return 0;
}
