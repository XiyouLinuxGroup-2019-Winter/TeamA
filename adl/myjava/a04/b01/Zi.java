package a04.b01;

public class Zi extends Fu{
    int numZi=20;
    int num=2;
    public void methodZi(){
        int num=333;
        System.out.println(this.num);
        System.out.println(num);
        System.out.println(super.num);
    }

}
