import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] profits = new int[n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(st.nextToken());
            int p = Integer.parseInt(st.nextToken());

            if (i + t - 1 < n) {
                profits[i] += p;
                for (int j = i + t; j < n; j++) {
                    profits[j] += p;
                }
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            result = Math.max(profits[i], result);
        }

        System.out.println(result);
    }
}