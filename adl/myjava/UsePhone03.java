package qq.qqq.qqqq;

public class UsePhone03 {
    public static void main(String[] args) {
        Phone one = new Phone();
        one.brand="apple";
        one.price=981.00;
        one.color="土豪金";
         method(one);
    }
    public static void method(Phone param){
        System.out.println(param.color);
        System.out.println(param.price);
        System.out.println(param.brand);
    }
}
