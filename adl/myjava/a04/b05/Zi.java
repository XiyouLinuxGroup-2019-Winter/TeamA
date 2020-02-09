package a04.b05;

public class Zi extends Fu{
    int num=10;
    @Override
    public void method(){
        super.method();
        System.out.println("zi");
    }
    public void show(){
        int num=30;
        System.out.println(num);
        System.out.println(this.num);
        System.out.println(super.num);
    }

}
