#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 특정 자리 (r, c)에 사람이 있을 때 거리두기 규칙 검사
bool check(vector<string> &room, int r, int c) {
    // 상하좌우 (맨해튼 거리 1)
    int dr1[4] = {-1,1,0,0};
    int dc1[4] = {0,0,-1,1};
    for (int i=0;i<4;i++){
        int nr = r+dr1[i], nc = c+dc1[i];
        if (nr<0||nc<0||nr>=5||nc>=5) continue;
        if (room[nr][nc]=='P') return false; // 바로 옆에 사람
    }

    // 직선 거리 2 (위, 아래, 왼쪽, 오른쪽 두 칸)
    int dr2[4] = {-2,2,0,0};
    int dc2[4] = {0,0,-2,2};
    for (int i=0;i<4;i++){
        int nr = r+dr2[i], nc = c+dc2[i];
        if (nr<0||nc<0||nr>=5||nc>=5) continue;
        if (room[nr][nc]=='P'){ // 두 칸 떨어진 곳에 사람
            int mr = r+dr2[i]/2, mc = c+dc2[i]/2; // 중간 칸
            if (room[mr][mc]!='X') return false;  // 파티션 없으면 위반
        }
    }

    // 대각선 거리 2
    int dr3[4] = {-1,-1,1,1};
    int dc3[4] = {-1,1,-1,1};
    for (int i=0;i<4;i++){
        int nr = r+dr3[i], nc = c+dc3[i];
        if (nr<0||nc<0||nr>=5||nc>=5) continue;
        if (room[nr][nc]=='P'){ // 대각선에 사람
            // 사이 두 칸 모두 파티션이어야 안전
            if (!(room[r][nc]=='X' && room[nr][c]=='X'))
                return false;
        }
    }

    return true; // 모든 검사 통과 → 규칙 지킴
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (auto &room : places){
        bool ok = true;
        for (int r=0;r<5;r++){
            for (int c=0;c<5;c++){
                if (room[r][c]=='P'){
                    if (!check(room,r,c)) {
                        ok=false;
                        break;
                    }
                }
            }
            if (!ok) break;
        }
        answer.push_back(ok?1:0);
    }
    return answer;
}