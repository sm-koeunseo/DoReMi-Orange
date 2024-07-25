#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void star(int i, int j, int num){
    if( i%3 == 1 && j%3 == 1)
        cout << ' ';
    else
        cout << '*';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;
    for (int i=0; i<num; i++){
        for (int j=0; j<num; j++)
            star(i, j, num);
        cout<<endl;
    }
}