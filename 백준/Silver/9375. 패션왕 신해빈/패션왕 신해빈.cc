#include <bits/stdc++.h>
using namespace std;

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    map<string, int> map;
    string str;
    int sum;

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> m;
        map.clear();
        sum = 1;
        for (int j=0; j<m; j++){
            cin >> str >> str;
            map[str]++;
        }
        for (auto it = map.begin(); it != map.end(); it++) {
            sum *= (it->second + 1);
        }
        sum--;
        cout << sum << "\n";
    }
}