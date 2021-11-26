#include <iostream>
#include <vector>

using namespace std;

void fd(vector<vector<char>>& image, int r1, int s1, int r2, int s2, char old, bool& find) {
    if (r1 < 0 || r1 >= image.size() || s1 < 0 || s1 >= image[r1].size() || image[r1][s1] != old || find == true) {
        return;
    }
    if (r1 == r2 && s1 == s2) {
        find = true;
        return;
    }
    image[r1][s1] = '2';
    fd(image, r1 + 1, s1, r2, s2, old, find);
    fd(image, r1 - 1, s1, r2, s2, old, find);
    fd(image, r1, s1 + 1, r2, s2, old, find);
    fd(image, r1, s1 - 1, r2, s2, old, find);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r = 0, c = 0, x = 0, r1 = 0, s1 = 0, r2 = 0, s2 = 0;
    char d;
    vector<vector<char>> arr;
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        vector<char> op;
        for (int j = 0; j < c; j++) {
            cin >> d;
            op.push_back(d);
        }
        arr.push_back(op);
    }

    cin >> x;

    for (int i = 0; i < x; i++) {
        cin >> r1 >> s1 >> r2 >> s2;
        vector<vector<char>> tmp = arr;
        bool find = false;
        if (tmp[r1 - 1][s1 - 1] == '0') {
            fd(tmp, r1 - 1, s1 - 1, r2 - 1, s2 - 1, '0', find);
            if (find == true) {
                cout << "binary\n";
            }
            else {
                cout << "neither\n";
            }
        }
        else {
            fd(tmp, r1 - 1, s1 - 1, r2 - 1, s2 - 1, '1', find);
            if (find == true) {
                cout << "decimal\n";
            }
            else {
                cout << "neither\n";
            }
        }
    }

    return 0;
}