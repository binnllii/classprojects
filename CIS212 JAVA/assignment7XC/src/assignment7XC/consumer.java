package assignment7XC;

import java.util.LinkedList;
import java.util.concurrent.BlockingQueue;

public class consumer implements Runnable{

	private LinkedList<String> _queue;
	private int _consumer;
	private String Max_String = " ";

	 public consumer(LinkedList<String> queue, int consumer) {
	        _queue = queue;
	        _consumer = consumer;
	        //System.out.println("check");
	    }
	private int _lengthofQueue = 0;
	@Override
	public void run() {
		
		while (_queue.isEmpty() || !main.producerrunning){
		synchronized(_queue) {
			  try {
				  _queue.wait();
				  String n = _queue.remove();
				  if(n.compareTo(Max_String) > 0){
					  n = Max_String;
				  }
				  _lengthofQueue++;
				  if(_lengthofQueue % 1000 == 0){
						System.out.println("consumer " + _consumer +"Consume value : " + _lengthofQueue);
					}
				  //System.out.println("Consuming value : " + n);

				 _queue.notifyAll();
			  }
			 catch (InterruptedException e) {
				e.printStackTrace();
			}
			//System.out.println("Consumer 1: " + n);
			 
		}
		
	}
	System.out.print("consumer " + _consumer + " done consuming!" + _lengthofQueue + " consumed");
	System.out.print("consumer " + _consumer + " max String" + Max_String);
}
}
	