class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int[] cloth = new int[n + 1];
        n++;
        
        for (int i=1; i<n; i++) cloth[i] = 1;   // 전체 체육복 할당
        for (int l : lost) cloth[l]--;          // 도난 체육복 감소
        for (int r : reserve) cloth[r]++;       // 여벌 체육복 증가
        
        for (int i=1; i<n; i++){
            if (cloth[i] == 0){ // 체육복 없다면
                if (i - 1 > 0 && cloth[i-1] == 2){  // 왼쪽에서 빌리기
                    cloth[i-1]--;
                    cloth[i]++;
                } else if (i + 1 < n && cloth[i+1] == 2){   // 오른쪽에서 빌리기
                    cloth[i+1]--;
                    cloth[i]++;
                }
            }
        }
        
        int answer = 0;
        for (int i=1; i<n; i++){
            if (cloth[i] > 0) answer++;
        }
        
        return answer;
    }
}