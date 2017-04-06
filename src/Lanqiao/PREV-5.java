/**
 * Created by LonelyEnvoy on 2017-4-6.
 * 历届试题 错误票据
 * Keywords: 简单排序
 */

import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<Integer> list = new ArrayList<Integer>();
        int n = Integer.parseInt(reader.readLine());
        while (n-- > 0) {
            String[] data = reader.readLine().split(" ");
            for (String str : data) {
                if (str.length() != 0) {
                    list.add(Integer.parseInt(str));
                }
            }
        }
        list.sort(new Comparator<Integer>() {
            public int compare(Integer o1, Integer o2) {
                return o1 - o2;
            }
        });

        Iterator<Integer> itr = list.iterator();
        int last = itr.next();
        int repeated = -1;
        int lost = -1;
        while ((repeated == -1 || lost == -1) && itr.hasNext()) {
            int curr = itr.next();
            if (last == curr) {
                repeated = curr;
            } else if (curr - last > 1) {
                lost = curr - 1;
            }
            last = curr;
        }

        System.out.println(lost + " " + repeated);

        reader.close();
    }
}