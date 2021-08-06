// https://www.acmicpc.net/problem/1935

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String expression = br.readLine();

        int[] operands = new int[N];
        for (int i = 0; i < N; i++) {
            operands[i] = Integer.parseInt(br.readLine());
        }

        Stack<Double> stack = new Stack<>();
        for (int i = 0; i < expression.length(); i++) {
            char ch = expression.charAt(i);
            if (Character.isLetter(ch)) {
                int index = ch - 'A';
                double operand = operands[index];
                stack.push(operand);
            } else {
                double num2 = stack.pop();
                double num1 = stack.pop();
                double result;
                if (ch == '*') {
                    result = num1 * num2;
                } else if (ch == '+') {
                    result = num1 + num2;
                } else if (ch == '-') {
                    result = num1 - num2;
                } else {
                    result = num1 / num2;
                }
                stack.push(result);
            }
        }

        System.out.printf("%.2f\n", stack.pop());
    }
}
