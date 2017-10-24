/*
 * Created by LonelyEnvoy on 2017-10-24.
 * A. Alex and broken contest
 * Keywords: simple strings
 */

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        System.out.println(check(s) ? "YES" : "NO");
    }

    static final String[] names = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
    
    static boolean check(String s) {
        boolean flag = false;
        for (String name : names) {
            int pos = s.indexOf(name);
            if (pos != -1) {
                if (flag) return false;
                flag = true;
                if (s.indexOf(name, pos+1) != -1) return false;
            }
        }
        return flag;
    }
}

