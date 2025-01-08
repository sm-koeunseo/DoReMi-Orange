#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v, v2;
    int a[9], sum = 0, i, j, t1, t2;

    for (i=0; i<9; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a+9);

    for (i=0; i<9; i++)
        for (j=0; j<9; j++){
            if (sum - a[i] - a[j] == 100){
                t1 = i;
                t2 = j;
            }
        }

    for (int k=0; k<9; k++){
        if (k != t1 && k != t2)
            cout << a[k] << "\n";
    }
}
