#include <bits/stdc++.h>
using namespace std;

int p, a[1000000], b, c;
long d;

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> p;
    for (int i=0; i<p; i++){
        cin >> a[i];
    }
    cin >> b >> c;

    for (int i=0; i<p; i++){
        int tmp = a[i];
        d++;
        tmp -= b;
        if (tmp / c > 0){
            d += tmp/c;
            tmp %= c;
        }
        if (tmp > 0)
            d++;
    }

    cout << d;

    return 0;
}