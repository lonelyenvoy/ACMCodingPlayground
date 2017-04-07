/**
 * Created by LonelyEnvoy on 2017-4-7.
 * Mock Test Problem
 * Keywords: 数论
 * Source: 蓝桥杯大赛辅导视频-百度传课-第五讲：整数的基本性质与运用
 * See: https://www.chuanke.com/?mod=school&act=show&do=course&sid=8197723
 */

// 注意：此算法需要较长时间才能运行出结果，不适合编程大题。

/*
一个N位的十进制正整数，如果它的每个位上的数字的N次方的和等于这个数本身，则称其为花朵数。
例如：
当N=3时，153就满足条件，因为 1^3 + 5^3 + 3^3 = 153，这样的数字也被称为水仙花数（其中，“^”表示乘方，5^3表示5的3次方，也就是立方）。
当N=4时，1634满足条件，因为 1^4 + 6^4 + 3^4 + 4^4 = 1634。
当N=5时，92727满足条件。
实际上，对N的每个取值，可能有多个数字满足条件。
程序的任务是：求N=21时，所有满足条件的花朵数。注意：这个整数有21位，它的各个位数字的21次方之和正好等于这个数本身。

如果满足条件的数字不只有一个，请从小到大输出所有符合条件的数字，每个数字占一行。因为这个数字很大，请注意解法时间上的可行性。
 */

import java.util.*;
import java.io.*;
import java.math.*;


public class Main {

    static BigInteger[] base = new BigInteger[10];
    static int[] times = new int[10];

    static void pow21() {
        for (int i = 0; i < 10; i++) {
            base[i] = BigInteger.valueOf(i).pow(21);
        }
    }

    static void judge() {
        BigInteger sum = BigInteger.ZERO;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < times[i]; j++) {
                sum = sum.add(base[i]);
            }
            //base[i].multiply(BigInteger.valueOf(times[i]))
        }

        String result = sum.toString();
        int length = result.length();
        if (length != 21) {
            return;
        }

        int[] newTimes = new int[10];
        for (int i = 0; i < 21; i++) {
            newTimes[result.charAt(i) - '0']++;
        }
        for (int i = 0; i < 10; i++) {
            if (newTimes[i] != times[i]) {
                return;
            }
        }

        System.out.println(result);
    }

    static void dfs(int k, int chosen) {
        if (k == 9) {
            times[k] = 21 - chosen;
            judge();
            return;
        }

        for (int i = 0; i < 21 - chosen; i++) {
            times[k] = i;
            dfs(k+1, chosen+i);
        }
    }

    public static void main(String[] args) {
        pow21();
        dfs(0, 0);
    }
}
