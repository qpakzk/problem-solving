// https://www.acmicpc.net/problem/2839

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[][] dp = new int[2][5001];
        dp[0][3] = 1;
        dp[1][3] = 0;

        dp[0][4] = -1;
        dp[1][4] = -1;

        dp[0][5] = 0;
        dp[1][5] = 1;

        for (int i = 6; i <= n; i++) {
            int three = -1, five = -1;

            if (i - 3 >= 3 && dp[0][i - 3] >= 0) {
                three = dp[0][i - 3] + dp[1][i - 3] + 1;
            }

            if (i - 5 >= 3 && dp[1][i - 5] >= 0) {
                five = dp[0][i - 5] + dp[1][i - 5] + 1;
            }

            if (three == -1 && five == -1) {
                dp[0][i] = dp[1][i] = -1;
            } else if (three == -1) {
                dp[0][i] = dp[0][i - 5];
                dp[1][i] = dp[1][i - 5] + 1;
            } else if (five == -1) {
                dp[0][i] = dp[0][i - 3] + 1;
                dp[1][i] = dp[1][i - 3];
            } else if (three < five) {
                dp[0][i] = dp[0][i - 3] + 1;
                dp[1][i] = dp[1][i - 3];
            } else {
                dp[0][i] = dp[0][i - 5];
                dp[1][i] = dp[1][i - 5] + 1;
            }
        }

        int result;
        if (dp[0][n] == -1) {
            result = -1;
        } else {
            result = dp[0][n] + dp[1][n];
        }

        System.out.println(result);
    }
}
