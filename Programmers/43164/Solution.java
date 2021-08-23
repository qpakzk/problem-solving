// https://programmers.co.kr/learn/courses/30/lessons/43164

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {

    private boolean[] visited;
    private List<List<String>> answers;

    public void backtrace(String origin, String[][] tickets, List<String> path, int depth) {
        if (depth > tickets.length) {
            answers.add(new ArrayList<>(path));
            return;
        }

        for (int i = 0; i < tickets.length; i++) {
                if (visited[i] || !tickets[i][0].equals(origin))
                continue;

            visited[i] = true;
            path.add(tickets[i][1]);
            backtrace(tickets[i][1], tickets, path, depth + 1);
            path.remove(path.size() - 1);
            visited[i] = false;
        }
    }

    public String[] solution(String[][] tickets) {
        answers = new ArrayList<>();
        visited = new boolean[tickets.length];

        Arrays.sort(tickets,
                (a, b) -> a[0].equals(b[0]) ? a[1].compareTo(b[1]) : a[0].compareTo(b[0]));

        List<String> path = new ArrayList<>();
        String origin = "ICN";
        path.add(origin);
        backtrace(origin, tickets, path, 1);

        return answers.get(0).toArray(String[]::new);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String[][] tickets1 = {{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}};
        System.out.println(Arrays.toString(solution.solution(tickets1)));

        String[][] tickets2 = {{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL","SFO"}};
        System.out.println(Arrays.toString(solution.solution(tickets2)));
    }
}
