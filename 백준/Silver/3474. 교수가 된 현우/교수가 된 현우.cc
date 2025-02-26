#include <bits/stdc++.h>
using namespace std;

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, c2, c5;
    cin >> n;

    for (int i=0; i<n; i++){ 
        cin >> m;
        c2 = 0;
        c5 = 0;
 
        for (int j=2; j<=m; j*=2)
            c2 += m / j;
 
        for (int j=5; j<=m; j*=5)
            c5 += m / j;

        cout << min(c2, c5) << "\n";
    }
    
    return 0;
}