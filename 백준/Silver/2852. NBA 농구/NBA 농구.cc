#include <bits/stdc++.h>
using namespace std;

int getTime(string &str){
    return stoi(str.substr(0,2)) * 60 + stoi(str.substr(3,2));
}

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str1, str2;
    int win_time[2] = {0};
    int s[3] = {0};
    int t, n;

    cin >> n >> t >> str1;
    s[t]++;

    for (int i=1; i<n; i++){
        cin >> t >> str2;

        if (s[1] > s[2])        win_time[0] += (getTime(str2) - getTime(str1));
        else if (s[2] > s[1])   win_time[1] += (getTime(str2) - getTime(str1));

        s[t]++;
        str1 = str2;
    }

    if (s[1] > s[2])        win_time[0] += (2880 - getTime(str1));
    else if (s[2] > s[1])   win_time[1] += (2880 - getTime(str1));

    for (int i=0; i<2; i++){
        cout.width(2);
        cout.fill('0');
        cout << win_time[i]/60 << ":";
        cout.width(2);
        cout.fill('0');
        cout << win_time[i]%60 << "\n";
    }
    
    return 0;
}