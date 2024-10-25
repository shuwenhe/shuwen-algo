#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> heights;
	int taotao_height;

	for(int i = 0; i < 10; i++){
		int height;
		cin>>height;
		heights.push_back(height);
	}

	cin>>taotao_height;

	int count = 0;
	for(int height : heights){
		if(height <= taotao_height + 30 ){
			count++;
		}
	}
	cout<<count<<endl;
}
