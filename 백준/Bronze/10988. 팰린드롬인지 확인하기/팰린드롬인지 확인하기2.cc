#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int l = s.length();
    for (int i=0; i<l/2; i++){
        if (s[i] != s[l-1-i]){
            cout << 0;
            return 0;
        }
    }
    cout << 1;
    return 0;
}
