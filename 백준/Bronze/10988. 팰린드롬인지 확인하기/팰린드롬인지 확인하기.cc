#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, t;
    cin >> s;

    t = s;
    reverse(t.begin(), t.end());
    
    if (t == s) cout << 1;
    else        cout << 0;
    
    return 0;
}