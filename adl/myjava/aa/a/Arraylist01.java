package aa.a;

import java.util.ArrayList;

public class Arraylist01 {
    public static void main(String[] args) {
        ArrayList<String> list =new ArrayList<>();
        list.add("asd");
        list.add("asdd");
        list.add("asddd");
        boolean success= list.add("asdd");
        System.out.println(success);
        String ssad= list.get(2);
        System.out.println(ssad);
        String remove = list.remove(3);
        System.out.println("who"+remove);
        System.out.println(list);
        int size = list.size();
        System.out.println("size="+size);

    }
}
