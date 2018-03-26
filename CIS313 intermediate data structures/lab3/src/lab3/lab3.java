

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class lab3 {
    public static void main(String[] args) throws FileNotFoundException {
    
    	// Loop over the Scanner
        // Split each line into the task and the corresponding number (if one exists)
        // Depending on what the input task was, preform the corresponding function
        //      (ie) insert, maximum, extractMax, isEmpty, or print
        // Hint: Use a switch-case statement

        // Don't forget to close your Scanner!
    	
    	
//    	File file = new File("/Users/BinLi/Documents/workspace/lab3/src/lab3/inSample.txt");
//    	@SuppressWarnings("resource")
		Scanner scan = new Scanner(System.in);
//    	Scanner scan = new Scanner(file);
    	int inputSize = Integer.parseInt(scan.nextLine());
    	
    	pQueue<Integer> queue = new pQueue<Integer>(inputSize);
    	
    	while(scan.hasNext()){
    		String[] input = scan.nextLine().split(" ");
    		
    		switch(input[0]){
    			case "insert":
    				queue.insert(Integer.parseInt(input[1]));
    				break;
    			case "isEmpty":
    				if(queue.isEmpty()){
    					System.out.println("Empty");
    				}
    				else{
    					System.out.println("Not Empty");
    				}
    				break;
    			case "print":
    				queue.print();
    				System.out.println("");
    				break;
    			case "maximum":
    				System.out.println(queue.maximum());
    				break;
    			case "extractMax":
    				System.out.println(queue.extractMax());
    				break;
    				
    			case "build":
    				//seperates the array
    				String[] array = input[1].replaceAll("\\[", "").replaceAll("\\]", "")
    						.replaceAll("\\s", "").split(",");
    				//creates the int array
    				Integer[] intArr = new Integer[array.length + 1];
    				//transfers the string array into the int array
    				for(int i = 1; i < intArr.length; i++){
    					intArr[i] = Integer.parseInt(array[i-1]);
    				}
    				queue.build(intArr);

    		}
    	}
    }
}
