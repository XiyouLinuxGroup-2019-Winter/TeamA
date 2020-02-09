package aa.a;

public class StaticStudentField {
    public static void main(String[] args) {

        Student one =new Student("asd",13);
        Student two =new Student("ad",133);
        one.room="101";
        System.out.println("name"+one.getName()+"AGE"+one.getAge()+"room"+one.room
                +"学号"+one.getId());

        System.out.println("name"+two.getName()+"AGE"+two.getAge()+"room"+two.room
                +"学号"+two.getId());

    }
}
