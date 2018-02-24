/**
 * Created by LonelyEnvoy on 2018-2-24.
 * 十六进制转十进制
 */

import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        long sum = 0;
        for (int i = 0, len = s.length(); i < len; ++i) {
            sum += normalize(s.charAt(i)) * Math.pow(16, len-i-1);
        }
        System.out.println(sum);
    }

    static int normalize(char c) {
        if (c >= '0' && c <= '9') return c - '0';
        else return c - 'A' + 10;
    }
}

