// https://www.acmicpc.net/problem/1256

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static int[][] dp;

    private static String word;

    public static void word(int a, int z, int remain) {
        if (a == 0) {
            for (int i = 0; i < z; i++) {
                word = word.concat("z");
            }
            return;
        }

        if (z == 0) {
            for (int i = 0; i < a; i++) {
                word = word.concat("a");
            }
            return;
        }

        int outcome = dp[a - 1][z];
        if (outcome >= remain) {
            word = word.concat("a");
            word(a - 1, z, remain);
        }
        else {
            word = word.concat("z");
            word(a, z - 1, remain - outcome);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        // dp[n][m]: the number of cases that contain n 'a's and m 'z's
        dp = new int[n + 1][m + 1];

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int j = 0; j <= m; j++) {
            dp[0][j] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = Math.min(dp[i - 1][j] + dp[i][j - 1], 1_000_000_001);
            }
        }

        if (k > dp[n][m]) {
            System.out.println(-1);
            return;
        }

        word = "";
        word(n, m, k);

        System.out.println(word);
    }
}
