import java.util.*;
import java.util.Arrays;
import java.util.Scanner;
import java.io.*;

class BubbleSort{

	static void bubbleSort(int [] input){
		for(int i = 0;i < input.length;i++){
			for(int j = i + 1;j < input.length;j++){
				if(input[j] < input[i]){
					int temp;
					temp = input[i];
					input[i] = input[j];
					input[j] = temp;
				}
			}
		}
	}

	public static void main(String[] args){
		int n;
		System.out.println("Enter the size of the array");
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		int [] input = new int[n];
		System.out.println("Enter the elements of the array");
		for(int i = 0;i < n;i++){
			input[i] = sc.nextInt();
		}
		System.out.println("Elements before sorting : ");
		for(int i = 0;i < n;i++){
			System.out.print(input[i] + " ");
		}
		System.out.println();
		bubbleSort(input);
		System.out.println("Elements after sorting : ");
		for(int i = 0;i < n;i++){
			System.out.print(input[i] + " ");
		}
	}
}