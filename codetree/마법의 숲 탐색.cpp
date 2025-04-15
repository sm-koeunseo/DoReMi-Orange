// 마법의 숲 탐색
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
// #define MAX_L 70

int r, c, k;    // 숲의 크기, 정령의 수
int y, d;       // 골렘의 열정보, 출구 위치
int a[73][70];  // 숲, 출구 위치 확인
bool isExit[73][70], visited[73][70];
int dx[] = {-1, 0, 1, 0};   // 북, 동, 남, 서 방향
int dy[] = {0, 1, 0, -1};
int res;

// x, y로 이동 가능한지 확인
bool canGo(int x, int y){   // 중심 기준으로 상하좌우 한칸씩 존재 (-1 적용)
                            // x행: 북쪽의 여유칸 3칸 고려
    bool flag = (x < r + 2) && (y > 0 && y < c - 1);
    flag = flag && (a[x-1][y-1] == 0);  // 이동 전 좌표
    flag = flag && (a[x-1][y] == 0);
    flag = flag && (a[x-1][y+1] == 0);
    flag = flag && (a[x][y-1] == 0);
    flag = flag && (a[x][y] == 0);
    flag = flag && (a[x][y+1] == 0);
    flag = flag && (a[x+1][y] == 0);
    return flag;
}

bool inRange(int x, int y){
    return 2 < x && x < r + 3 && -1 < y && y < c;
}

int getDis(int x, int y){
    int result = x;
    memset(visited, 0, sizeof(visited));

    queue<pair<int,int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while(q.size()){
        pair<int, int> cur = q.front(); q.pop();
        for (int k=0; k<4; k++) {
            int nx = cur.first + dy[k], ny = cur.second + dx[k];
            if (inRange(nx, ny) && !visited[nx][ny] // 골렘 내부 이동 가능, 탈출구라면 다른 골렘으로 이동 가능
                && (a[nx][ny] == a[cur.first][cur.second] || (a[nx][ny] != 0 && isExit[cur.first][cur.second]))) {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
                result = max(result, nx);
            }
        }
    }

    return result;
}

void down(int x, int y, int d, int id){
    if (canGo(x + 1, y)){                   // 아래
        down(x + 1, y, d, id);
    } else if (canGo(x + 1, y - 1)){
        down(x + 1, y - 1, (d+3)%4, id);    // 왼쪽 아래 (출구 270도 회전)
    } else if (canGo(x + 1, y + 1)){
        down(x + 1, y + 1, (d+1)%4, id);    // 오른쪽 아래 (출구 90도 회전)
    } else {    // 아래, 왼쪽, 오른쪽 회전 불가능할때
        // 숲의 위치 밖이라면 모든 골렘 퇴장
        if (!inRange(x-1, y-1) || !inRange(x+1, y+1))
            for (int i=0;i<r+3;i++)
                for (int j=0;j<c;j++){
                    a[i][j] = 0;
                    isExit[i][j] = false;
                }
        else {  // 골렘 위치 고정
            a[x][y] = id;
            for (int i=0; i < 4; i++)
                a[x+dx[i]][y+dy[i]] = id;
            isExit[x+dx[d]][y+dy[d]] = true;
            res += getDis(x, y) - 3 + 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c >> k;
    k++;
    for (int id=1; id<k; id++){
        cin >> y >> d;
        y--;
        down(0, y, d, id);
    }

    cout << res;
    return 0;
}