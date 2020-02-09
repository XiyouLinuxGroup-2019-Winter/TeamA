package aa.a;

public class StaticMehod {
    public static void main(String[] args) {
        MyClass obj=new MyClass();
        obj.method();
//        obj.methodStatic();
        MyClass.methodStatic();

    }
}
