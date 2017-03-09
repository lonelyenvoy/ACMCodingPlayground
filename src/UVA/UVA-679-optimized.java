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
        final int maxDepth = 20;
        final int treeNodeAmount = 1 << maxDepth;
        boolean[] tree = new boolean[treeNodeAmount];

        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int depth = sc.nextInt();
            int ballAmount = sc.nextInt();

            for (int i = 0; i < treeNodeAmount; i++) {
                tree[i] = false;
            }
            int deadline = 1 << depth - 1;
            int pos = 0;
            for (int i = 0; i < ballAmount; i++) {
                pos = 0;
                while (pos < deadline) {
                    tree[pos] = !tree[pos];
                    if (tree[pos]) {
                        pos = 2 * pos;
                    } else {
                        pos = 2 * pos + 1;
                    }
                }
            }
            System.out.println(pos);
        }
        sc.close();
    }
}