import java.util.*;
import java.util.Arrays;
import java.util.Scanner;
import java.io.*;

class Returnpairs{
	int str;
	int end;
	Returnpairs(int s , int e){
		this.str = s;
		this.end = e;
	}
}

class SortByStart implements Comparator<Returnpairs>{
	public int compare(Returnpairs a , Returnpairs b){
		return a.str - b.str;
	}
}

class Solution{
	public void merge(ArrayList<Returnpairs> intervals){
		// Collections.sort(intervals , new Comparator<Returnpairs>(){
		// 	public int compare(Returnpairs a , Returnpairs b){
		// 		return a.str - b.str;
		// 	}
		// });
		Collections.sort(intervals , new SortByStart());
		for(int i = 0;i < intervals.size();i++){
			System.out.println(intervals.get(i).str + " " + intervals.get(i).end);
		}

	}
}

class Tesst{
	public static void main(String[] args){
		// System.out.println();
		int n;
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		ArrayList<Returnpairs> intervals = new ArrayList<Returnpairs>();
		for(int i = 0;i < n;i++){
			int s;
			int e;
			s = sc.nextInt();
			e = sc.nextInt();
			Returnpairs temp = new Returnpairs(s , e);
			intervals.add(temp);
		}
		// Collections.sort(intervals , new Comparator<Returnpairs>(){
		// 	@Override
		// 	public int compare(Returnpairs a , Returnpairs b){
		// 		return a.str - b.str;
		// 	}
		// });
		// for(int i = 0;i < intervals.size();i++){
		// 	System.out.println(intervals.get(i).str + " " + intervals.get(i).end);
		// }
		Solution obj = new Solution();
		obj.merge(intervals);
	}
}