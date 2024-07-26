#include <iostream>
using namespace std;

int paperW=0, paperB=0; // 종이 개수
bool paper[128][128];   // 최대 길이 만큼 paper 생성

// 가로 시작, 세로 시작, 길이
void count(int x, int y, int l){
    bool check = paper[x][y]; // 가장 첫 번째 칸 확인
    bool cut = false;

    // 주어진 칸만큼 첫 번째 칸과 같은 값인지 확인
    for (int i=x; i<x+l; i++)
        for (int j=y; j<y+l; j++){
            if (paper[i][j] ^ check){   // xor -> 두 값이 다르면 1
                cut = true;
                break;
            }
        }

    if (cut){
        count(x     , y     , l/2);
        count(x     , y+l/2 , l/2);
        count(x+l/2 , y     , l/2);
        count(x+l/2 , y+l/2 , l/2);
    } else {  // 모든 칸이 같은 색의 종이라면 해당 색의 개수 증가
        if(check)
            paperB++;
        else
            paperW++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;
    for (int i=0; i<num; i++)
        for (int j=0; j<num; j++){
            cin >> paper[i][j];
        }

    count(0, 0, num);
    cout << paperW << endl;
    cout << paperB << endl;

    return 0;
}