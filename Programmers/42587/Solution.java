// https://programmers.co.kr/learn/courses/30/lessons/42587

import java.util.*;

public class Solution {

    public int solution(int[] priorities, int location) {
        LinkedList<Pair> list = new LinkedList<>();
        for (int i = 0; i < priorities.length; i++)
            list.add(new Pair(i, priorities[i]));

        Map<Integer, Integer> map = new HashMap<>();
        int order = 1;
        while (!list.isEmpty()) {
            boolean highest = true;
            Pair pair = list.remove();
            for (Pair next : list) {
                if (pair.priority < next.priority) {
                    highest = false;
                    break;
                }
            }

            if (highest) {
                map.put(pair.index, order);
                order++;
            }
            else
                list.addLast(pair);
        }

        return map.get(location);
    }

    static class Pair {
        private final int index;
        private final int priority;

        public Pair(int index, int priority) {
            this.index = index;
            this.priority = priority;
        }

    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        int[] priorities1 = {2, 1, 3, 2};
        int location1 = 2;
        int answer1 = 1;
        if (answer1 != solution.solution(priorities1, location1)) throw new AssertionError();

        int[] priorities2 = {1, 1, 9, 1, 1, 1};
        int location2 = 0;
        int answer2 = 5;
        if (answer2 != solution.solution(priorities2, location2)) throw new AssertionError();
    }
}
