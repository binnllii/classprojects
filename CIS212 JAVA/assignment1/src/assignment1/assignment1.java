
package assignment1;
import java.util.Scanner; 

public class assignment1 {
	public static void main(String[] args) {
	Scanner scanner = new Scanner(System.in);
	
	boolean running = true;
	int total = 0;
	while (running){
        System.out.println("Enter a positive integer (-3 to "
        		+ "print, -2 to reset, -1 to quit):");
        int i = scanner.nextInt();
        if(i == -3){
        	System.out.println("Sum: " + total);
        }
        else if(i == -2){
        	total = 0;
        }
        else if(i == -1){
        	System.out.println("Sum: " + total);
        	running = false;
        }
        else if(i < -3){
        	total = total + 0;
        }
        else{
        total = total + i;
        }
    }
	scanner.close();
}
}