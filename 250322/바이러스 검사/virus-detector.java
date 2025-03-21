import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int[] customers = Arrays.stream(br.readLine().split(" "))
                            .limit(n)
                            .mapToInt(Integer::parseInt)
                            .toArray();

        StringTokenizer st = new StringTokenizer(br.readLine());
        int leader = Integer.parseInt(st.nextToken());
        int member = Integer.parseInt(st.nextToken());

        long result = Arrays.stream(customers)
                            .mapToLong(customer -> {
                                int count = 1;
                                customer -= leader;

                                if (customer > 0) {
                                    count += (customer / member) + (customer % member > 0 ? 1 : 0);
                                }

                                return count;
                            })
                            .sum();

        System.out.println(result);
    }
}
