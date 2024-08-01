#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 보드의 상태에서 가장 긴 연속된 사탕의 길이를 계산하는 함수
int findLongestCandy(const vector<string>& board, int N) {
    int maxCandy = 1;
    
    for (int i = 0; i < N; ++i) {
        // 각 행에서 가장 긴 연속 부분 계산
        int rowCandy = 1;
        for (int j = 1; j < N; ++j) {
            if (board[i][j] == board[i][j - 1]) {
                rowCandy++;
            } else {
                rowCandy = 1;
            }
            maxCandy = max(maxCandy, rowCandy);
        }
        
        // 각 열에서 가장 긴 연속 부분 계산
        int colCandy = 1;
        for (int j = 1; j < N; ++j) {
            if (board[j][i] == board[j - 1][i]) {
                colCandy++;
            } else {
                colCandy = 1;
            }
            maxCandy = max(maxCandy, colCandy);
        }
    }
    
    return maxCandy;
}

int main() {
    int N;
    cin >> N;
    
    vector<string> board(N);
    for (int i = 0; i < N; ++i) {
        cin >> board[i];
    }
    
    int maxCandies = 0;
    
    // 모든 칸에 대해 인접한 칸과 교환 시도
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            // 오른쪽과 교환
            if (j + 1 < N && board[i][j] != board[i][j + 1]) {
                swap(board[i][j], board[i][j + 1]);
                maxCandies = max(maxCandies, findLongestCandy(board, N));
                swap(board[i][j], board[i][j + 1]); // 원상복귀
            }
            // 아래쪽과 교환
            if (i + 1 < N && board[i][j] != board[i + 1][j]) {
                swap(board[i][j], board[i + 1][j]);
                maxCandies = max(maxCandies, findLongestCandy(board, N));
                swap(board[i][j], board[i + 1][j]); // 원상복귀
            }
        }
    }
    
    cout << maxCandies << endl;
    
    return 0;
}
