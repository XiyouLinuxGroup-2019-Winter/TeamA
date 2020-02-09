package aa.a;

public class MyClass {
    int num;
    static int numStatic;
    public void method(){
        System.out.println(num);
        System.out.println("成员方法");
    }
    public static void methodStatic(){
        System.out.println("静态方法");
        System.out.println(numStatic);
    }
}
