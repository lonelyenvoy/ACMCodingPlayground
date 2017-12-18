/**
 * Created by LonelyEnvoy on 2017-12-18.
 * 基础练习 特殊回文数
 * Keywords: brute force, simple strings
 */

import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        n = Integer.parseInt(sc.next());
        sc.close();
        brute(0,1,5);
        brute(0,1,6);
        for (int item:list) System.out.println(item);
    }

    static int n;
    static List<Integer> list = new ArrayList<>();

    // v -- value, k -- kth digit, p -- peak
    static void brute(int v, int k, int p) {
        if (k==p+1) {
            if (check(v)) list.add(v);
            return;
        }
        for (int a=(k==p?1:0);a<=9;++a) {
            brute((int)(v+a*Math.pow(10,k-1)), k+1, p);
        }
    }

    static boolean check(int v) {
        String s = v+"";
        int len = s.length();
        for (int i=0;i<(len>>1);++i) if (s.charAt(i) != s.charAt(len-i-1)) return false;
        int sum = 0;
        for (int i=0;i<len;++i) sum += s.charAt(i) - '0';
        return sum == n;
    }
}

