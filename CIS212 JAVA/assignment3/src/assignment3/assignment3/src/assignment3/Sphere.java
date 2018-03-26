package assignment3;

import Circle;

public class Sphere extends Circle{
	//private double area;
	
	public Sphere(double radius) {
		super(radius);
	}
	
	@Override
	public double getArea() {
		return (4 * (Math.pow(_radius, 2)) * Math.PI);
	}
}
