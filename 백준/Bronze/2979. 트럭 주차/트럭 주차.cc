#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    int t[101] = {0,};
    int t1, t2;
    for (int i=0; i<3; i++){
        cin >> t1 >> t2;
        for (int j= t1; j<t2; j++){
            t[j]++;
        }
    }

    int sum = 0;
    for(int i=1; i<101; i++){
        if (t[i] == 1)  sum += a;
        else if (t[i] == 2) sum += b * 2;
        else if (t[i] == 3) sum += c * 3;
    }

    cout << sum;

}