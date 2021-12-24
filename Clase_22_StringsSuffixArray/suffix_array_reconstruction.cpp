#include <iostream>
#include <string>

using namespace std;

void Reconstruction(int l, int s) {
    int pos;
    string word, suffix;
    word = "";
    for (int i = 0; i < l; i++) word += "*";

    int flag = 1;
    for (int i = 0; i < s; i++) {
        cin >> pos >> suffix;
        pos--;
        for (int j = 0; j < suffix.size(); j++) {
            if (suffix[j] == '*') {
                break;
            }
            else if (word[j + pos] == '*' || word[j + pos] == suffix[j]) {
                word[j + pos] = suffix[j];
            }
            else {
                flag = 0;
                break;
            }
        }
        for (int j = 0; j < suffix.size(); j++) {
            if (suffix[suffix.size() - j - 1] == '*') {
                break;
            }
            else if (word[l - j - 1] == '*' || word[l - j - 1] == suffix[suffix.size() - j - 1]) {
                word[l - j - 1] = suffix[suffix.size() - j - 1];
            }
            else {
                flag = 0;
                break;
            }
        }
    }
    for (int i = 0; i < l; i++) {
        if (word[i] == '*') {
            flag = 0;
        }
    }
    if (flag==0) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        cout << word << "\n";
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int l, s;
        cin >> l >> s;
        Reconstruction(l, s);
    }
    return 0;
}