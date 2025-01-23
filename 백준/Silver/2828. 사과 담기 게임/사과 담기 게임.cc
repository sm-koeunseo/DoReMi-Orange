#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, bs = 1, be, c, tmp, move = 0;
    cin >> n >> be >> c;

    for (int i=0; i<c; i++){
        cin >> tmp;
        if (tmp >= bs && tmp <= be) continue;
        else if (bs < tmp){
            if (be < tmp)
                tmp -= be;
            else
                tmp -= bs;
            bs += tmp;
            be += tmp;
            move += tmp;
        }else{
            if (bs > tmp)
                tmp = bs - tmp;
            else
                tmp = be - tmp;
            bs -= tmp;
            be -= tmp;
            move += tmp;
        }
    }
    cout << move;
}