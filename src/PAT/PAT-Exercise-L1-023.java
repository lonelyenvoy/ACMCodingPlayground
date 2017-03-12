/**
 * Created by LonelyEnvoy on 2017-3-12.
 * L1-023. 输出GPLT
 * Keywords: 水题
 */

import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        final BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        final String line = reader.readLine();
        int[] count = new int[4]; // GPLT
        final char[] chars = { 'G', 'P', 'L', 'T'};
        for (int c : count) {
            c = 0;
        }
        for (int i = 0; i < line.length(); i++) {
            switch (line.charAt(i)) {
                case 'G':case 'g': count[0]++; break;
                case 'P':case 'p': count[1]++; break;
                case 'L':case 'l': count[2]++; break;
                case 'T':case 't': count[3]++; break;
                default: break;
            }
        }
        int sumChars = 0;
        for (int c : count) {
            sumChars += c;
        }
        for (int i = 0; i < sumChars; i++) {
            for (int j = 0; j < 4; j++) {
                if (count[j]-- > 0) {
                    System.out.print(chars[j]);
                }
            }
        }
        System.out.println();
    }
}
