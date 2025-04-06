#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int visited[1000001];
int f, s, g, u, d;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> f >> s >> g >> u >> d;

    if (s == g) {
        cout << 0;
        return 0;
    }

    q.push(s);
    visited[s] = 1;
    while(q.size()){
        int x = q.front(); q.pop();

        for (int y : { x + u, x - d}){
            if (y > 0 && y <= f && !visited[y]){
                visited[y] = visited[x] + 1;
                q.push(y);

                if(y == g){
                    cout << visited[y] - 1;
                    return 0;
                }
            }
        }
    }
    cout << "use the stairs";
    return 0;
}