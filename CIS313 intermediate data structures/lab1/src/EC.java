

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Objects;
import java.util.Scanner;


public class EC {
	public static void main(String[] args){
	
		// Create a Scanner that reads system input
		
		// Loop over the scanner's input
		// For each line of the input, send it to isPalindrome()
		// If isPalindrome returns true, print "This is a Palindrome." 
		// Otherwise print "Not a Palindrome."
		
		// Close the Scanner		
		Scanner x;	
//		x = new Scanner(new File("/Users/BinLi/Documents/workspace/lab1/src/inSample.txt"));
			x = new Scanner(System.in);
			x.nextLine();
			while(x.hasNext()){
				String number = x.nextLine();
				if(isPalindromeEC(number)){
					System.out.println("This is a Palindrome.");
				}
				else{
					System.out.println("Not a Palindrome.");
				}
			}
			x.close();
		} 
	
	

	public static boolean isPalindromeEC(String s){
	
		// Implement if you wish to do the extra credit.
				// Create a stack and a Queue of chars that represents the passed in string
	// Hint: While you loop through the given string, push the same char onto your stack
	//		 that you enqueue into your Queue. This way you can use dequeue to get 
	//       the string from left to right, but you pop the string from right to left
	
	// Compare your Queue and Stack to see if the input String was a Palindrome or not
	boolean track = true;

	Stack<Character> myStack = new Stack<Character>();
	TwoStackQueue<Character> myQueue = new TwoStackQueue<Character>();
	for (char ch: s.toCharArray()) {
		myStack.push(ch);
		myQueue.enqueue(ch);
	}
	for(int i = 0; i < s.length(); i++){
		Node<Character> checkQ = myQueue.dequeue();
		Node<Character> checkS = myStack.pop();
		
		if(!(Objects.equals(checkQ.getData(), checkS.getData()))){
			track = false;
		}
	}
	return track;
	}
}
