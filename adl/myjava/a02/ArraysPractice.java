package a02;

import java.util.Arrays;

public class ArraysPractice {
    public static void main(String[] args) {
        String str="adjfsjlg";
        char[] chars = str.toCharArray();
        Arrays.sort(chars);
        for (int i = chars.length - 1; i >= 0; i--) {
            System.out.println(chars[i]);
        }
       // String.toCharArray;
    }
}

