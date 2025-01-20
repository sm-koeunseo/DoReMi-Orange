#include <bits/stdc++.h>
using namespace std;

int a[5][5];
bool v[5];

void go(int from){
    v[from] = 1;
    cout << from << '\n';
    for (int i=0; i<5; i++){
        if(v[i]) continue;
        if(a[from][i]){
            go(i);
        }
    }
}

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    a[1][2] = 1; a[1][3] = 1; a[3][4] = 1;
    a[2][1] = 1; a[3][1] = 1; a[4][3] = 1;

    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            if (a[i][j] && v[i] == 0){
                go(i);
            }
        }
    }
}