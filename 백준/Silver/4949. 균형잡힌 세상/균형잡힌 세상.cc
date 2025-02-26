#include <bits/stdc++.h>
using namespace std;

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    getline(cin, str);
    while (str != "."){
        stack<char> s;
        bool yes = true;
        for (char c : str){
            if (c == '(' || c == '[') s.push(c);
            else if (c == ')' || c == ']'){
                if (s.empty() || ((c == ')') && (s.top() != '(')) || ((c == ']') && (s.top() != '['))){
                    yes = false;
                    break;
                }
                s.pop();
            }
        }
        if (yes && s.empty()) cout << "yes\n";
        else cout << "no\n";

        getline(cin, str);
    }

    return 0;
}