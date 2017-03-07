/**
 * Created by LonelyEnvoy on 2017-3-7.
 * Fibonacci数列
 */

import java.util.*;
import java.io.*;
import java.math.*;

public class Main {

    private static final BigInteger testData = BigInteger.valueOf(10007);

    private static BigInteger fibonacci_loop(int n) {
        if (n < 2) {
            return BigInteger.valueOf(n);
        }
        BigInteger f0 = BigInteger.ONE;
        BigInteger f1 = f0;
        BigInteger f2 = BigInteger.ONE;
        for (int i = 2; i < n; i++) {
            f2 = f0.add(f1);
            f0 = f1;
            f1 = f2;
        }
        return f2;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        sc.close();
        System.out.println(fibonacci_loop(n).remainder(testData));
    }
}
