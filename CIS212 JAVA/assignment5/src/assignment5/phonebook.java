package assignment5;

import java.util.*;
import java.io.File;
import java.util.ArrayList;
import javax.swing.JFrame;


public class phonebook{
	
	//#1
	public static void main(String[] args){
		
			ArrayList<tracker> list = new ArrayList<tracker>();
			try{
				Scanner x = new Scanner(new File("/Users/BinLi/Documents/workspace/assignment5/src/assignment5/phonebook.txt"));
					while(x.hasNextLine()){
						int number = x.nextInt();
						String lname = x.next();
						String fname = x.next();
						String fullName  = lname + " " + fname;
						list.add(new tracker(number, fullName));
					}
					x.close();
			}
			catch(Exception e){
				System.out.println("Cannot find file!");
			}
			mainFrame frame = new mainFrame(list);
			frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			frame.pack();
			frame.setVisible(true);
	}	
	
	//#2
	public static ArrayList<tracker> selectionSort(ArrayList<tracker> data){
		int smallest;
		for(int i = 0; i < data.size() - 1; i++){
			smallest = i;
			for(int index = smallest; index < data.size(); index++){
				if(data.get(index).getfullName().compareTo(data.get(i).getfullName()) < 0 ){
					smallest = index;
					Collections.swap(data, i, smallest);
				}
			}
		}
		return data;
	}
	
	//#3
	public static ArrayList<tracker> mergeSort(ArrayList<tracker> data){
		ArrayList<tracker> left = new ArrayList<tracker>();
	    ArrayList<tracker> right = new ArrayList<tracker>();
	    int center;
	 
	    if (data.size() == 1) {    
	        return data;
	    } else {
	        center = data.size()/2;
	        // copy the left half of whole into the left.
	        for (int i = 0; i < center; i++) {
	                left.add(data.get(i));
	        }
	 
	        //copy the right half of whole into the new arraylist.
	        for (int i = center; i < data.size(); i++) {
	                right.add(data.get(i));
	        }
	 
	        // Sort the left and right halves of the arraylist.
	        left  = mergeSort(left);
	        right = mergeSort(right);
	 
	        // Merge the results back together.
	        merge(left, right, data);
	    }
	    return data;
	}
	
	private static void merge(ArrayList<tracker> left, ArrayList<tracker> right, ArrayList<tracker> whole) {
	    int leftIndex = 0;
	    int rightIndex = 0;
	    int wholeIndex = 0;
	 
	    // As long as neither the left nor the right ArrayList has
	    // been used up, keep taking the smaller of left.get(leftIndex)
	    // or right.get(rightIndex) and adding it at both.get(bothIndex).
	    while (leftIndex < left.size() && rightIndex < right.size()) {
	        if (left.get(leftIndex).getfullName().compareTo(right.get(rightIndex).getfullName()) < 0) {
	            whole.set(wholeIndex, left.get(leftIndex));
	            leftIndex++;
	        } else {
	            whole.set(wholeIndex, right.get(rightIndex));
	            rightIndex++;
	        }
	        wholeIndex++;
	    }
	 
	    ArrayList<tracker> rest;
	    int restIndex;
	    if (leftIndex >= left.size()) {
	        // The left ArrayList has been use up...
	        rest = right;
	        restIndex = rightIndex;
	    } else {
	        // The right ArrayList has been used up...
	        rest = left;
	        restIndex = leftIndex;
	    }
	 
	    // Copy the rest of whichever ArrayList (left or right) was not used up.
	    for (int i = restIndex; i < rest.size(); i++) {
	        whole.set(wholeIndex, rest.get(i));
	        wholeIndex++;
	    }
	}
//code source
//http://www.codexpedia.com/java/java-merge-sort-implementation/
	
	//#4
	public static boolean trueorFalse(ArrayList<tracker> data){
		boolean sorted = true;
		for (int i = 1; i < data.size(); i++) {
	        if (data.get(i - 1).getfullName().compareTo(data.get(i).getfullName()) > 0){
	        	sorted = false;
	        }
	    }
	    return sorted;
	}
}
	
	
	
	
	
	
	
	
	
	