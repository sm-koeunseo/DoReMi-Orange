#include <iostream>
#include <algorithm>
using namespace std;

char c[6562][6562];

void print(int num, int n, int m){
    if (num == 3){
        c[n][m] = '*';
        c[n][m+1] = '*';
        c[n][m+2] = '*';
        c[n+1][m] = '*';
        c[n+1][m+1] = ' ';
        c[n+1][m+2] = '*';
        c[n+2][m] = '*';
        c[n+2][m+1] = '*';
        c[n+2][m+2] = '*';
    } else {
        for (int i=0; i<num/3; i++){
            print(num/3, n+i, m+i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;
    print(num, 0, 0);

    // 출력
}