package com.interview.recursion;

/**
 * Created by Kunal on 07-11-2016.
 * input -> abxxxxbbyz
 * output -> ayz
 */
public class BombersAlgo {
    public static void main(String[] args){
        System.out.println("Welcome to bombers algo");
        BombersAlgo b=new BombersAlgo();
        System.out.println(b.bomber("abxxxxbbyz"));
    }
    public String bomber(String data){
        StringBuilder data1=new StringBuilder();
        for(int i=0;i<data.length()-1;i++){
            if(data.charAt(i)==data.charAt(i+1)){
            while(i<data.length()-1 && data.charAt(i)==data.charAt(i+1))
                i++;
                i++;
            }
            data1.append(data.charAt(i));
        }
        data1.append(data.charAt(data.length()-1));
        System.out.println(data1.toString());
        if(data.length()==data1.toString().length()) return data1.toString();
        return bomber(data1.toString());
    }
}
