/**
 * Created by LonelyEnvoy on 2017-4-7.
 * 历届试题 买不到的数目
 * Keywords: 数论
 * Limits: High run-time efficiency required
 */

import java.util.*;
import java.io.*;
import java.math.*;

public class Main {

    static final int MAX = 50000;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        boolean[] canBuy = new boolean[MAX];

        int low = (a < b ? a : b);
        int high = (a > b ? a : b);

        int curr;
        for (int i = 0; i < MAX / a; i++) {
            for (int j = 0; j < (MAX - i / a) / b; j++) {
                curr = i * a + b * j;
                if (curr < MAX) canBuy[curr] = true;
            }
        }

        int maxCannotBuy = -1;
        int count = 0;
        for (int i = high; i < MAX ; i++) {
            if (count == low) {
                maxCannotBuy = i - low - 1;
                break;
            }

            if (canBuy[i] = true) {
                count++;
            } else {
                count = 0;
            }
        }

        System.out.println(maxCannotBuy);
        sc.close();
    }
}
