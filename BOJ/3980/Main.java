// https://www.acmicpc.net/problem/3980

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    private static final int SIZE = 11;

    private static int[][] map;

    private static int max;

    private static boolean[] visited;

    static void backtrace(int player, int sum, int depth) {
        if (depth >= SIZE) {
            max = Math.max(max, sum);
            return;
        }

        for (int i = 0; i < SIZE; i++) {
            if (map[player][i] != 0 && !visited[i]) {
                visited[i] = true;
                sum += map[player][i];
                backtrace(player + 1, sum, depth + 1);
                sum -= map[player][i];
                visited[i] = false;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int c = Integer.parseInt(br.readLine());

        while (c-- > 0) {
            map = new int[SIZE][SIZE];
            for (int i = 0; i < SIZE; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine(), " ");
                for (int j = 0; j < SIZE; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            max = 0;
            visited = new boolean[SIZE];
            backtrace(0, 0, 0);
            System.out.println(max);
        }
    }
}
