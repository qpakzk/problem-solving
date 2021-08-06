// https://www.acmicpc.net/problem/9012

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            String input = br.readLine();
            Stack<Character> stack = new Stack<>();
            boolean valid = true;
            for (int i = 0; i < input.length(); i++) {
                char ch = input.charAt(i);
                if (ch == '(')
                    stack.push(ch);
                else {
                    if (stack.isEmpty()) {
                        valid = false;
                        break;
                    }
                    stack.pop();
                }
            }

            if (valid && stack.isEmpty())
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}
