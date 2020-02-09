package aa.a;

public class String06 {
    public static void main(String[] args) {
        String str1="aaa.bbb.ccc";
        String[]array1=str1.split("\\.");
        for (int i = 0; i < array1.length; i++) {
            System.out.println(array1[i]);
        }

    }
}
