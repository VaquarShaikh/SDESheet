import java.util.*;
import java.util.Arrays;
import java.util.Scanner;
import java.io.*;

class dual{
	int start;
	int end;
	dual(int start , int end){
		this.start = start;
		this.end = end;
	}
}

class SortValuesbyStart implements Comparator<dual>{
	public int compare(dual a , dual b){
		return a.start - b.start;
	}
}

class Test1{
	public static void main(String[] args){
		// System.out.println();
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		ArrayList<dual> input = new ArrayList<dual>();
		for(int i = 0;i < n;i++){
			input.add(new dual(sc.nextInt(),sc.nextInt()));
		}
		System.out.println("The entered intervals are : ");
		for(int i = 0;i < input.size();i++){
			System.out.println(input.get(i).start + " " + input.get(i).end);
		}System.out.println();

		Collections.sort(input , new SortValuesbyStart());

		System.out.println("After sorting : ");

		for(int i = 0;i < input.size();i++){
			System.out.println(input.get(i).start + " " + input.get(i).end);
		}

	}
}