#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

void kmp(string p, int ps, string t, int ts) {
    vector<int> suf(ps);
    int len = 0, i = 1, j = 0, first = 1;
    suf[0] = 0;
    while (i < ps) {
        if (p[i] == p[len]) 
            suf[i++] = ++len;
        else if (len) 
            len = suf[len - 1];
        else suf[i++] = 0;
    }
    i = 0;
    while (i < ts) {
        if (p[j] == t[i]) {
            j++; i++;
        }
        if (j == ps) {
            if (first) 
                first = 0;
            else 
                cout<<" ";
            cout << i - j;
            j = suf[j - 1];
        }
        else if (i < ts && p[j] != t[i]) {
            if (j) 
                j = suf[j - 1];
            else 
                i++;
        }
    }
    cout<<"\n";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string pattern , text;
    
    while (getline(cin,pattern) && pattern.size() >= 0 && getline(cin,text) && text.size() >= 0) {
        kmp(pattern,pattern.size(),text,text.size());
        pattern.clear();
        text.clear();
    }

    return 0;
}


