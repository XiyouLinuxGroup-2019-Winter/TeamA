package aa.a;

public class String07 {
    public static void main(String[] args) {
        int[]array={1,2,4};
        String result =fromArrayToString(array);
        System.out.println(result);
    }
    public static String fromArrayToString(int[]array){
        String str="[";
        for (int i = 0; i < array.length; i++) {
            if(i==array.length-1)
                str+="word"+array[i]+']';
            else str+="word"+array[i]+"#";
        }
        return  str;
    }
}
