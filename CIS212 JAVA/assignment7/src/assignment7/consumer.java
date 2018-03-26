package assignment7;


import java.util.HashMap;
import java.util.Random;
import java.util.concurrent.LinkedBlockingQueue;

public class consumer implements Runnable{

	private int MAX_WAIT_MS = 10;
	private LinkedBlockingQueue<String> _queue;
	private int _consumer;
	private String Max_String = " ";
	private int _lengthofQueue = 0;

	 public consumer(LinkedBlockingQueue<String> queue, int consumer) {
	        _queue = queue;
	        _consumer = consumer;
	        //System.out.println("check");
	    }
	@Override
	public void run() {
		Random random = new Random();
		
		while(!producer.checkString()){
			try {
				Thread.sleep(random.nextInt(MAX_WAIT_MS));
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		while (!_queue.isEmpty()){
				  String n = _queue.poll();
				  if(n.compareTo(Max_String) > 0){
					  Max_String = n;
				  }
				  _lengthofQueue++;
				  if(_lengthofQueue % 1000 == 0){
						System.out.println("consumer " + _consumer +" Consumed : " + _lengthofQueue);
					}
				 
					try {
						Thread.sleep(random.nextInt(MAX_WAIT_MS));
					} catch (InterruptedException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
			  }
			 
	System.out.println("consumer " + _consumer + " done consuming! " + _lengthofQueue + " consumed");
	System.out.println("consumer " + _consumer + " max String: " + Max_String);
}
}
	
