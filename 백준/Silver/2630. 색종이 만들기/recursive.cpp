#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int paperW=0, paperB=0; // 종이 개수
bool paper[128][128];   // 최대 길이 만큼 paper 생성

// 가로 시작, 가로 끝, 세로 시작, 세로 끝
void count(int is, int il, int js, int jl){
    bool check = paper[is][js]; // 가장 첫 번째 칸 확인
    bool flag = true;

    // 주어진 칸만큼 첫 번째 칸과 같은 값인지 확인
    for (int i=is; i<il && flag; i++)
        for (int j=js+1; j<jl; j++){
            if (paper[i][j] ^ check){   // xor -> 두 값이 다르면 1
                flag = false;
                break;
            }
        }
    
    if (flag){  // 모든 칸이 같은 색의 종이라면 해당 색의 개수 증가
        if(check)
            paperB++;
        else
            paperW++;
    } else {
        if ((il-is) != 1) { // 두 칸 이상이라면 다시 반으로 쪼개서 확인
            count(is        , (is+il)/2 , js        , (js+jl)/2 );
            count(is        , (is+il)/2 , (js+jl)/2 , jl        );
            count((is+il)/2 , il        , js        , (js+jl)/2 );
            count((is+il)/2 , il        , (js+jl)/2 , jl        );
        }
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

    count(0, num, 0, num);
    cout << paperW << endl;
    cout << paperB << endl;

    return 0;
}