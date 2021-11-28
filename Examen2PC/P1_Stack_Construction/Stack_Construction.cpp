//P_1 Stack Construction
//https://open.kattis.com/problems/stack
#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

int stackconstruction(string& msg) {
    int c = 0;
    stack <char> p;
    map<char, int> rep;
    
    rep[msg[0]] = 1;
    p.push(msg[0]);
    c+=2;

    for (int i = 1; i < msg.length(); i++) {
        if (rep[msg[i]] == 1) {
            while (p.top() != msg[i]) {
                rep.erase(p.top());
                p.pop();
                c++;
            }
            c++;
        }
        else {
            p.push(msg[i]);
            rep[msg[i]] = 1;
            c+=2;
        }
    }

    while (!p.empty()) {
        p.pop();
        c++;
    }
    return c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 0;

    cin >> t;
    cin.ignore();
    while(t--) {
        
        string msg;
        getline(cin, msg);
        cout << stackconstruction(msg)<<"\n";
        cin.clear();
    }
    return 0;
}