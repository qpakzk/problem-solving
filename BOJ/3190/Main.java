// https://www.acmicpc.net/problem/3190

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {

    private static final int SNAKE = -1;

    private static final int BLANK = 0;

    private static final int APPLE = 1;

    public static boolean isOver(int x, int y, int n, int[][] board) {
        return x < 1 || x > n || y < 1 || y > n || board[x][y] == SNAKE;
    }

    public static void rotate(int d[], char direction) {
        int dx = d[0];
        int dy = d[1];

        if (dx == 0 && dy == 1) {
            if (direction == 'D') {
                d[0] = 1;
                d[1] = 0;
            } else {
                d[0] = -1;
                d[1] = 0;
            }
        } else if (dx == 1 && dy == 0) {
            if (direction == 'D') {
                d[0] = 0;
                d[1] = -1;
            } else {
                d[0] = 0;
                d[1] = 1;
            }
        } else if (dx == 0 && dy == -1) {
            if (direction == 'D') {
                d[0] = -1;
                d[1] = 0;
            } else {
                d[0] = 1;
                d[1] = 0;
            }
        } else {
            if (direction == 'D') {
                d[0] = 0;
                d[1] = 1;
            } else {
                d[0] = 0;
                d[1] = -1;
            }
        }
    }
    public static void main(String[] args) throws IOException {
        int[][] board = new int[101][101];

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int k = Integer.parseInt(br.readLine());


        for (int i = 0; i < k; i++) {
            String input = br.readLine();
            StringTokenizer st = new StringTokenizer(input, " ");
            int row = Integer.parseInt(st.nextToken());
            int col = Integer.parseInt(st.nextToken());
            board[row][col] = APPLE;
        }

        int l = Integer.parseInt(br.readLine());
        char[] rotate = new char[10000];
        for (int i = 0; i < l; i++) {
            String input = br.readLine();
            StringTokenizer st = new StringTokenizer(input, " ");
            int t = Integer.parseInt(st.nextToken());
            char d = st.nextToken().charAt(0);
            rotate[t] = d;
        }

        board[1][1] = SNAKE;

        int[] d = {0, 1};
        LinkedList<Coordinate> snake = new LinkedList<>();
        snake.add(new Coordinate(1, 1));

        int time = 0;
        int headX = 1;
        int headY = 1;
        while (true) {
            time++;

            headX += d[0];
            headY += d[1];

            if (isOver(headX, headY, n, board)) break;

            snake.add(new Coordinate(headX, headY));
            if (board[headX][headY] != APPLE) {
                Coordinate coordinate = snake.removeFirst();
                board[coordinate.getX()][coordinate.getY()] = BLANK;
            }
            board[headX][headY] = SNAKE;

            if (rotate[time] != 0) {
                rotate(d, rotate[time]);
            }
        }

        System.out.println(time);
    }

    static class Coordinate {
        private final int x, y;

        public Coordinate(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }
    }
}
