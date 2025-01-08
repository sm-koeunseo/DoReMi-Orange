#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, pos;
    string s, ss, se;
 
    cin >> n >> s;
    pos = s.find('*');
    ss = s.substr(0, pos);
    se = s.substr(pos+1);

    for (int i=0; i<n; i++){
        cin >> s;
        if (ss.size() + se.size() > s.size()) cout << "NE\n";
        else{
            if (ss == s.substr(0, ss.size()) && se == s.substr(s.size() - se.size())) cout << "DA\n";
            else cout << "NE\n";
        }
    }

    return 0;
}