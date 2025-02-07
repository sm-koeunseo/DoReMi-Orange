#include <bits/stdc++.h>
using namespace std;

int n, k, c;
string str;

int main(){
    cin >> n >> k >> str;

    for (int i=0; i<n; i++){
        if (str[i] == 'P'){
            for (int j = i-k; j<=i+k; j++){
                if (j < 0) continue;
                if (str[j] == 'H'){
                    c++;
                    str[j] = 'h';
                    break;
                }
            }
        }
    }

    cout << c;
    return 0;
}
