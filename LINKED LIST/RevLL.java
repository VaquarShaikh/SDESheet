package Sample;

import java.util.*;
import java.util.Arrays;
import java.util.Scanner;
import java.io.*;

class RevLL{
	public Node<Integer> reverseList(Node<Integer> head){
		if(head == null || head.next == null){
			return head;
		}
		Node<Integer> smallAns = reverseList(head.next);
		Node<Integer> tail = head.next;
		tail.next = head;
		head.next = null;
		return smallAns;
	}
}