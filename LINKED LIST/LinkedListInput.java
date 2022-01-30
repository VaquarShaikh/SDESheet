
package Samplee;

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

class LinkedListInput{

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
		}
	}

	public static void main(String[] args) throws NumberFormatException , IOException{
		// int t = Integer.parseInt(br.readLine().trim());
		// while(t > 0){
			Node<Integer> head = takeInput();
			printList(head);
			RevLL obj = new RevLL();
			Node res = obj.reverseList(head);
			System.out.println(res.data);
			// t--;
		// }
	}
}