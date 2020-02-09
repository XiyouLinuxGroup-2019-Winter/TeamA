package aa.a;

import java.util.Scanner;

public class Scanner03 {
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        System.out.println("1:");
        int a=sc.nextInt();
        System.out.println("2:");
        int b=sc.nextInt();
        System.out.println("3:");
        int c=sc.nextInt();
        int temp =a>b?a:b;
        int max=temp>c?temp:c;
        System.out.println("max:"+max);

    }
}
