#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
bool v[100001] = {false};
int d[100001] = {0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    if (n == k) {
        cout << 0;
        return 0;
    }

    q.push(n);
    v[n] = true;

    while(q.size()){
        int x = q.front(); q.pop();

        for (int y : { x - 1, x + 1, x * 2}){
            if (y > -1 && y < 100001 && !v[y]){
                v[y] = true;
                d[y] = d[x] + 1;
                q.push(y);

                if (y == k){
                    cout << d[y];
                    return 0;
                }
            }
        }

    }
}