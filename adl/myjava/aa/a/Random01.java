package aa.a;

import java.util.Random;

public class Random01 {
    public static void main(String[] args) {
        Random  r=new Random();
//        int num=r.nextInt();
//        System.out.println("随机数试试"+num);
        for (int i = 0; i < 100; i++) {
            int num=r.nextInt(10);
            System.out.println(num);
        }
    }

}
