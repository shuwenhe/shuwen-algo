#include<bits/stdc++.h>

using namespace std;

int main(){
	string s;

	cin >> s;

	int c = 0;

	for(int i = 0;i < s.length();i++){
		if(s[i] == '1'){
			c++;
		}
	}
	cout<<c<<endl;

	return 0;
}
