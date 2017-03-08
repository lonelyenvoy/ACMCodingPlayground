/**
 * Created by LonelyEnvoy on 2017-3-8.
 * Train Problem I
 * Keywords: 栈，队列，深度优先搜索
 *
 * 由于本算法中嵌套了递归，所以产生了大量全局变量，复用性、可维护性和可读性较差。
 *
 * changelog
 * 2017-3-8: 采取计算完毕一组数据后立即输出的方法，同时避免使用String.format()，提高效率
 */

import java.util.*;
import java.math.*;
import java.io.*;

public class Main {

    private static int trainAmount = 0;
    private static Deque<Integer> entrance = new ArrayDeque<>();
    private static Stack<Integer> transfer = new Stack<>();
    private static Deque<Integer> exit = new ArrayDeque<>();

    private static String expectedResult;
    private static boolean hasFoundExpectedResult = false;

    private static Deque<Boolean> trainTrace = new ArrayDeque<>(); // true: train in; false: train out

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            trainAmount = sc.nextInt();
            String trains = sc.next();
            expectedResult = sc.next();
            for (int i = 0; i < trainAmount; i++) {
                entrance.addLast(trains.charAt(i) - '0');
            }
            dfs();
            if (!hasFoundExpectedResult) {
                System.out.println("No.");
                System.out.println("FINISH");
            }
            // clear
            entrance.clear();
            hasFoundExpectedResult = false;
        }
    }

    private static void dfs() {
        if (hasFoundExpectedResult) {
            return;
        }
        if (entrance.isEmpty() && transfer.empty() && exit.size() == trainAmount) {
            outputIfResultMatchExpect();
            return;
        }
        if (!entrance.isEmpty()) {
            Integer i = entrance.removeFirst();
            transfer.push(i);
            trainTrace.addLast(true); // train in
            dfs();
            // backtrack
            transfer.pop();
            entrance.addFirst(i);
            trainTrace.removeLast(); // withdraw train in
        }
        if (!transfer.empty()) {
            Integer i = transfer.pop();
            exit.addLast(i);
            trainTrace.addLast(false); // train out
            dfs();
            // backtrack
            exit.removeLast();
            transfer.push(i);
            trainTrace.removeLast(); // withdraw train out
        }
    }

    private static void outputIfResultMatchExpect() {
        boolean isMatched = true;
        Iterator itr = exit.iterator();
        for (int i = 0; i < exit.size(); i++) {
            if (expectedResult.charAt(i) != itr.next().toString().charAt(0)) {
                isMatched = false;
                break;
            }
        }
        if (isMatched) {
            hasFoundExpectedResult = true;
            System.out.println("Yes.");
            for (boolean aTrace : trainTrace) {
                if (aTrace) {
                    System.out.println("in");
                } else {
                    System.out.println("out");
                }
            }
            System.out.println("FINISH");
        }
    }
}