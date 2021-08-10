// https://www.acmicpc.net/problem/2174

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static final String WALL_MESSAGE = "Robot %d crashes into the wall\n";
    static final String ROBOT_MESSAGE = "Robot %d crashes into robot %d\n";

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        int[][] map = new int[b + 1][a + 1];

        st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        List<Robot> robots = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            char d = st.nextToken().charAt(0);
            map[y][x] = i + 1;
            switch (d) {
                case 'N':
                    robots.add(new Robot(x, y, 0, 1));
                    break;
                case 'S':
                    robots.add(new Robot(x, y, 0, -1));
                    break;
                case 'W':
                    robots.add(new Robot(x, y, -1, 0));
                    break;
                case 'E':
                    robots.add(new Robot(x, y, 1, 0));
                    break;
            }
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int robotId = Integer.parseInt(st.nextToken());
            char command = st.nextToken().charAt(0);
            int loop = Integer.parseInt(st.nextToken());

            while (loop-- > 0) {
                if (command == 'L') {
                    robots.get(robotId - 1).rotateLeft();
                } else if (command == 'R') {
                    robots.get(robotId - 1).rotateRight();
                } else {
                    int prevX = robots.get(robotId - 1).x;
                    int prevY = robots.get(robotId - 1).y;
                    robots.get(robotId - 1).forward();

                    int curX = robots.get(robotId - 1).x;
                    int curY = robots.get(robotId - 1).y;

                    if (curX > a || curY > b || curX < 1 || curY < 1) {
                        System.out.printf(WALL_MESSAGE, robotId);
                        return;
                    }

                    if (map[curY][curX] > 0) {
                        System.out.printf(ROBOT_MESSAGE, robotId, map[curY][curX]);
                        return;
                    }

                    map[prevY][prevX] = 0;
                    map[curY][curX] = robotId;
                }
            }
        }

        System.out.println("OK");
    }

    static class Robot {
        int x;
        int y;
        int dx;
        int dy;

        public Robot(int x, int y, int dx, int dy) {
            this.x = x;
            this.y = y;
            this.dx = dx;
            this.dy = dy;
        }

        public void rotateLeft() {
            if (dx == 1 && dy == 0) { // E
                dx = 0; dy = 1; // N
            } else if (dx == -1 && dy == 0) { // W
                dx = 0; dy = -1; // S
            } else if (dx == 0 && dy == 1) { // N
                dx = -1; dy = 0; // W
            } else { // S
                dx = 1; dy = 0; // E
            }
        }

        public void rotateRight() {
            if (dx == 1 && dy == 0) { // E
                dx = 0; dy = -1; // S
            } else if (dx == -1 && dy == 0) { // W
                dx = 0; dy = 1; // N
            } else if (dx == 0 && dy == 1) { // N
                dx = 1; dy = 0; // E
            } else { // S
                dx = -1; dy = 0; // W
            }
        }

        public void forward() {
            x += dx;
            y += dy;
        }
    }
}
