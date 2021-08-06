// https://www.acmicpc.net/problem/1158

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        List<Integer> list = new LinkedList<>();;
        for (int i = 1; i <= N; i++) {
            list.add(i);
        }

        Queue<Integer> queue = new LinkedList<>();

        int rotate = K - 1;
        while (true) {
            queue.add(list.get(rotate));
            list.remove(rotate);
            if (list.isEmpty()) {
                break;
            }

            int size = list.size();

            rotate--;
            if (rotate < 0) {
                rotate = size - 1;
            }

            rotate += K;
            rotate %= size;
        }

        System.out.print("<");
        System.out.print(queue.remove());
        while (!queue.isEmpty()) {
            System.out.print(", ");
            System.out.print(queue.remove());
        }
        System.out.println(">");

    }
}
