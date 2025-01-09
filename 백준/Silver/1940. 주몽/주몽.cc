#include <bits/stdc++.h>
using namespace std;

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a[15000] = {0}, cnt = 0;
    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    for (int i=0; i<n-1; i++){
        if (a[i] < 0) continue;
        for(int j=i+1; j<n; j++){
            if (a[i] + a[j] == m){
                cnt++;
                a[i] = INT_MIN;
                a[j] = INT_MIN;
            }
        }
    }
    cout << cnt;
}