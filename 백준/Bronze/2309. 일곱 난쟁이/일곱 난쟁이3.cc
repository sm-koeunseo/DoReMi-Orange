#include <bits/stdc++.h>
using namespace std;
pair<int, int> ret;

int main(){
    vector<int> v, v2;
    int a[9], sum = 0, i, j;

    for (i=0; i<9; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a+9);

    for (i=0; i<9; i++)
        for (j=0; j<9; j++){
            if (sum - a[i] - a[j] == 100){
                ret = {i, j};
            }
        }

    for (int k=0; k<9; k++){
        if (k != ret.first && k != ret.second)
            cout << a[k] << "\n";
    }
}
