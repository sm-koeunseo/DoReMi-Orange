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
        bool check = true;
        for (char c : str){
            if (c == ')'){
                if (s.empty() || s.top() == '['){
                    check = false;
                    break;
                }else s.pop();
            }
            if (c == ']') {
                if (s.empty() || s.top() == '(') {
                    check = false;
                    break;
                }else s.pop();
            }
            if(c == '(') s.push(c);
            if(c == '[') s.push(c);
        }

        if (check && s.empty()) cout << "yes\n";
        else cout << "no\n";

        getline(cin, str);
    }

    return 0;
}