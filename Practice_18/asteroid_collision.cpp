#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> out;
    int n = asteroids.size();
    deque<int> colli;
    colli.push_back(asteroids[0]);
    bool flag = false;
    for (int i = 1; i < n; i++) {
        if (colli.empty()) {
            colli.push_back(asteroids[i]);
            continue;
        }

        int m = colli.back();
        if (m > 0 && asteroids[i] < 0) {
            if (m == (asteroids[i] * -1)) {
                colli.pop_back();
            }
            else if (m < (asteroids[i] * -1)) {
                colli.pop_back();
                flag = false;

                while (!colli.empty()) {
                    if (colli.back() > 0) {
                        if (colli.back() < (asteroids[i] * -1)) {
                            colli.pop_back();
                        }
                        else if (colli.back() > (asteroids[i] * -1)) {
                            flag = true;
                            break;
                        }
                        else if (colli.back() == (asteroids[i] * -1)) {
                            flag = true;
                            colli.pop_back();
                            break;
                        }
                    }
                    else break;
                }

                if (flag == false) colli.push_back(asteroids[i]);
            }
            continue;
        }
        colli.push_back(asteroids[i]);
    }

    while (!colli.empty()) {
        out.push_back(colli.front());
        colli.pop_front();
    }
    return out;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> asteroids = { -2,-2,1,-2 };
    vector<int> result = asteroidCollision(asteroids);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}