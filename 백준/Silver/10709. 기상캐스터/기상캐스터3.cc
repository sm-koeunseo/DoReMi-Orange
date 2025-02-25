#include <bits/stdc++.h>
using namespace std;

int a[100][100];
int h, w;
string s;

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> h >> w;
    for (int i=0; i<h; i++){
        cin >> s;
        for (int j=0; j<w; j++){
            if (s[j] == '.') a[i][j] = -1;
            else a[i][j] = 0;
        }
    }

    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            if (a[i][j] == 0){
                cout << "0 ";
                int cnt = 1;
                while(a[i][j+1] == -1){
                    cout << cnt++ << " ";
                    j++;
                }
            } else {
                cout << "-1 ";
            }
        }
        cout << "\n";
    }
    
    return 0;
}