#include <iostream>

using namespace std;

int main(){
	string s;
	getline(cin,s);
	int count = 0;
	for(char c : s){
		if(c != ' ' && c != '\n'){
			count++;
		}
	}
	cout<<count<<endl;
	return 0;
}
