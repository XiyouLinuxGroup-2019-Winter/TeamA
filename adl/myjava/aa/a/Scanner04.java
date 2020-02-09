package aa.a;

import java.util.Scanner;

public class Scanner04 {
    public static void main(String[] args) {
//        Scanner sc =new Scanner(System.in);
//        int num=sc.nextInt();
//        int num=new Scanner(System.in).nextInt();
//        System.out.println("shu"+num);
        method(new Scanner(System.in));
        Scanner sc= methodReturn();
        int num=sc.nextInt();
        System.out.println("输入的是"+num);
    }

    public static void method(Scanner sc){
        int num=sc.nextInt();
        System.out.println("输入的是"+num);
    }
    public static Scanner methodReturn(){
        return new Scanner(System.in);
         }
}
