/**
 * Created by LonelyEnvoy on 2017-3-17.
 * 队列操作
 */

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Queue<Integer> q = new LinkedList<>();

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int directive;
        int operand;
        outer: while (n-- > 0) {
            directive = sc.nextInt();
            switch (directive) {
                case 1:
                    operand = sc.nextInt();
                    q.offer(operand);
                    break;
                case 2:
                    if (q.isEmpty()) {
                        System.out.println("no");
                        break outer;
                    }
                    System.out.println(q.poll());
                    break;
                case 3:
                    System.out.println(q.size());
                    break;
            }
        }
        sc.close();
    }
}
