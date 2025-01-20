#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> v;
    v.push_back(1); // 2*1 크기에서는 2*1 한가지만 가능
    v.push_back(2); // 2*2 크기에서는 2*1 두개 or 1*2 두개로 두가지 가능
    // 2*3 크기라면? 2*2의 두가지 경우의 수에 1*2를 붙일 수 있음 -> 4-1(중복) = 3
    // 2*4 크기는 2*2에 2*2를 붙이기, 2*3에 1*2를 붙이기로 5개 
    for (int i=2; i<n; i++)
        v.push_back((v[i-1] + v[i-2])%10007);
    cout << v[n-1];
    return 0;
}