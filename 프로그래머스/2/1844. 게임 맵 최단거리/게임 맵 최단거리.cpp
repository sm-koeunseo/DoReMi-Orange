#include<vector>
#include<queue>
#include<cstring>
#include <tuple>
using namespace std;

int visited[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int solution(vector<vector<int>> maps)
{
    memset(visited, -1, sizeof(visited));
    
    queue<pair<int,int>> q;
    int ox = maps.size();
    int oy = maps[0].size();
    q.push({ox - 1, oy - 1});
    visited[ox - 1][oy - 1] = 1;
    
    while (q.size()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop(); 
        
        if (x == 0 && y == 0)
            break;
        
        for (int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= ox || ny >= oy) continue;
            if (maps[nx][ny] == 0) continue;
            if (visited[nx][ny] != -1) continue;
            visited[nx][ny] = visited[x][y] + 1;
            q.push({nx, ny});
        }
    }
    
    return visited[0][0];
}