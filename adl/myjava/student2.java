package qq.qqq.qqqq;

public class student2 {
    public static void main(String[] args) {
        student stu =new student();
        System.out.println(stu.name);
        System.out.println(stu.age);
        stu.name="adl";
        stu.age=18;
        System.out.println(stu.age);
        System.out.println(stu.name);
        stu.eat();
        stu.sleep();
        stu.study();
    }
}
