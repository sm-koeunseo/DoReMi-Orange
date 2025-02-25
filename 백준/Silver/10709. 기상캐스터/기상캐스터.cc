#include <bits/stdc++.h>
using namespace std;

int a[100][100], b[100][100];
int h, w;
string s;

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> h >> w;
    for (int i=0; i<h; i++){
        cin >> s;
        for (int j=0; j<w; j++)
            a[i][j] = s[j];
    }

    for (int i=0; i<h; i++){
        int j=0, v=0;
        bool flag = true;
        for (; a[i][j] != 'c' && j < w; j++){
            b[i][j] = -1;
        }
        while(j < w){
            b[i][j] = v++;
            for (j=j+1; a[i][j] != 'c' && j < w; j++, v++){
                b[i][j] = v;
            }
            v = 0;
        }
    }

    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}