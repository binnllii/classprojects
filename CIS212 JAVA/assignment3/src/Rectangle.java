//Bin Li



public class Rectangle implements Measurable {
	private double _length;
	private double _width;
	private double area;
	//setters
	public Rectangle(double length, double width) {
		_length = length;
		_width = width;
	}
	//getters
	@Override
	public double getArea() {
		area = _length * _width;
		return area;
	}
	public double getlength(){
		return _length;
	}
	public double getwidth(){
		return _width;
	}
}
