import java.util.*;
import java.util.Arrays;
import java.util.Scanner;
import java.io.*;

class Node<T>{
	T data;
	Node<T> next;
	Node(T data){
		this.data = data;
		this.next = null;
	}
}

class Solution{
	public Node<Integer> reverse(Node<Integer> head){
		if(head == null || head.next == null){
			return head;
		}
		Node<Integer> smallAns = reverse(head.next);
		Node<Integer> tail = head.next;
		tail.next = head;
		head.next = null;
		return smallAns;
	}
}


class Reverse{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static Node<Integer> takeInput() throws IOException{

		String [] datas = br.readLine().trim().split("\\s");
		Node<Integer> head = null , tail = null;
		int i = 0;
		while(i < datas.length){
			int data = Integer.parseInt(datas[i]);
			Node<Integer> newNode = new Node<Integer>(data);
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

	static void printList(Node<Integer> head){
		Node<Integer> temp = head;
		while(temp != null){
			System.out.print(temp.data + " ");
			temp = temp.next;
		}System.out.println();
	}

	public static void main(String[] args) throws NumberFormatException , IOException{
		// System.out.println();
		Solution obj = new Solution();	
		int t = Integer.parseInt(br.readLine().trim());
		while(t > 0){
			Node<Integer> head = takeInput();
			System.out.println("The Linkedlist you entered is : ");
			printList(head);
			System.out.println("The Linkedlist after reversal is : ");
			Node<Integer> newHead = obj.reverse(head);
			printList(newHead);
			t--;
		}
	}
}