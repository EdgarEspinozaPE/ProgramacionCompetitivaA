#include <iostream>
#include <string>
#include<vector>
#include<map>

using namespace std;

void lcs(string& s) {

    int n = s.length(), m = 0;
    map<string, pair<int, int>> ord;
    string sub = "";

    for (int i = 0; i < n; i++) {
        if (isdigit(s[i])) {
            m++;
            continue;
        }
        ord[s.substr(i)] = make_pair(m, 0);
    }

    int k = 0, cont = 0;
    string prev;
    for (auto& j : ord) {
        if (k >= 1) {
            cont = 0;
            string temp = j.first;
            for (int i = 0; i < temp.length(); i++) {
                if (i >= prev.length() && !isdigit(prev[i]) && !isdigit(temp[i])) {
                    j.second.second = cont;
                    break;
                }
                if (prev[i] == temp[i]) {
                    cont++;
                }
                else {
                    j.second.second = cont;
                    break;
                }

            }
        }
        prev = j.first;
        k++;
    }
    cout << "lcp \t string \t color\n";
    for (auto j : ord) {
        cout << j.second.second << "\t" << j.first << " \t" << j.second.first << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> s = { "AABC","BCDC","BCDE","CDED" };

    string arr;
    for (int i = 0; i < 4; i++) {
        arr += s[i] + to_string(i);
    }

    cout << "AABC, BCDC, BCDE, CDED" << "\n";
    lcs(arr);
    
}