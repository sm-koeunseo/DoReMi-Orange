#include <iostream>
#include <cstring>
using namespace std;

int n, m, k;                    // 크기, 사람수, 시간
int a[10][10], b[10][10];       // 지도, 회전용 임시지도
pair<int, int> location[10];    // 참가자 위치
pair<int, int> exits;           // 출구 위치
int res;                        // 총 이동 거리
int sx, sy, sz;                 // 회전 정사각형 정보
bool arrived[10];
int arrivedCount;


void MoveOne() {
    for(int i = 0; i < m; i++) {
        if (arrived[i]) continue;   // 이미 도착했다면 생략
        
        if(location[i].first != exits.first) {  // 행 이동
            int nx = location[i].first;
            int ny = location[i].second;

            if(exits.first > nx) nx++;
            else nx--;

            if(!a[nx][ny]) {    // 벽이 아니면 이동 가능
                location[i].first = nx;
                location[i].second = ny;
                res++;
                continue;       // 이동했다면 다음 참가자 이동시키기
            }
        }

        if(location[i].second != exits.second) {    // 열 이동
            int nx = location[i].first;
            int ny = location[i].second;

            if(exits.second > ny) ny++;
            else ny--;

            if(!a[nx][ny]) {
                location[i].first = nx;
                location[i].second = ny;
                res++;
            }
        }
    }
}

void FindSquare() {
    for(int ss = 2; ss <= n; ss++) {    // 정사각형 길이
        for(int x1 = 0; x1 < n - ss + 1; x1++) {
            for(int y1 = 0; y1 < n - ss + 1; y1++) {
                int x2 = x1 + ss - 1;
                int y2 = y1 + ss - 1;

                if(!(x1 <= exits.first && exits.first <= x2 && y1 <= exits.second && exits.second <= y2))
                    continue;   // 출구 없다면 다음 정사각형 확인

                bool found = false;
                for(int l = 0; l < m; l++) {
                    if(arrived[l]) continue;    // 이미 탈출한 사람은 체크하지 않음
                    if(x1 <= location[l].first && location[l].first <= x2 && y1 <= location[l].second && location[l].second <= y2)
                        found = true;
                }

                if(found) {
                    sx = x1;
                    sy = y1;
                    sz = ss;
                    return;
                }
            }
        }
    }
}

void RotateSquare() {
    memset(b, 0, sizeof(b));

    // 임시 저장 & 벽 강도 감소
    for (int i=0; i<sz; i++) for (int j=0; j<sz; j++){
        int x = sx + i;
        int y = sy + j;
        if (a[x][y] > 0) a[x][y]--;
        b[i][j] = a[x][y];
    }

    // 회전
    for (int i=0; i<sz; i++) for (int j=0; j < sz; j++)
        a[sx + j][sy + sz - 1 - i] = b[i][j];
}

void RotatePin() {
    for(int i = 0; i < m; i++) {
        if(arrived[i]) continue;
        int x = location[i].first;
        int y = location[i].second;
        if(sx <= x && x < sx + sz && sy <= y && y < sy + sz) {
            int ox = x - sx, oy = y - sy;
            int rx = oy, ry = sz - ox - 1;
            location[i] = make_pair(rx + sx, ry + sy);
        }
    }

    int x = exits.first;
    int y = exits.second;
    if(sx <= x && x < sx + sz && sy <= y && y < sy + sz) {
        int ox = x - sx, oy = y - sy;
        int rx = oy, ry = sz - ox - 1;
        exits = make_pair(rx + sx, ry + sy);
    }
}

int main() {
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)for(int j = 0; j < n; j++)
        cin >> a[i][j];
    
    for(int i = 0; i < m; i++) {
        cin >> location[i].first;
        cin >> location[i].second;
        location[i].first--;
        location[i].second--;
    }

    cin >> exits.first;
    cin >> exits.second;
    exits.first--;
    exits.second--;

    while(k--) {
        // 참가자 이동
        MoveOne();

        // 탈출 처리
        for (int i=0; i<m; i++){
            if(arrived[i]) continue;
            if (location[i].first == exits.first && location[i].second == exits.second){
                arrived[i] = true;
                arrivedCount++;
            }
        }
        if (arrivedCount == m) break;

        // 정사각형 구하기
        FindSquare();

        // 회전
        RotateSquare();
        RotatePin();
    }

    cout << res << "\n";
    cout << exits.first + 1 << " " << exits.second + 1;
}
