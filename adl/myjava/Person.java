package qq.qqq.qqqq;

public class Person {
    String name;
    private int age;
    public void show(){
        System.out.println("i'm"+name+"年龄"+age);
    }
    public void setAge(int num){
        if(0<num&&num<100)
        age=num;
        else System.out.println("数据不可理喻");
    }
    public int getAge(){
        return age;
    }
}
