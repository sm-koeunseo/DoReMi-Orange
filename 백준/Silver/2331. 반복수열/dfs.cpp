#include <iostream>
#include <cmath>
using namespace std;

int visit[236196];
int b;
int cnt = 0;

void dfs(int a){
    int orig = a;
    int next = 0;

    visit[orig-1]++;

    next = pow(a/1000, b) + pow((a%1000)/100, b) + pow((a%100)/10, b) + pow((a%10), b);
    cout<<next;
    if (visit[next-1]==2) return;
        
    dfs(next);

    if (visit[orig-1]==1) cnt++;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a;
    cin >> a >> b;

    dfs(a);
    cout << cnt;
}