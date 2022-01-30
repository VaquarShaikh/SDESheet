import java.util.*;
import java.util.Arrays;
import java.util.Scanner;
import java.io.*;

class ListNode<T>{
	T data;
	ListNode<T> next;
	ListNode(T data){
		this.data = data;
		this.next = null;
	}
}


class Solution{
	public ListNode<Integer> reverseList(ListNode<Integer> head){
		if(head == null || head.next == null){
			return head;
		}
		ListNode<Integer> smallAns = reverseList(head.next);
		ListNode<Integer> tail = head.next;
		tail.next = head;
		head.next = null;
		return smallAns;
	}
}


class Test{

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	static ListNode<Integer> takeInput() throws IOException{
		String[] datas = br.readLine().trim().split("\\s");
		ListNode<Integer> head = null , tail = null;
		int i = 0;
		while(i < datas.length){
			int data = Integer.parseInt(datas[i]);
			ListNode<Integer> newNode = new ListNode<Integer>(data);
			if(head == null){
				head = newNode;
				tail = newNode;
			}else{
				tail.next = newNode;
				tail = tail.next;
			}
			i++;
		}
		return head;
	}

	static void printList(ListNode<Integer> head){
		ListNode<Integer> temp = head;
		while(temp != null){
			System.out.print(temp.data + " ");
			temp = temp.next;
		}System.out.println();
	}

	public static void main(String[] args) throws NumberFormatException , IOException{
		// System.out.println();
		System.out.println("Enter the number of testcases");
		int t = Integer.parseInt(br.readLine().trim());
		while(t > 0){
			System.out.println("Enter the elements of the linkedkist");
			ListNode<Integer> head = takeInput();
			System.out.println("The elements entered are : ");
			printList(head);
			System.out.println("The reverse of this linkedlist is :");
			Solution obj = new Solution();
			ListNode<Integer> newHead = obj.reverseList(head);
			printList(newHead);
			t--;
		}
		
	}
}