package aa.a;

import java.util.ArrayList;

public class ArrayListStudent {
    public static void main(String[] args) {
        ArrayList<Student>  list=new ArrayList<>();
        Student one =new Student("sd",201);
        Student two =new Student("sdd",2);
        Student three =new Student("sdd",120);
        Student four =new Student("sds",210);
        list.add(one);
        list.add(two);
        list.add(three);
        list.add(four);
        for (int i=0;i<list.size();i++){
            Student stu=list.get(i);
            System.out.println("name"+stu.getName()+"age"+stu.getAge());
        }
    }
}
