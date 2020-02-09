package aa.a;
import java.util.Scanner;
public class Scanner01 {
    public static void main(String[] args) {
        Scanner sc =  new Scanner(System.in);
        int num=sc.nextInt();
        System.out.println("输入的是"+num);
        String  str=sc.next();
        System.out.println("字符串"+str);
    }
}
