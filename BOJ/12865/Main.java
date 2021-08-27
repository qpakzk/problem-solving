// https://www.acmicpc.net/problem/12865

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static class Item {
        int w;
        int v;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        Item[] items = new Item[n + 1];

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            items[i] = new Item();
            items[i].w = Integer.parseInt(st.nextToken());
            items[i].v = Integer.parseInt(st.nextToken());
        }

        int[][] dp = new int[n + 1][k + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = j >= items[i].w
                        ? Math.max(dp[i - 1][j], dp[i - 1][j - items[i].w] + items[i].v)
                        : dp[i - 1][j];
            }
        }

        System.out.println(dp[n][k]);
    }
}
