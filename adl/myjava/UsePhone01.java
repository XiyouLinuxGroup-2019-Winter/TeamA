package qq.qqq.qqqq;

public class UsePhone01 {
    public static void main(String[] args) {
        Phone one = new Phone();
        System.out.println(one.brand);
        System.out.println(one.price);
        System.out.println(one.color);
        one.brand="明国";
        one.color="hei";
        one.price=11.2;
        one.call("乔布斯");
        one.call("qq");
        one.sendMessage();
    }
}
