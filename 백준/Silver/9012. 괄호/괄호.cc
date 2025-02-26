#include <bits/stdc++.h>
using namespace std;

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        string str;
        cin >> str;
        stack<char> s;
        bool check = true;

        for (char c : str){
            if (c == '(') s.push(c);
            else {
                if (s.empty()){
                    check = false;
                    break;
                } else s.pop();
            }
        }

        if (check && s.empty()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}