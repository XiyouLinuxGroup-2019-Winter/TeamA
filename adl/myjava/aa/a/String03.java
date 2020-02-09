package aa.a;

public class String03 {
    public static void main(String[] args) {
        int length = "asdldjalkf".length();
        System.out.println(length);
        String str1="HELLO";
        String str2="World";
        String str3=str1.concat(str2);
        System.out.println(str1);
        System.out.println(str2);
        System.out.println(str3);
        char c = "ADLADL".charAt(1);
        System.out.println(c);
        String original="helloworld";
        int index =original.indexOf("llo");
        System.out.println(index);
    }
}
