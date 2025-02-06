#include <bits/stdc++.h>
using namespace std;

int n, num1, num2, num3;
int a[2187][2187];

void count(int x, int y, int l){
    int check = a[x][y];
    bool cut = false;

    for (int i=x; i<x+l; i++){
        for (int j=y; j<y+l; j++){
            if (a[i][j] ^ check){   // xor -> 두 값이 다르면 1
                cut = true;
                break;
            }
        }
        if (cut) break;
    }

    if (cut){
        count(x         , y         , l/3);
        count(x + l/3   , y         , l/3);
        count(x + l/3*2 , y         , l/3);
        count(x         , y + l/3   , l/3);
        count(x + l/3   , y + l/3   , l/3);
        count(x + l/3*2 , y + l/3   , l/3);
        count(x         , y + l/3*2  , l/3);
        count(x + l/3   , y + l/3*2  , l/3);
        count(x + l/3*2 , y + l/3*2  , l/3);
    }else{
        switch (check){
            case -1: num1++; break;
            case 0: num2++; break;
            case 1: num3++; break;
        }
    }

}

int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    
    count(0, 0, n);
    cout << num1 << "\n" << num2 << "\n" << num3;
    
    return 0;
}