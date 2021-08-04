// https://www.acmicpc.net/problem/3190

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static final int SNAKE = -1;

    static final int BLANK = 0;

    static final int APPLE = 1;

    static int N;

    static int K;

    static int L;

    static int[][] map = new int[101][101];

    static char[] rotate = new char[10000];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        K = Integer.parseInt(br.readLine());

        for (int i = 0; i < K; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            map[x][y] = APPLE;
        }

        L = Integer.parseInt(br.readLine());

        for (int i = 0; i < L; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int t = Integer.parseInt(st.nextToken());
            char d = st.nextToken().charAt(0);
            rotate[t] = d;
        }

        map[1][1] = SNAKE;
        Queue<Coordinate> snake = new LinkedList<>();
        snake.add(new Coordinate(1, 1));

        int[] d = {0, 1};

        int headX = 1, headY = 1;
        int time = 0;
        while (true) {
            time++;

            headX += d[0];
            headY += d[1];

            if (isOver(headX, headY)) break;

            snake.add(new Coordinate(headX, headY));

            if (map[headX][headY] != APPLE) {
                Coordinate remove = snake.remove();
                map[remove.x][remove.y] = BLANK;
            }

            map[headX][headY] = SNAKE;

            if (rotate[time] != 0) {
                rotate(d, rotate[time]);
            }
        }

        System.out.println(time);
    }

    static boolean isOver(int x, int y) {
        return x < 1 || x > N || y < 1 || y > N ||
                map[x][y] == SNAKE;
    }

    static void rotate(int[] d, char rotate) {
        int dx = d[0], dy = d[1];

        if (dx == 0 && dy == 1) {
            if (rotate == 'D') {
                d[0] = 1; d[1] = 0;
            } else {
                d[0] = -1; d[1] = 0;
            }
        } else if (dx == 1 && dy == 0) {
            if (rotate == 'D') {
                d[0] = 0; d[1] = -1;
            } else {
                d[0] = 0; d[1] = 1;
            }
        } else if (dx == 0 && dy == -1) {
            if (rotate == 'D') {
                d[0] = -1; d[1] = 0;
            } else {
                d[0] = 1; d[1] = 0;
            }
        } else {
            if (rotate == 'D') {
                d[0] = 0; d[1] = 1;
            } else {
                d[0] = 0; d[1] = -1;
            }
        }
    }

    static class Coordinate {
        int x;
        int y;

        Coordinate(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
