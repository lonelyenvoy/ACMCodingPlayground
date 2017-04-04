/**
 * Created by LonelyEnvoy on 2017-4-5.
 * 算法训练 5-1最小公倍数
 * Keywords: gcd, lcm, 水题
 */

import java.*;
import java.util.*;
import java.math.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        System.out.print(lcm(a, b));
    }

    public static int lcm(int a, int b) {
        return a * b / gcd(a, b);
    }

    public static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
}
