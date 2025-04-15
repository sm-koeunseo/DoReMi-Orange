#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int N, Q;
int a[16][16];          // 배양 용기
int b[16][16];          // 임시 배양 용기
bool v[16][16];         // 방문 여부
bool alive[51] = {0};   // 미생물의 생존 여부
int mCnt[51];           // 각 미생물의 크기
pair<int,int> t1, t2;   // 미생물 좌표
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool mCheck[51][51];    // 면적 계산 시 확인 여부 체크
int ret = 0;


void dfs(int x, int y, int id){
    for (int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if (a[nx][ny] != id || v[nx][ny]) continue;
        v[nx][ny] = true;
        dfs(nx, ny, id);
    }
}

void mEntrance(int id){
    cin >> t1.first >> t1.second;
    cin >> t2.first >> t2.second;

    //cout << "\n\n(" << t1.first << "," << t1.second << ")";
    //cout << " (" << t2.first << "," << t2.second << ")\n";

    vector<int> del;
    bool delCheck[Q+1] = {0};
    for (int i=t1.first; i<t2.first; i++){
        for (int j=t1.second; j<t2.second; j++){
            if(a[i][j] > 0){    // 기존에 미생물이 있던 공간이라면
                if (!delCheck[a[i][j]]){
                    del.push_back(a[i][j]);
                    delCheck[a[i][j]] = true;
                }
                mCnt[a[i][j]]--;
            }
            a[i][j] = id;
            alive[id] = true;
            mCnt[id]++;
        }
    }

    for (int t=0; t<del.size(); t++){
        int id2 = del[t];
        int count=0;

        memset(v, 0, sizeof(v));
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                if (a[i][j] == id2 && !v[i][j]){
                    v[i][j] = true;
                    dfs(i, j, id2);
                    count++;
                }
            }
        }

        if (count != 1){    // 미생물이 아예 사라지거나 둘 이상으로 나뉘었을 때
            alive[id2] = false;
            if (count > 1){
                for (int i=0; i<N; i++){
                    for (int j=0; j<N; j++)
                        if (a[i][j] == id2){
                            a[i][j] = 0;
                            mCnt[id2]--;
                        }
                    if (mCnt[id2] == 0) break;
                }
            }
        }
    }
}

bool isSet(int x, int y, int id, int minX, int minY){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (a[i][j] == id) {
                int nx = x + (i - minX);
                int ny = y + (j - minY);

                if (nx < 0 || ny < 0 || nx >= N || ny >= N) return false;
                if (b[nx][ny] != 0) return false;
            }
        }
    }

    return true;
}

void mSet(int x, int y, int id, int minX, int minY){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (a[i][j] == id) {
                int nx = x + (i - minX);
                int ny = y + (j - minY);
                b[nx][ny] = id;
            }
        }
    }
}

void mMove(){
    priority_queue<pair<int,int>> q;
    for (int i=1; i<Q; i++)
        if(alive[i])
            q.push({mCnt[i], -i});

    memset(b, 0, sizeof(b));
    while(q.size()){
        int id = -1 * q.top().second;
        int size = q.top().first;
        q.pop();
        //cout << "id: " << id <<"\n";

        bool found = false;
        int minX = N, minY = N; // 좌상단 좌표 구하기기
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (a[i][j] == id) {
                    if (i < minX || (i == minX && j < minY)) {
                        minX = i;
                        minY = j;
                    }
                }
            }
        }

        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                if (isSet(i, j, id, minX, minY)){
                    mSet(i, j, id, minX, minY);
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        if (!found){ // 위치 못 한 거 삭제
            alive[id] = false;
            mCnt[id] = 0;
        }
    }

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            a[i][j] = b[i][j];
        }
    }
}

void getResult(int x, int y, int id){
    v[x][y] = true;

    for (int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if (v[nx][ny]) continue;

        int nid = a[nx][ny];
        if (nid == 0) continue;
        if (id == nid){
            v[nx][ny] = true;
            getResult(nx, ny, nid);
        } else if (id != nid && !mCheck[id][nid]){
            mCheck[id][nid] = true;
            mCheck[nid][id] = true;
            ret += mCnt[id] * mCnt[nid];
        }
    }
}

void mResult(){
    ret = 0;
    memset(v, 0, sizeof(v));
    memset(mCheck, 0, sizeof(mCheck));

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if(a[i][j] > 0 && !v[i][j]){
                v[i][j] = true;
                getResult(i, j, a[i][j]);
            }
        }
    }
    cout << ret << "\n";
}

void mPrint(){
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++)
            cout << a[i][j];
        cout << "\n";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> Q; Q++;
    for (int t=1; t<Q; t++){
        mEntrance(t);
        //mPrint();

        mMove();
        //mPrint();

        mResult();
    }

    return 0;
}