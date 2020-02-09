package aa.a;

import java.util.ArrayList;
import java.util.Random;

public class ArrayListReturn {
    public static void main(String[] args) {
        ArrayList<Integer>biglist=new ArrayList<>();
        Random r=new Random();
        for (int i = 0; i < 20; i++) {
            int num=r.nextInt(100)+1;
            biglist.add(num);
        }
        ArrayList<Integer>smallList =getSmallList(biglist);
        System.out.println("偶数有多少"+smallList.size());
        for (int i = 0; i < smallList.size(); i++) {
            System.out.println(smallList.get(i));
        }
    }
    public static ArrayList<Integer>getSmallList(ArrayList<Integer>bigList){
        ArrayList<Integer>smallList =new ArrayList<>();
        for (int i = 0; i < bigList.size(); i++) {
            int num =bigList.get(i);
            if(num%2==0)
                smallList.add(num);
        }
        return smallList;
    }
}