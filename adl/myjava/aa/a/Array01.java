package aa.a;

public class Array01 {
    public static void main(String[] args) {
        Person[] array = new Person[3];

        Person one =new Person("aa",18);
        Person two =new Person("bb",12);
        Person three= new Person("ASd",1);
        array[0]=one;
        array[1]=two;
        array[2]=three;
        System.out.println(array[0]);
        System.out.println(array[1]);
        System.out.println(array[2]);
        System.out.println(array[1].getName());

    }
}
