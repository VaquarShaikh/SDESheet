import java.util.*;
import java.util.Arrays;
import java.util.Scanner;
import java.io.*;

class Interval{
	int start;
	int end;
	Interval(int s , int e){
		this.start = s;
		this.end = e;
	}
}

class SortByStart implements Comparator<Interval>{
	public int compare(Interval a , Interval b){
		return a.start - b.start;
	}
}

class Solution{
	public ArrayList<Interval> merge(ArrayList<Interval> intervals){
		Collections.sort(intervals , new SortByStart());
		Stack<Interval> storeIntervals = new Stack<Interval>();
		storeIntervals.push(intervals.get(0));
		for(int i = 1;i < intervals.size();i++){
			Interval top = storeIntervals.peek();
			// push
			if(intervals.get(i).start > top.end){
				storeIntervals.push(intervals.get(i));
			}//merge
			else if(intervals.get(i).end > top.end){
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
		Collections.sort(res , new SortByStart());
		return res;
	}
}

class MergeOverlap{
	public static void main(String[] args){
		int n;
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		ArrayList<Interval> intervals = new ArrayList<Interval>();
		for(int i = 0;i < n;i++){
			intervals.add(new Interval(sc.nextInt() , sc.nextInt()));
		}
		Solution obj = new Solution();
		ArrayList<Interval> res = obj.merge(intervals);
		for(int i = 0;i < res.size();i++){
			System.out.println(res.get(i).start + " " + res.get(i).end);
		}
	}
}