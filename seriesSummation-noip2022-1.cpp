#include <iostream>

using namespace std;

int main(){
	int k;
	cin>>k;
	double s = 0.0;
	int n = 0;
	while(s <= k){
		n++;
		s += 1.0/n;
	}
	cout<<n<<endl;
}
