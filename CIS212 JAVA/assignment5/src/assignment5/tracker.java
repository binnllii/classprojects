package assignment5;

public class tracker {
	private int _number;
	private String _fullName;
	
	public tracker(int number, String fullName){
		_number = number;
		_fullName = fullName;
	}
	public int getNumber(){
		return _number;
	}
	public String getfullName(){
		return _fullName;
	}
}