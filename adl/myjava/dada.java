package qq.qqq.qqqq;

public class dada {
    public static void main(String[] args) {
        int a=getSum();
        System.out.println(a);
        System.out.println(sum(1,2,3));
        System.out.println(sum(1,3));
    }
    public static int getSum(){
        int sum=0;
        for (int i = 1; i <= 100; i++) {
            sum+=i;
        }
        return sum;
    }
    public static int sum(int a,int b){
        return a+b;
    }

    public static int sum(int a,int b,int c){
        return a+b+c;
    }

}
