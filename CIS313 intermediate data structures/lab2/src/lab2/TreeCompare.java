package lab2;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

import BST;
import Node;

public class TreeCompare {
	
	
	  public static void main(String[] args) throws FileNotFoundException {

	        // Loop over the Scanner
	        // Split each line into the task and the corresponding number (if one exists)
	        // Depending on what the input task was, preform the corresponding function
	        //      (ie) insert, delete, find, inoder, preorder, or postorder
	        // Hint: Use a switch-case statement

	        // Don't forget to close your Scanner!
	    	
	    	
	     
			
	    	BST<Integer> n1 = new BST<Integer>();
	    	BST<Integer> n2 = new BST<Integer>();
	    	File file = new File("/Users/BinLi/Documents/workspace/lab2/src/lab2/inSample.txt");
	    	@SuppressWarnings("resource")
			Scanner scan = new Scanner(file);

	    	while(scan.hasNext()){
	    		String[] Input = scan.nextLine().split(" ");
	    		boolean check = isInteger(Input[0]);
	    		if(check)
	    			for(int i = 0; i < Integer.parseInt(Input[0]); i++){
	    				switch (Input[0]) {
	    				case "insert":
	    					n1.insert(Integer.parseInt(Input[1]));
	    					System.out.println("LLL");
	    					break;
	    				case "preorder":
	    					n1.traverse("preorder", n1.getRoot());
	    					System.out.println("");
	    					break;
	    				case "inorder":
	    					n1.traverse("inorder", n1.getRoot());
	    					System.out.println("");
	    					break;
	    				case "postorder":
	    					n1.traverse("postorder", n1.getRoot());
	    					System.out.println("");
	    					break;
	    				case "delete":
	    					n1.delete(Integer.parseInt(Input[1]));
	    					break;
	    				case "find":
	    					Node<Integer> findTest = n1.find(Integer.parseInt(Input[1]));
	    					if(findTest != null){
	    						System.out.println("found" + findTest.getData());
	    					}
	    					else{
	    						System.out.println("cant find");
	    					}
	    				}
	    			}
	    		
	    		
	        	}
	    	}
	  
	    	
	    		
	    	
	  

	
	
	
//	private boolean compareTrees(BinaryTreeNode n1, BinaryTreeNode n2)
//	{
//	    if (n1 == null || n2 == null)
//	        return n1 == n2;  // i.e. both null
//
//	    if (n1.getNodeData() != n2.getNodeData())
//	        return false;
//
//	    return compareTrees(n1.left, n2.left) && compareTrees(n1.right, n2.right);
//	}
//}

public static boolean isInteger(String s) {
    boolean isValidInteger = false;
    try
    {
       Integer.parseInt(s);
       // s is a valid integer
       isValidInteger = true;
    }
    catch (NumberFormatException ex)
    {
       // s is not an integer
    }
    return isValidInteger;
 }
}
