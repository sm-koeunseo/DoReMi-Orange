#include <bits/stdc++.h>
using namespace std;

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i,n, ret = 0;
    cin >> n;
    for (i=666; ret < n; i++){
        int num = i;
        int cnt = 0;

        while(num > 0){
            if (num % 10 == 6) cnt++;
            else cnt = 0;
            num /= 10;

            if (cnt == 3){
                ret++;
                break;
            }
        }
    }

    cout << i-1;
    
    return 0;
}