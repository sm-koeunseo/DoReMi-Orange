#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a[26] = {0}, c=0;
    cin >> n;
    string s;

    for (int i=0; i<n; i++){
        cin >> s;
        a[s[0] - 'a']++;
    }

    for (int i=0; i<26; i++)
        if (a[i] > 4) c++;

    if (c > 0){
        for (int i=0; i<26; i++)
            if (a[i] > 4) cout << (char)(i + 'a');
    } else
        cout << "PREDAJA";
}