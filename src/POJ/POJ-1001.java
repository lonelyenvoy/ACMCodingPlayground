/**
 * Created by LonelyEnvoy on 2017-3-25.
 * Exponentiation
 * Keywords: 大数处理
 */

import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNext()) {
            String str = sc.next();
            BigDecimal r = new BigDecimal(str);
            int n = sc.nextInt();
            r = r.pow(n).stripTrailingZeros();
            String result = r.toPlainString();
            if (result.charAt(0) == '0') {
                result = result.substring(1);
            }
            System.out.println(result);
        }
    }
}