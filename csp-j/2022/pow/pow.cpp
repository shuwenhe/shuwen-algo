#include<iostream>

using namespace std;

int main(){
    long long a,b;
    cin>>a>>b;
    long long result = 1;
    for(int i = 1;i<=b;i++){
        result*=a;
        if(result>1e9){
            cout<<-1;
            return 0;
        }
    }
    cout<<result;
}
