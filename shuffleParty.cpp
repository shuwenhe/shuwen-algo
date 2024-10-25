#include<bits/stdc++.h>
using namespace std;

long long position_of_one(long long n) {
    vector<long long> divisors;
    divisors.push_back(1);
    for (long long i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    long long product = 1;
    for (size_t i = 1; i < divisors.size(); ++i) {
        product *= divisors[i];
    }
    return product;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        cout << position_of_one(n) << endl;
    }
    return 0;
}

