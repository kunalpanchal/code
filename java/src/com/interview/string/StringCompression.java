package com.interview.string;
/**
 * Created by Kunal on 26-11-2016.
 *
 * given - aabbbcccd
 * output= a2b3c3d
 */

public class StringCompression {

    public static void main(String args[]){
//        Scanner in =new Scanner(System.in);
//        String s=in.nextLine();
        String s="taaabbbbbccccddde";
        for(int i=0;i<s.length();i++){
            int counter =0;
            while(i<s.length()-1 && s.charAt(i)==s.charAt(i+1)){
                counter++;
                i++;
            }
            System.out.print(s.charAt(i));
            if(counter>0)System.out.print(counter+1);
        }
    }
}
