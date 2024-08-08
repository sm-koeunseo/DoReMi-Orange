#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char c[5][15];
    string t;
    int j;

    for (int i=0; i<5; i++){
        cin >> t;
        for (j=0; j<t.size(); j++){
            c[i][j] = t[j];
        }
        for (; j<15; j++){
            c[i][j] = 0;
        }
    }

    for (int i=0; i<15; i++){
        for (j=0; j<5; j++){
            if (c[j][i] != 0)
                cout << c[j][i];
        }
    }
}