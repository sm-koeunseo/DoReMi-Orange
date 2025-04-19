#include <string>
#include <cstring>

using namespace std;

int solution(int n, int w, int num) {
    int a[100][10];
    memset(a, 0, sizeof(a));
    int answer = 0;
    
    int r=0, c=-1;
    int tr, tc;
    bool dir = true;
    for (int i=0; i<n; i++){
        if (dir){   // 순방향
            if (c == w - 1){    // 끝에 도달했을 때
                r++;
                dir = false;
            } else {
                c++;
            }
        }else {     // 역방향
            if (c == 0){
                r++;
                dir = true;
            } else {
                c--;
            }
        }     
        
        if (i + 1 == num){
            tr = r;
            tc = c;
        }
        a[r][c] = i+1;
    }
    
    while(true){
        if (a[tr][tc] > 0){
            answer++;
            tr++;
        }else{
            break;
        }
    }
    
    return answer;
}