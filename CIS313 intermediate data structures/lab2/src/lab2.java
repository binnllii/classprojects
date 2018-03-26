

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class lab2 {
    public static void main(String[] args) throws FileNotFoundException {

        // Loop over the Scanner
        // Split each line into the task and the corresponding number (if one exists)
        // Depending on what the input task was, preform the corresponding function
        //      (ie) insert, delete, find, inoder, preorder, or postorder
        // Hint: Use a switch-case statement

        // Don't forget to close your Scanner!
    	
    	
     
		
    	BST<Integer> binary = new BST<Integer>();
//    	File file = new File("/Users/BinLi/Documents/workspace/lab2/src/lab2/inSample.txt");
    	@SuppressWarnings("resource")
		Scanner scan = new Scanner(System.in);

    	while(scan.hasNext()){
    		String[] Input = scan.nextLine().split(" ");
    	
    	
    		switch (Input[0]) {
    			case "insert":
    				binary.insert(Integer.parseInt(Input[1]));
    				
    				break;
    			case "preorder":
    				binary.traverse("preorder", binary.getRoot());
    				System.out.println("");
    				break;
    			case "inorder":
    				binary.traverse("inorder", binary.getRoot());
    				System.out.println("");
    				break;
    			case "postorder":
    				binary.traverse("postorder", binary.getRoot());
    				System.out.println("");
    				break;
    			case "delete":
    				binary.delete(Integer.parseInt(Input[1]));
    				break;
    			case "find":
    				Node<Integer> findTest = binary.find(Integer.parseInt(Input[1]));
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