//Bin Li


import java.lang.Math;


public class Circle implements Measurable{
	protected double _radius;
	private double area;
	
	public Circle(double radius){
		_radius = radius;
	}

	@Override
	public double getArea() {
		area = (Math.PI * Math.pow(_radius, 2));
		return area;
	}
	
}
