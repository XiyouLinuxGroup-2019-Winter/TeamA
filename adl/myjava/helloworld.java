package qq.qqq.qqqq;



import java.util.Scanner;
/*
 * 啊啊啊*/

public class helloworld {
        public static void main(String[] args) {
            System.out.println("hello world");
            System.out.println("Sad");
            Scanner sc = null;
            printMethod();
            System.out.println(sum(1,2));

        }
        public static int sum(int a,int b){
            int result = a+b;
            return result;
        }
        public static void printMethod() {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 20; j++) {
                    System.out.print("*");
                }
                System.out.println();
            }

        }


}
