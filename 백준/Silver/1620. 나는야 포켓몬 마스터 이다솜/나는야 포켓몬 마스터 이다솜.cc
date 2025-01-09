#include <bits/stdc++.h>
using namespace std;

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    string s;
    map<string, int> map1;
    // map<int, string> map2;
    string a[100001 ];
    
    cin >> n >> m;
    n++;
    for (int i=1; i<n; i++){
        cin >> s;
        map1[s] = i;
        // map2[i] = s;
        a[i] = s;
    }
    for (int i=0; i <m; i++){
        cin >> s;
        if(atoi(s.c_str()) == 0)
            cout << map1[s] << "\n";
        else
            cout << a[atoi(s.c_str())] << "\n";
    }
}