#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[26] = {0,};
    string s;

    cin >> s;
    for(int i=0; i<s.length(); i++){
        a[s[i]-97]++;
    }
    for(int i=0; i<26; i++){
        cout << a[i] << " ";
    }
}