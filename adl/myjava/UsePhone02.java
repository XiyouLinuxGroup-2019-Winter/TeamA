package qq.qqq.qqqq;

public class UsePhone02 {

        public static void main(String[] args) {
            Phone two = new Phone();
            System.out.println(two.brand);
            System.out.println(two.price);
            System.out.println(two.color);
            two.brand="明国";
            two.color="hei";
            two.price=11.2;
            two.call("乔布斯");
            two.call("qq");
            two.sendMessage();
            Phone three = new Phone();
            System.out.println(three.brand);
            System.out.println(three.price);
            System.out.println(three.color);
            three.brand="明aa国";
            three.color="heiaa";
            three.price=11.21;
            three.call("aa乔布斯");
            three.call("qqaaiaa");
            three.sendMessage();
        }

}
