package assignment7;


import java.util.Random;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.UUID;

public class producer implements Runnable{


	private LinkedBlockingQueue<String> _queue;
	public static boolean isFilled = false;
	private int productionCount = 0;
	
	 public producer(LinkedBlockingQueue<String> queue) {
	        _queue = queue;
	    }

	
	@Override
	public void run() {
		Random random = new Random();
			for(int i = 0; i < 2000; i++){
			try {
				Thread.sleep(random.nextInt(1000));
				}
			catch (InterruptedException e) {
				e.printStackTrace();
				
			}
			int begin = i * 1000;
			int end = begin + 1000;
			for(int j = begin; j < end; j++){
				String randomID = UUID.randomUUID().toString();
				try {
					_queue.put(randomID);
					isFilled = true;
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				productionCount++;
			}
			System.out.println("Produced: " + (i + 1) * 1000);
			//productionCount++;
		}
		
		System.out.println("Done producing! " + productionCount + " produced.");
	}
	public static boolean checkString(){
		return isFilled;
	}
}


