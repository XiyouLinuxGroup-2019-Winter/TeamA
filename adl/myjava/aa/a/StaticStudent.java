package aa.a;

public class StaticStudent {
    public static void main(String[] args) {
        Student.room="101";
        Student one =new Student("zhn",12);
        System.out.println(one.getName());
        System.out.println(one.getAge());
        System.out.println(Student.room);
        Student two =new Student("zshn",12);
        System.out.println(two.getName());
        System.out.println(two.getAge());
        System.out.println(Student.room);

    }
}

//ALT+鼠标左键