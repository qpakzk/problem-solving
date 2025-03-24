import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        Work[] works = new Work[n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            works[i] = new Work(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())); 
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            int profit = 0;
            int day = i;
            while (day < n && day + works[day].t - 1 < n) {
                profit += works[day].p;
                day += works[day].t;
            }
            result = Math.max(profit, result);
        }

        System.out.println(result);
    }

    static class Work {
        int t;
        int p;

        Work(int t, int p) {
            this.t = t;
            this.p = p;
        }
    }
}