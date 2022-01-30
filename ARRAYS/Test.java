import java.util.*;
import java.util.Arrays;
import java.util.Scanner;
import java.io.*;
import java.lang.*;


class Interval{
	int start;
	int end;
	Interval(int start , int end){
		this.start = start;
		this.end = end;
	}
}


class SortbyStart implements Comparator<Interval>{
	public int compare(Interval a , Interval b){
		 return a.start - b.start;
	}
}
 

class Solution{
	public ArrayList<Interval> merge(ArrayList<Interval> intervals) {
		Collections.sort(intervals , new SortbyStart());
		Stack<Interval> storeIntervals = new Stack<Interval>();
		storeIntervals.push(intervals.get(0));
		for(int i = 1;i < intervals.size();i++){
			Interval top = storeIntervals.peek();
			// push
			if(intervals.get(i).start > top.end){
				storeIntervals.push(intervals.get(i));
			}
			// merge and push
			else if(top.end < intervals.get(i).end){
				top.end = intervals.get(i).end;
				storeIntervals.pop();
				storeIntervals.push(top);
			}
		}
		ArrayList<Interval> res = new ArrayList<Interval>();
		while(!storeIntervals.empty()){
			Interval top = storeIntervals.pop();
			res.add(top);
		}
		Collections.sort(res , new SortbyStart());
		return res;
	}
}

class Test{
	public static void main(String[] args){
		// System.out.println();
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		ArrayList<Interval> intervals = new ArrayList<Interval>();
		for(int i = 0;i < n;i++){
			intervals.add(new Interval(sc.nextInt(),sc.nextInt()));
		}
		Solution obj = new Solution();
		ArrayList<Interval> output = obj.merge(intervals);
		for(int i = 0;i < output.size();i++){
			System.out.println(output.get(i).start + " " + output.get(i).end);
		}
	}
}