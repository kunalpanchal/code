package com.interview.patterns;

import java.util.Scanner;

/**
 * Created by Kunal on 06-12-2016.
 */
public class HashCross {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = n;
        int p=(n/2)-1;
        for (int i = 0; i < n; i++) {
            if (i< n / 2) {
                for (int j = 0; j < i; j++) System.out.print(' ');
                for (int j = 0; j < k; j++) System.out.print('#');
                k = k - 2;
                System.out.println();
            }else{
                int l=(n/2)-p;
                for (int j = 0; j < n/2-l/2; j++) {System.out.print(' '); }
                for (int j = 0; j < l; j++) System.out.print('#');
                System.out.println();
                p = p - 2;
            }
        }
    }
}
