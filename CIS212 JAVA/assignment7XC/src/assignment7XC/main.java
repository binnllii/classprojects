package assignment7XC;

import java.util.LinkedList;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.LinkedBlockingQueue;


public class main {
	public static int MAX_STRINGS = 100000;
	public static boolean producerrunning = false;
	
	public static void main(String[] args){
	
	LinkedList<String> queue   = new LinkedList<String>();
	ExecutorService executor = Executors.newCachedThreadPool();
	executor.submit(new producer(queue));
	
	executor.submit(new consumer(queue,1));
	executor.submit(new consumer(queue,2));
	executor.shutdown();


	

	}
}
