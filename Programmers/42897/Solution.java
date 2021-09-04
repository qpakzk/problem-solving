// https://programmers.co.kr/learn/courses/30/lessons/42897

public class Solution {
    public int solution(int[] money) {
        // dp[0]: can visit money[0]
        // dp[1]: shouldn't visit money[1]
        int[][] dp = new int [2][money.length];

        dp[0][0] = money[0];
        dp[0][1] = Math.max(dp[0][0], money[1]);

        dp[1][1] = money[1];

        final int lastIndex = money.length - 1;
        for (int i = 2; i < lastIndex; i++) {
            dp[0][i] = Math.max(dp[0][i - 2] + money[i], dp[0][i - 1]);
        }

        for (int i = 2; i <= lastIndex; i++) {
            dp[1][i] = Math.max(dp[1][i - 2] + money[i], dp[1][i - 1]);
        }

        return Math.max(dp[0][lastIndex - 1], dp[1][lastIndex]);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        int[] money = {1, 2, 3, 1};
        System.out.println(solution.solution(money));
    }
}
