import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

public class assignment2 {
    public static void main(String[] args) throws FileNotFoundException{
        //Scanner sc = new Scanner(System.in);
        
    	//variables for for loops and etc
        int p,k,j,n, edges, nodes, graphs,
        graphcounter = 0, prevNum = 1, shortestPath = 0;
      File file = new File("/Users/BinLi/Documents/workspace/Assignment2-315/src/inSample.txt");
    	Scanner sc = new Scanner(file);
    	graphs = sc.nextInt();
    	
        for( int i = 0; i < graphs; i++){    	
        	graphcounter++;
        	//declare the adj_list
        	ArrayList<LinkedList<Integer>> adj_list = new ArrayList<LinkedList<Integer>>();
        	nodes = sc.nextInt();
            edges = sc.nextInt();
        
        	for(n = 0; n < nodes; n++){
            	adj_list.add(new LinkedList<Integer>());
            }
        	
        	
        	//iterates the values in txt folder
        	for(j = 0; j < edges; j++){
        		adj_list.get(sc.nextInt()).add(sc.nextInt());
        	}        	
        	
        	
            int Numpath[] = new int[nodes + 1];
            Numpath[1] = 1;
            
            //allocates a value to all locations of the array
            for(k = 2; k <= nodes; k++){
            	Numpath[k] = 0;
            }
            prevNum = adj_list.get(1).getLast();
            //counts the number of paths
            for(p = 1; p <= nodes-1; p++){            	
            	for(j = p + 1; j <= nodes; j++){            		
            		if(adj_list.get(p).contains(j)){	       			
            			Numpath[j] = Numpath[j] + Numpath[p];
                    	//calculates the shortest path
                		if(p >= prevNum){
                			prevNum = adj_list.get(p).getLast(); //gets last element of desired adj list
                			shortestPath++;
                			
                		}                		      		
            		}	
            	}
            }
            //print all the answers
            System.out.println("graph number: " + graphcounter);
            System.out.println("shortest path: " + (shortestPath + 1));
            //the longest path is just p - 1
            System.out.println("longest path: " + (p - 1));
            System.out.println("Number of paths: " + Numpath[nodes]);
            System.out.println();
            shortestPath = 0;
     
        }           
        sc.close();
    }
}
