import java.util.Scanner;
public class Touwei {
        public  int binarySearch(int[] nums, int target) {
            if (nums == null || nums.length == 0) {
                return -1;
            }
            int l = 0;
            int r = nums.length - 1;
            while (l <= r) {
                int middle = (l + r) / 2;
                if (nums[middle] == target) {
                    return middle;
                } else if (nums[middle] > target) {
                    r = middle - 1;
                } else {
                    l = middle + 1;
                }
            }
            return -1;
        }

        public  int[] searchRange(int[] nums, int target) {
            int[] arr = { -1, -1 };
            if (nums == null || nums.length == 0) {
                return arr;
            }
            int index = binarySearch(nums, target);
            if (index == -1) {
                return arr;
            }
            int l = index - 1;
            while (l >= 0 && nums[l] == target) {
                --l;
            }
            arr[0] = l + 1;
            int r = index + 1;
            while (r < nums.length && nums[r] == target) {
                ++r;
            }
            arr[1] = r - 1;
            return arr;
        }
        public static void main(String[] args){
        Scanner input=new Scanner(System.in);
        int length=0,target;
        length=input.nextInt();
        int[] arr =new int[length];
        for (int i = 0; i < length; i++) {
            arr[i]=input.nextInt();
            }
        target= input.nextInt();
        Touwei.binarySearch(arr,target);

        }
}

