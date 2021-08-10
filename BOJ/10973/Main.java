// https://www.acmicpc.net/problem/10973

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int[] nums = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(st.nextToken());
        }

        int i = nums.length - 1;
        while (i > 0 && nums[i - 1] < nums[i]) {
                i -= 1;
        }

        if (i == 0) {
            System.out.println(-1);
            return;
        }

        int j = nums.length;
        while (i < j && nums[j - 1] > nums[i - 1]) {
            j -= 1;
        }
        swap(nums, i - 1, j - 1);

        i += 1;
        j = nums.length;
        while (i < j) {
            swap(nums, i - 1, j - 1);
            i += 1;
            j -= 1;
        }

        Arrays.stream(nums).forEach((num) -> System.out.print(num + " "));
    }

    public static void swap(int[] nums, int index1, int index2) {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
}
