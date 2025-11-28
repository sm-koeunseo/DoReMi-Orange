class Solution {
    
    int check(int[] numbers, int depth, int num, int sum, int target){
        if (depth == num){
            if (sum == target) return 1;
            else return 0;
        }
        
        return check(numbers, depth+1, num, sum + numbers[depth], target)
            + check(numbers, depth+1, num, sum - numbers[depth], target);
    }
        
        
    public int solution(int[] numbers, int target) {
        return check(numbers, 0, numbers.length, 0, target);
    }
}