/**
 * Created by LonelyEnvoy on 2017-3-7.
 * 十六进制转八进制
 */

import java.util.*;
import java.math.*;
import java.io.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int amount = Integer.parseInt(sc.next());
        String[] results = new String[amount];
        for (int i = 0; i < amount; i++) {
            String input = sc.next();
            results[i] = BinaryToOctal(hexToBinary(input));
        }
        sc.close();
        for (int i = 0; i < amount; i++) {
            System.out.println(results[i]);
        }
    }

    private static String hexToBinary(String hex) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < hex.length(); i++ ) {
            char c = hex.charAt(i);
            switch (c) {
                case '0': sb.append("0000"); break;
                case '1': sb.append("0001"); break;
                case '2': sb.append("0010"); break;
                case '3': sb.append("0011"); break;
                case '4': sb.append("0100"); break;
                case '5': sb.append("0101"); break;
                case '6': sb.append("0110"); break;
                case '7': sb.append("0111"); break;
                case '8': sb.append("1000"); break;
                case '9': sb.append("1001"); break;
                case 'A': sb.append("1010"); break;
                case 'B': sb.append("1011"); break;
                case 'C': sb.append("1100"); break;
                case 'D': sb.append("1101"); break;
                case 'E': sb.append("1110"); break;
                case 'F': sb.append("1111"); break;
                default: break;
            }
        }
        return sb.toString();
    }

    private static String BinaryToOctal(String bin) {
        while (bin.length() % 3 != 0) {
            bin = "0" + bin;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < bin.length(); i += 3) {
            String currentUnit = bin.substring(i, i + 3);
            if (currentUnit.equals("000")) sb.append("0");
            else if (currentUnit.equals("001")) sb.append("1");
            else if (currentUnit.equals("010")) sb.append("2");
            else if (currentUnit.equals("011")) sb.append("3");
            else if (currentUnit.equals("100")) sb.append("4");
            else if (currentUnit.equals("101")) sb.append("5");
            else if (currentUnit.equals("110")) sb.append("6");
            else if (currentUnit.equals("111")) sb.append("7");
        }
        if (sb.charAt(0) == '0') {
            sb.deleteCharAt(0);
        }
        return sb.toString();
    }
}
