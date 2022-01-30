import java.util.*;
import java.util.Arrays;
import java.util.Scanner;
import java.io.*;
import java.lang.*;


class Solution{
	public int maxSubArray(final int[] A) {
		int curr = 0 , maxsum = -10000;
		for(int i = 0;i < A.length;i++){
			curr += A[i];
			maxsum = Math.max(maxsum , curr);
			if(curr < 0){
				curr = 0;
			}
		}
		return maxsum;
    }
}

class MaxSubarray{
	public static void main(String[] args){
		// System.out.println();
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int [] A = new int[n];
		for(int i = 0;i < n;i++){
			A[i] = sc.nextInt();
		}
		Solution obj = new Solution();
		int res = obj.maxSubArray(A);
		System.out.println(res);
	
	}
}