/**
 * Created by LonelyEnvoy on 2017-3-9.
 * Dropping Balls
 * Keywords: 二叉树
 *
 * 本题是UVA-679的变种，去除了输入中第一行的number of test cases和最后一行的-1
 *
 */

import java.util.*;
import java.math.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        BinTree tree = new BinTree();

        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int depth = sc.nextInt();
            int ballAmount = sc.nextInt();

            tree.create(depth);
            BallDropper dropper = new BallDropper(tree);
            System.out.println(dropper.dropBalls(ballAmount));

            tree.reset();
        }
        sc.close();
    }
}


class BinNode {
    int data;
    BinNode[] child = new BinNode[2];
    boolean flag = false; // false -> turn left, true -> turn right

    public BinNode(int data) {
        this.data = data;
    }

    public void reset() {
        flag = false;
    }
}

class BinTree {
    private BinNode root = new BinNode(1);

    public void create(int depth) {
        create(root, depth, 1);
    }

    private void create(BinNode node, int maxDepth, int currentDepth) {
        if (currentDepth == maxDepth) {
            return;
        }
        int childNumber = 2 * node.data;
        node.child[0] = new BinNode(childNumber);
        node.child[1] = new BinNode(childNumber + 1);
        create(node.child[0], maxDepth, currentDepth + 1);
        create(node.child[1], maxDepth, currentDepth + 1);
    }

    public void output() {
        output(root);
        System.out.println();
    }

    private void output(BinNode node) {
        if (node == null) {
            return;
        }
        System.out.print(node.data + " ");
        output(node.child[0]);
        output(node.child[1]);
    }

    public BinNode getRoot() {
        return root;
    }

    public void reset() {
        root.flag = false;
    }
}

class BallDropper {
    private BinNode treeRoot;

    public BallDropper(BinTree tree) {
        this.treeRoot = tree.getRoot();
    }

    public int dropBalls(int ballAmount) {

        for (int i = 0; i != ballAmount - 1; i++) {
            dropBall(treeRoot);
        }
        return dropLastBall();
    }

    private void dropBall(BinNode node) {
        node.flag = !node.flag;
        if (node.child[0] == null) {
            return;
        }
        if (node.flag) {
            dropBall(node.child[0]);
        } else {
            dropBall(node.child[1]);
        }
    }

    private int dropLastBall() {
        BinNode node = treeRoot;
        while (node.child[0] != null) {
            node.flag = !node.flag;
            if (node.flag) {
                node = node.child[0];
            } else {
                node = node.child[1];
            }
        }
        return node.data;
    }
}