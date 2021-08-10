// https://www.acmicpc.net/problem/1759

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    private static int L;
    private static int C;
    private static char[] alphabets;
    private static char[] cipher;
    private static boolean[] visited;

    private static int vowels;
    private static int consonants;

    public static void calculate(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowels++;
        } else {
            consonants++;
        }
    }
    public static void dfs(int alphabetIndex, int cipherIndex) {
        if (cipherIndex == L) {
            vowels = 0;
            consonants = 0;

            for (char c : cipher) {
                calculate(c);
            }

            if (vowels >= 1 && consonants >= 2) {
                for (char c : cipher) {
                    System.out.print(c);
                }
                System.out.println();
            }
            return;
        }

        if (alphabetIndex == C) {
            return;
        }

        if (!visited[alphabetIndex]) {
            visited[alphabetIndex] = true;
            cipher[cipherIndex] = alphabets[alphabetIndex];
            dfs(alphabetIndex + 1, cipherIndex + 1);
            visited[alphabetIndex] = false;
        }

        dfs(alphabetIndex + 1, cipherIndex);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        L = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine(), " ");
        alphabets = new char[C];
        for (int i = 0; i < C; i++) {
            alphabets[i] = st.nextToken().charAt(0);
        }

        Arrays.sort(alphabets);
        cipher = new char[L];
        visited = new boolean[C];
        dfs(0, 0);
    }
}
