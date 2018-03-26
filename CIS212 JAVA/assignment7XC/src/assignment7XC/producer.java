package assignment7XC;

import java.util.LinkedList;
import java.util.Random;
import java.util.concurrent.BlockingQueue;
import java.util.UUID;

public class producer implements Runnable{

	private static final int MAX_WAIT_MS = 500;
	private static final int TOTAL_ITEMS = 20000;
	private static final Object _lock = new Object();
	private LinkedList<String> _queue;
	
	 public producer(LinkedList<String> queue) {
	        _queue = queue;
	    }

	
	@Override
	public void run() {
			for(int i = 0; i < TOTAL_ITEMS; i++){
				
			try {
				synchronized (_queue) {
						//main.producerrunning = true;
						_queue.add(UUID.randomUUID().toString());
						if(i % 1000 == 0){
							System.out.println("produced: " + i);
						}
						_queue.notifyAll();
						main.producerrunning = true;
					}
				Thread.sleep(1);
			}
			catch (InterruptedException e) {
				e.printStackTrace();
			}
			
		}
		System.out.println("Done producing: " + TOTAL_ITEMS + " produced.");
	}
}

