package aa.a;

public class String05 {
    public static void main(String[] args) {
        char[]chars="hello".toCharArray();
        System.out.println(chars[0]);
        System.out.println(chars.length);
        byte[]bytes="anc".getBytes();
        for (int i = 0; i < bytes.length; i++) {
            System.out.println(bytes[i]);
        }
        String str1="hedal lj jk jl";
        String j = str1.replace("j", "*");
        System.out.println(j);


    }
}
