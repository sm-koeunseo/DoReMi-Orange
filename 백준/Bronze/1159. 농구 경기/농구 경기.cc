#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a[26] = {0};
    cin >> n;
    string s, r;

    for (int i=0; i<n; i++){
        cin >> s;
        a[s[0] - 'a']++;
    }

    for (int i=0; i<26; i++)
        if (a[i] > 4) r += (i + 'a');
    if (r.size()) cout << r;
    else cout << "PREDAJA";
}