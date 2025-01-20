#include <bits/stdc++.h>
using namespace std;

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt[26] = {0}, odd=0, tmp=-1;
    string str;

    cin >> str;
    for (int i=0; i<str.length(); i++){
        cnt[str[i]-'A']++;
    }
    for (int i=0; i<26; i++){
        if (cnt[i] % 2 == 1){
            odd++;
            tmp = i;
        }
        if (odd > 1){
            cout << "I'm Sorry Hansoo";
            return 0;
        }
    }
    for (int i=0; i<26; i++){
        for (int j=0; j<cnt[i]/2; j++){
            cout<<(char)('A' + i);
        }
    }
    if (tmp != -1){
        cout << (char)('A' + tmp);
    }
    for (int i=25; i>-1; i--){
        for (int j=0; j<cnt[i]/2; j++){
            cout<<(char)('A' + i);
        }
    }
}