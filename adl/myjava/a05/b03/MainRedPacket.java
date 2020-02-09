package a05.b03;

import java.util.ArrayList;

public class MainRedPacket {
    public static void main(String[] args) {
        Manager manager=new Manager("群主",100);
        Member one=new Member("a",0);
        Member two=new Member("b",0);
        Member three=new Member("c",0);
        manager.show();
        one.show();
        two.show();
        three.show();
        System.out.println("========");
        ArrayList<Integer>redList=manager.send(20,3);
        one.receive(redList);
        two.receive(redList);
        three.receive(redList);
        one.show();
        two.show();
        three.show();
    }
}
