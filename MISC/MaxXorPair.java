import java.util.*;
import java.util.Arrays;
import java.util.Scanner;
import java.io.*;
import java.lang.*;


class TrieNode{
	TrieNode left , right;
}

class Solution{
	private static void insert(TrieNode head , int n){
		TrieNode curr = head;
		for(int i = 31;i >= 0;i--){
			int b = (n>>i)&1;
			if(b==0){
				if(curr.left == null){
					curr.left = new TrieNode();
				}
				curr = curr.left;
			}else{
				if(curr.right == null){
					curr.right = new TrieNode();
				}
				curr = curr.right;
			}
		}
	}
	private int findMaximumXOR(TrieNode head , int [] nums){
		int n = nums.length;
		int max_xor = Integer.MIN_VALUE;
		TrieNode curr = head;
		int curr_xor = 0;
		for(int i = 0;i < n;i++){
			int value = nums[i];
			for(int j = 31;j >= 0;j--){
				int b = (value>>j)&1;
				if(b == 0){
					if(curr.right != null){
						curr_xor += Math.pow(2,j);
						curr = curr.right;
					}else{
						curr = curr.left;
					}
				}else{
					if(curr.left != null){
						curr_xor += Math.pow(2,j);
						curr = curr.left;
					}else{
						curr = curr.left;
					}
				}
			}
			if(curr_xor > max_xor){
				max_xor = curr_xor;
			}
		}
		return max_xor;
	}
	public int findMaximumXOR(int [] nums){
		TrieNode head = new TrieNode();
		for(int i = 0;i < nums.length;i++){
			insert(head , nums[i]);
		}
		return findMaximumXOR(head , nums);
	}
}

class MaxXorPair{
	public static void main(String[] args){
		// System.out.println();
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int [] nums = new int[n];
		for(int i = 0;i < n;i++){
			nums[i] = sc.nextInt();
		}
		Solution obj = new Solution();
		int res = obj.findMaximumXOR(nums);
	}
}