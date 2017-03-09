/**
 * Created by LonelyEnvoy on 2017-3-9.
 * Dropping Balls
 * Keywords: 二叉树
 *
 * A better solution
 *
 */

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNext()) {
            final int depth = sc.nextInt();
            int nthBallPassingThisNode = sc.nextInt(); // ballAmount
            int node = 1;
            for (int i = 1; i != depth; i++) {
                if (nthBallPassingThisNode % 2 == 0) { // turn right
                    nthBallPassingThisNode /= 2;
                    node = 2 * node + 1;
                } else { // turn left
                    nthBallPassingThisNode = (nthBallPassingThisNode + 1) / 2;
                    node = 2 * node;
                }
            }
            System.out.println(node);
        }
        sc.close();
    }
}