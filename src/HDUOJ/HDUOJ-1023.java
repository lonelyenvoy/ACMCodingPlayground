/**
 * Created by LonelyEnvoy on 2017-3-8.
 * Train Problem II
 * Hint: 卡特兰数
 */

import java.util.*;
import java.math.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int n = Integer.parseInt(sc.next());
            BigInteger result = factorial(2 * n).divide( factorial(n + 1).multiply(factorial(n)) );
            System.out.println(result);
        }
        sc.close();
    }

    private static BigInteger factorial(int n) {
        if (n <= 2) return BigInteger.valueOf(n);
        BigInteger product = BigInteger.ONE;
        for (int i = 2; i <= n; i++) {
            product = product.multiply(BigInteger.valueOf(i));
        }
        return product;
    }
}
