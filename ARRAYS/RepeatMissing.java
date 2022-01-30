import java.util.*;
import java.util.Arrays;
import java.util.Scanner;
import java.io.*;

class Solution{
	public int[] repeatedNumber(final int[] A){
		// System.out.println("This is a dummy");
		Long n = A.length;
		Long sum = n*(n+1)/2;
		Long ssum = n*(n+1)*(2*n+1)/6;
		for(int i = 0;i < n;i++){
			sum -= A[i];
			ssum -= (A[i]*A[i]);
		}	
		int x = (ssum/sum + sum)/2;
		int y = (ssum/sum - sum)/2;
		Long [] ans = new Long[2];
		ans[0] = y;
		ans[1] = x;
		return ans;
	}
}

class RepeatMissing{
	public static void main(String[] args){
		// System.out.println("hello");
		int n;
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		int [] A = new int[n];
		for(int i = 0;i < n;i++){
			A[i] = sc.nextInt();
		}	
		Solution obj = new Solution();
		int [] res = obj.repeatedNumber(A);
		for(int i = 0;i < res.length;i++){
			System.out.print(res[i] + " ");
		}
	}
}