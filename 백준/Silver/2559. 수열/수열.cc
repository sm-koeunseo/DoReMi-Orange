#include <bits/stdc++.h>
using namespace std;

int main(){
    int day, seq, temp[100000];
    cin >> day >> seq;

    for (int i=0; i<day; i++){
        cin >> temp[i];
    }

    int sum=0, max=INT_MIN;
    for (int i=0; i<seq; i++){
        sum += temp[i];
    }
    if (sum > max) max = sum;
    for (int i=seq; i<day; i++){
        sum -= temp[i-seq];
        sum += temp[i];
        if (sum > max) max = sum;
    }

    cout << max;
}