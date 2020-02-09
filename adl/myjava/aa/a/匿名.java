package aa.a;

public class 匿名 {
    public static void main(String[] args) {
        匿名01 aa=new 匿名01();
        aa.name="sad";
        aa.showName();
        System.out.println("========");
        new 匿名01().name="adl";
        new 匿名01().showName();

    }
}
