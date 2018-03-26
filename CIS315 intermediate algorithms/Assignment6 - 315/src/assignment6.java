import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Set;

public class assignment6 {
	public static Set<String> dictionary = new HashSet<String>();
	public static int[] lineT;
	public static boolean[] islist;
  	public static int[] Length;
  	public static int[] L2;
	
	public static void main(String[] args){
		//Scanner sc = new Scanner(System.in);
		loadDictionary("diction10k.txt");

		System.out.println("\n");
		
		int fNum = 0;
		String word;
	    //File file = new File("/Users/BinLi/Documents/workspace/Assignment6 - 315/src/inSample.txt");
	    //Scanner sc = new Scanner(file);
		Scanner sc = new Scanner(System.in);
	    fNum = sc.nextInt();
	    sc.nextLine();
	    for(int i = 0; i < fNum; i++){ 
	    	word = sc.nextLine();
	    	System.out.println("phrase number: " + (i+1));
	    	iterative(word);
	    	recursive(word);
	    	
	    }
	    
	    sc.close();
	}
	
	
public static boolean dict(String word){
	boolean checker = false;
	if(dictionary.contains(word)){
		checker = true;
	}
	return checker;
	
}	


public static boolean iterative(String word){
	System.out.println(word + "\n" + "\n" + "iterative attempt:");
	int n = word.length(); 
	lineT = new int[word.length()+1];
	islist = new boolean[word.length()+1];
	lineT[n] = word.length();
	String line;
	islist[n] = true;
	boolean tracker = true;
	for(int i = n; i >= 0; i--){	
		for(int j = i; j < n; j++){
			line = word.substring(i, j+1);
			if(dict(line) && islist[j+1]){
				islist[i] = true;
				lineT[i] = j;
			}
		}	
	}
	
	if(!islist[0]){
		System.out.println("NO, cannot be split!");
		System.out.println(word);;
		tracker = false;
	}else{

		System.out.println("YES, can be split!");
		int t = 0;
		while(t < word.length()){
			line = word.substring(t, lineT[t]+1);
			System.out.print(line + " ");
			t = lineT[t]+1;
		}	
	}
	System.out.println("\n");
	
	return tracker;
	
}




public static void recursive(String word) {
	System.out.println("memoized attempt:");
	int len = word.length();
	L2 = new int[len + 1];
	Length = new int[len + 1];
	Arrays.fill(Length, -99);
	L2[len] = len;
	Length[len] = 1;
	
	int recursive = isWord(Length, L2, word, 0);
	 
    if (recursive != 1) {
        System.out.println("NO, cannot be split!");
        System.out.println(word + "\n");
        return;
    }else{
    	System.out.println("YES, can be split!");
    	String word2;
    	int k = 0;
    	while (k < len) {
    		word2 = word.substring(k, L2[k] + 1);
    		System.out.print(word2 + " ");
    		k = L2[k] + 1;
    	}
    }
     System.out.println("\n");
}

 public static int isWord(int[] Length, int[] L2, String line, int i) {   
	 String word;
	 if (Length[i] == -99){
		 Length[i] = 0;
		 for (int j = i; j < line.length(); j++) {
			 word = line.substring(i, j+1);
			 
			 if (dict(word) && isWord(Length, L2, line, j + 1) == 1) {
				 Length[i] = 1;
				 L2[i] = j;
			 }
		 }
	 }
     return Length[i];
 }


public static void loadDictionary(String dictionaryFileName){
	File inFile = new File(dictionaryFileName);
	try {
		Scanner scan = new Scanner(inFile);
		String line;
		while (scan.hasNext()) {
			line = scan.next();
			dictionary.add(line.trim());
		}//while
		scan.close();
		} //try block
		catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
}
