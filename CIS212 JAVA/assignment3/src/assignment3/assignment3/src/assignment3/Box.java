//Bin Li

package assignment3;

import Rectangle;

public class Box extends Rectangle{
	private double _height;
	private double area;
	
	public Box(double length, double width, double height){
		super(length, width);
		_height = height;
	}
	@Override
	public double getArea() {
		area = (2 * (getlength() * _height)) + (2 * (getwidth() * _height)) + (2 * (getwidth() * getlength()));
		return area;
	}
}
