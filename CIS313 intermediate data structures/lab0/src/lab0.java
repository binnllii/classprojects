
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
public class lab0 {  
	public static void main(String[] args) throws FileNotFoundException{
	    
	Scanner x;
	
	x = new Scanner(new File("/Users/BinLi/Documents/workspace/assignment0/src/inSample.txt"));
	x.nextLine();
	while(x.hasNext()){     
		int a = x.nextInt();  
		int b = x.nextInt();    
		int g = gcd(a,b);     
		int l = lcm(a,b);    
		System.out.println(g + " " + l);   
		}  
	x.close();
	}


 public static int gcd(int a, int b){   
	 // Find the greatest common divisor of a and b   // Hint: Use Euclids Algorithm  
	 int lowNum = 0;
	 int bigNum = 0;
	 int finalNum = 0;
	 if(a > b){
		 lowNum = b;
		 bigNum = a;
	 }
	 else{
		 bigNum = b;
		 lowNum = a;
	 }
	 while(bigNum % lowNum != 0){
		 finalNum = lowNum;
		 lowNum = bigNum % lowNum;
		 bigNum = finalNum;
	 }
	 return lowNum;
 }
 public static int lcm(int a, int b){   
	 // Find the least common multiple of a and b   // Hint: Use the gcd of a and b
	 int temp = gcd(a, b);
	 return a*b/temp;
	 } 
}
