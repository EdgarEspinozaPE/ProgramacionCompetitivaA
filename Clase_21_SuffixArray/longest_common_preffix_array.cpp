#include <iostream>
#include <string>
#include<vector>
#include<map>

using namespace std;

vector<int> lcpa(string& s) {

    int n = s.length();
    map<string, int> ord;

    vector<int> lcp(n, 0);

    string sub = "";

    for (int i = n - 1; i >= 0; i--) {
        sub = s[i] + sub;
        ord[sub] = i;
    }

    int k = 0, cont = 0;
    lcp[0] = 0;
    string prev;
    for (auto j : ord) {
        if (k >= 1) {
            cont = 0;
            string temp = j.first;
            for (int i = 0; i < temp.length(); i++) {
                if (i >= prev.length()) {
                    lcp[k] = cont;
                    break;
                }
                if (prev[i] == temp[i]) {
                    cont++;
                }
                else {
                    lcp[k] = cont;
                    break;
                }

            }
        }
        prev = j.first;
        k++;
    }

    return lcp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s = "ABABBAB";
    vector<int> r = lcpa(s);

    cout << s << "\n";
    for (int i = 0; i < s.size(); i++) {
        cout << r[i] << " ";
    }

    return 0;
}