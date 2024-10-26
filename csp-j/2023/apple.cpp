#include <iostream>

using namespace std;

int main(){
	long long n, day = 0,pick = 0x3f3f3f3f;
	cin>>n;
	while(n){
		day++;
		if((n - 1) % 3 == 0)
			pick = min(pick,day);
		n -= (n - 1)/3 + 1;
	}
	cout<<day<<" "pick<<endl;
	return 0;
}
