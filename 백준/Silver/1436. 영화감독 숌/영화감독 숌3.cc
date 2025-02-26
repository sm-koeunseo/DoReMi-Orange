#include <bits/stdc++.h>
using namespace std;

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, i=666;
    cin >> n;

    for(;;i++){
        if (to_string(i).find("666") != string::npos) n--;
        if (n == 0) break;
    }
    cout << i;
    
    return 0;
}