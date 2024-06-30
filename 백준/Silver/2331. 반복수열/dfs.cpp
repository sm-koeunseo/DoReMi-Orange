#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int visit[236196];
int b;
int cnt = 0;

void dfs(int a){
    int orig = a;
    int next = 0;

    visit[orig-1]++;

    if (visit[orig-1]==3)
        return;

    next = pow(a/1000, b) + pow((a%1000)/100, b) + pow((a%100)/10, b) + pow((a%10), b);

    dfs(next);

    if (visit[orig-1] == 1) cnt++;
}

int main(){
    int a;

    cin >> a >> b;

    dfs(a);

    cout << cnt;
}