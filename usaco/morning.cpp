#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int minTimeToEnterPin(const string& pin) {
    int currentPos = 1; 
    int minTime = 0;

    for (char digit : pin) {
        int targetPos = digit - '0';
        int diff = abs(targetPos - currentPos);

        minTime += min(diff, 10 - diff) + 1;
        currentPos = targetPos;
    }

    return minTime;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string pin;
        cin >> pin;

        int time = minTimeToEnterPin(pin);
        cout << time << endl;
    }

    return 0;
}






