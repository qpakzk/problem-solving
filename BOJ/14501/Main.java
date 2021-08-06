// https://www.acmicpc.net/problem/14501

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] T = new int[N + 1];
        int[] P = new int[N + 1];
        int[] salary = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            T[i] = Integer.parseInt(st.nextToken());
            P[i]= Integer.parseInt(st.nextToken());
        }

        int maxSalary = 0;
        for (int i = 1; i <= N; i++) {
            if (i + T[i] > N + 1) {
                continue;
            }

            salary[i] += P[i];

            for (int j = i + T[i]; j <= N; j++) {
                salary[j] = Math.max(salary[j], salary[i]);
            }

            if (maxSalary < salary[i]) {
                maxSalary = salary[i];
            }
        }

        System.out.println(maxSalary);
    }
}
