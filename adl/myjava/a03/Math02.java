package a03;

public class Math02 {
    public static void main(String[] args) {
        double min=-10.8;
        double max=5.9;
        int count=0;
        for (int i = (int)min; i < max; i++) {
            int abs=Math.abs((i));
            if(abs>6||abs<2.1){
                System.out.println(i);
                count++;
            }

        }
        System.out.println(count);
    }
}
