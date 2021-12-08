#include <iostream>
#include <string>
#include<vector>

using namespace std;

vector<int> SuffixArray(string& s) {
    vector<int> sa(s.size(),0);
    sa[0] = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] < s[sa[i-1]]) {
            sa[i] = sa[i - 1];
            sa[i - 1] = i;
        }
        else 
            sa[i] = i;
    }
    return sa;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s = "camel";
    vector<int> r = SuffixArray(s);
    for (int i = 0; i < s.size(); i++) {
        cout << r[i] << " ";
    }

    return 0;
}