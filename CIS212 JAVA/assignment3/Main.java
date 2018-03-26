//Bin Li


import java.util.ArrayList;
import java.util.Random;

//import Math.random();

public class Main {
	private static final int MIN_VALUE = 0;

	public static void main(String[] args){
		//nextDouble();
		ArrayList<Measurable> Random = new ArrayList <Measurable>();
		double randNum = 0;
		int numBox = 0;
		int numCircle = 0;
		int numRect = 0;
		int numSphere = 0;
		for(int index = 0; index < 1000; index++){
			randNum = nextDouble();
			if(randNum <= .25){
				Random.add(new Box(nextDouble(), nextDouble(), nextDouble()));
				numBox++;
			}
			
			else if(randNum > .25 && randNum <= .5){
				Random.add(new Circle(nextDouble()));
				numCircle++;
			}
			
			else if(randNum > .5 && randNum <= .75){
				Random.add(new Rectangle(nextDouble(), nextDouble()));
				numRect++;
			}
			
			else if(randNum > .75 && randNum <= 1.0){
				Random.add(new Sphere(nextDouble()));
				numSphere++;
			}
			
		}
		System.out.println("rects: " + numRect + " boxes: " + numBox + 
				" circles: " + numCircle + " spheres: " + numSphere);
		
		System.out.println("sum: " + calculateSum(Random));
		
	}
	private static double nextDouble() {
		Random random = new Random();
		double randNum = random.nextDouble() * (1 - MIN_VALUE) + MIN_VALUE;
		return randNum;
	}
	
	private static double calculateSum(ArrayList <Measurable> AL){
		double sum = 0;
		for(int index = 0; index < AL.size(); index++){
			sum = sum + AL.get(index).getArea();
		}
		
		return sum;
	}
}

 
