package aa.a;

import java.util.ArrayList;

public class ArrayList02 {
    public static void main(String[] args) {
        ArrayList<String>list= new ArrayList<>();
        list.add("a");
        list.add("b");
        list.add("c");
        for (int i = 0; i < list.size(); i++) {
            System.out.println(list.get(i));
        }
        ArrayList<Integer>listc =new ArrayList<>();
        listc.add(11);
        listc.add(2);
        System.out.println(listc.get(1));
    }
}
