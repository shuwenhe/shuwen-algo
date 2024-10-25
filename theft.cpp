#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> cameras;

    for (int i = 0; i < n; i++) {
        int t, s;
        cin >> t >> s;
        cameras.push_back({t, s});
    }

    sort(cameras.begin(), cameras.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    auto check = [&](int time_limit) -> bool {
        vector<bool> stolen_diamonds(2, false);
        vector<int> disabled_cameras(n, 0);

        for (int time = 1; time <= time_limit; time++) {
            for (int i = 0; i < n; i++) {
                int t = cameras[i].first;
                int s = cameras[i].second;
                if (time > disabled_cameras[i]) {
                    if (t == 1) {
                        if (!stolen_diamonds[0]) {
                            stolen_diamonds[0] = true;
                            disabled_cameras[i] = time + s;
                        }
                    } else if (t == 2) {
                        if (!stolen_diamonds[1] && stolen_diamonds[0]) {
                            stolen_diamonds[1] = true;
                            disabled_cameras[i] = time + s;
                        }
                    } else {
                        if (!stolen_diamonds[0]) {
                            stolen_diamonds[0] = true;
                            disabled_cameras[i] = time + s;
                        } else if (!stolen_diamonds[1]) {
                            stolen_diamonds[1] = true;
                            disabled_cameras[i] = time + s;
                        }
                    }
                }
            }

            if (stolen_diamonds[0] && stolen_diamonds[1]) {
                return true;
            }
        }

        return false;
    };

    int left = 0, right = 2 * n;
    int result = -1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << result << endl;

    return 0;
}
