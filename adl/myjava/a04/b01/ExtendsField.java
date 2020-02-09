package a04.b01;

public class ExtendsField {
    public static void main(String[] args) {
        Fu  fu=new Fu();
        System.out.println(fu.numFu);
        Zi  zi=new Zi();
        System.out.println(zi.numFu);
        System.out.println(zi.numZi);
        System.out.println(zi.num);
        System.out.println(fu.num);
        zi.methodZi();
       // zi.methodFu();

    }
}
