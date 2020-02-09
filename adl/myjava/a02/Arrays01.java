package a02;

import java.util.Arrays;

public class Arrays01 {
    public static void main(String[] args) {
        int[]intArray={10,20,30};
        String intStr= Arrays.toString(intArray);
        System.out.println(intStr);
        int[]array1={2,1,2,3,4,5};
        Arrays.sort(array1);
        System.out.println(Arrays.toString(array1));
        System.out.println(array1);
        String[]array2={"zaa","bb","c"};
        Arrays.sort(array2);
        System.out.println(Arrays.toString(array2));

    }
}
