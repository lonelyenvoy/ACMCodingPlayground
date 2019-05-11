/*
 * Created by lonelyenvoy on 2019-05-11.
 * Map Sum Pairs
 * Keywords: prefix tree
 */

class Node {
    public int value;
    public int sum;
    public Node[] next;
}

class MapSum {
    private static final int MAX = 255;
    private Node map = new Node();

    public void insert(String key, int val) {
        insert(key, val, key.length(), map, 0);
    }

    public int sum(String prefix) {
        int len = prefix.length();
        Node root = map;
        for (int i = 0; i < len; i++) {
            Node node = root.next[prefix.charAt(i)];
            if (node.next == null) {
                return (i == len - 1) ? node.value : 0;
            }
            root = node;
        }
        return root.sum;
    }

    private int insert(String key, int val, int len, Node root, int depth) {
        if (depth == len) {
            int delta = val - root.value;
            root.value = val;
            root.sum += delta;
            return delta;
        }
        if (root.next == null) {
            root.next = new Node[MAX];
            for (int i = 0; i < MAX; i++) root.next[i] = new Node();
        }
        Node target = root.next[key.charAt(depth)];
        int delta = insert(key, val, len, target, depth + 1);
        root.sum += delta;
        return delta;
    }
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
