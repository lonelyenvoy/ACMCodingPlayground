/**
 * Created by LonelyEnvoy on 2017-4-5.
 * 历届试题 国王的烦恼
 * Keywords: 并查集
 * Limits: High run-time efficiency required
 */

// 注意：本题不能用Scanner输入，否则会超时

import java.util.*;
import java.math.*;
import java.io.*;

class Node {
    int from, to, days;
}

public class Main {

    static int[] set;

    static void init(int n) {
        set = new int[n+1];
        for (int i = 0; i <= n; i++) {
            set[i] = -1;
        }
    }

    static int find(int u) {
        while (set[u] >= 0) {
            u = set[u];
        }
        return u;
    }

    static boolean union(int u1, int u2) {
        u1 = find(u1);
        u2 = find(u2);
        if (u1 != u2) {
            if (set[u1] < set[u2]) { // u1's size is bigger than u2
                set[u2] = u1;
                set[u1]--;
            } else {
                set[u1] = u2;
                set[u2]--;
            }
            return true;
        }
        return false;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] strs = reader.readLine().split(" ");
        int n = Integer.parseInt(strs[0]);
        int m = Integer.parseInt(strs[1]);

        init(n);
        Node[] bridges = new Node[m];
        for (int i = 0; i < m; i++) {
            bridges[i] = new Node();
            strs = reader.readLine().split(" ");
            bridges[i].from = Integer.parseInt(strs[0]);
            bridges[i].to = Integer.parseInt(strs[1]);
            bridges[i].days = Integer.parseInt(strs[2]);
        }
        Arrays.sort(bridges, new Comparator<Node>() {
            public int compare(Node n1, Node n2) {
                return n2.days - n1.days;
            }
        });

        int fightCount = 0;
        int preDay = -1;
        for (int i = 0; i < m; i++) {
            if (union(bridges[i].from, bridges[i].to) && preDay != bridges[i].days) {
                fightCount++;
                preDay = bridges[i].days;
            };
        }

        System.out.println(fightCount);

        reader.close();
    }
}
