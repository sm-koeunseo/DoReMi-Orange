#include <bits/stdc++.h>
using namespace std;

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    string a, b;

    cin >> n;
    while(n--){
        map<string, int> map;
        cin >> m;
        for (int i=0; i<m; i++){
            cin >> a >> b;
            map[b]++;
        }
        long long ret = 1;
        for (auto c : map){
            ret *= ((long long)c.second + 1);
        }
        ret --;
        cout << ret << "\n";
    }
}
