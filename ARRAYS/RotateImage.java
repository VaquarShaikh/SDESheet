import java.util.*;
import java.util.Arrays;
import java.util.Scanner;
import java.io.*;

class Solution{
	public void rotate(ArrayList<ArrayList<Integer>> A){
		transpose(A); 
		for (int i = 0; i < A.size(); i++){ 
			Collections.reverse(A.get(i));
		}
	}

	void transpose(ArrayList<ArrayList<Integer>> arr) { 
		for (int i = 0; i < arr.size(); i++) {
			for (int j = i; j < arr.get(0).size(); j++) { 
				int temp = arr.get(j).get(i); 
				arr.get(j).set(i,arr.get(i).get(j)); 
				arr.get(i).set(j,temp); 
			} 
		}
	}
}


class RotateImage{
	public static void main(String[] args){
		// System.out.println();
		int n;
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		ArrayList<ArrayList<Integer>> a = new ArrayList<ArrayList<Integer>>();
		for(int i = 0;i < n;i++){
			ArrayList<Integer> row = new ArrayList<Integer>();
			for(int j = 0;j < n;j++){
				int temp;
				temp = sc.nextInt();
				row.add(temp);
			}
			a.add(row);
		}
		Solution obj = new Solution();
		obj.rotate(a);
		for(int i = 0;i < a.size();i++){
			for(int j = 0;j < a.get(i).size();j++){
				System.out.print(a.get(i).get(j) + " ");
			}System.out.println();
		}
	}
}