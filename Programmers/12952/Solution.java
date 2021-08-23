// https://programmers.co.kr/learn/courses/30/lessons/12952

public class Solution {
    public boolean isPromising(int row, int[] queen) {
        for (int i = 0; i < row; i++) {
            if (queen[i] == queen[row]
                    || Math.abs(queen[row] - queen[i]) == Math.abs(i - row))
                return false;
        }
        return true;
    }

    public int backtrace(int row, int[] queen) {
        if (row == queen.length) {
            return 1;
        }

        int answer = 0;
        for (int i = 0; i < queen.length; i++) {
            queen[row] = i;
            if (isPromising(row, queen)) {
                answer += backtrace(row + 1, queen);
            }

        }
        return answer;
    }

    public int solution(int n) {
        int[] queen = new int[n];
        return backtrace(0, queen);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.solution(4));
    }
}
