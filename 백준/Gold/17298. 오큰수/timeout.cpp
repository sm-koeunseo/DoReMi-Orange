#include <bits/stdc++.h>
using namespace std;

int a[1000000], n, tmp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    for (int i=0; i<n-1; i++){
        bool check = true;
        for (int j=i+1; j<n; j++){
            if (a[i] < a[j]) {
                cout << a[j] << " ";
                check = false;
                break;
            }
        }
        if (check)
            cout << "-1 ";
    }
    cout << "-1";
}