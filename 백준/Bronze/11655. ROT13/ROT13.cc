#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    
    for (int i=0; i<s.length(); i++){
        if (s[i] > 64 && s[i] < 91){
            if (s[i] + 13 > 90) s[i] = s[i] + 13 - 26;
            else                s[i] = s[i] + 13;
        }else if (s[i] > 96 && s[i] < 123){
            if (s[i] + 13 > 122)    s[i] = s[i] + 13 - 26;
            else                    s[i] = s[i] + 13;
        }
        cout << s[i];
    }
}