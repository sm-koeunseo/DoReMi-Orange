#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;   //  기준값, 등장값 배열
    int a[4], c[4] = {0,0,0,0};

    int n, m, tmp;
    cin >> n >> m;
    cin >> s;
    for(int i=0; i<4; i++){
        cin >> tmp;     // 기준값은 초과 조건에 걸리게 1씩 감소
        a[i] = tmp - 1;
    }

    int cnt=0;
    for (int i=0; i<m; i++){
        switch(s[i]){   // index 0~m는 직접 실행 (초기값 생성)
            case 'A': c[0]++; break;
            case 'C': c[1]++; break;
            case 'G': c[2]++; break;
            case 'T': c[3]++; break;
        }
    }
    if (c[0] > a[0] && c[1] > a[1] && c[2] > a[2] && c[3] > a[3])
        cnt++;  // 조건에 부합하면 cnt 증가
    
    int l=0, r=m;
    while (r < n){  // l값은 빼고 r값은 더하며 한 칸씩 옆으로 이동하며 개수 세기
        switch(s[l]){
            case 'A': c[0]--; break;
            case 'C': c[1]--; break;
            case 'G': c[2]--; break;
            case 'T': c[3]--; break;
        }
        switch(s[r]){
            case 'A': c[0]++; break;
            case 'C': c[1]++; break;
            case 'G': c[2]++; break;
            case 'T': c[3]++; break;
        }
        if (c[0] > a[0] && c[1] > a[1] && c[2] > a[2] && c[3] > a[3])
            cnt++;
        
        l++; r++;
    }

    cout << cnt;
}