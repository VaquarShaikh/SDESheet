import java.util.*;
import java.util.Arrays;
import java.util.Scanner;
import java.io.*;


class Solution{
	public void sortColors(int[] nums){
		int n = nums.length;
		int temp;
		int l = 0 , m = 0 , h = n - 1;
		while(m <= h){
			if(nums[m] == 0){
				temp = nums[l];
				nums[l] = nums[m];
				nums[m] = temp;
				l++;
				m++;
			}else if(nums[m] == 1){
				m++;
			}else{
				temp = nums[m];
				nums[m] = nums[h];
				nums[h] = temp;
				h--;
			}
		}
	}
}


class Sort012{
	public static void main(String[] args){
		// System.out.println("hello");
		int n;
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		int [] nums = new int[n];
		for(int i = 0;i < n;i++){
			nums[i] = sc.nextInt();
		}	
		Solution obj = new Solution();
		obj.sortColors(nums);
		for(int i = 0;i < nums.length;i++){
			System.out.print(nums[i] + " ");
		}
	}
}