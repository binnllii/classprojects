


@SuppressWarnings("rawtypes")
public class MaxHeap<E extends Comparable> {
    private E[] myArray;
    private int maxSize;
    private int length;

    
    @SuppressWarnings("unchecked")
	public MaxHeap(int s){
    	// Build the constructor
    	maxSize = s;
    	length = 0;
    	myArray =  (E[]) new Comparable[maxSize + 1];
    }

	// helper functions
    public E[] getArray(){
        return myArray;
    }

    public void setArray(E[] newArray){
    	if (newArray.length > maxSize+1){
    		return;
    	}
        myArray = newArray;
        length = newArray.length-1;
    }

    public int getMaxSize(){
        return maxSize;
    }

    public void setMaxSize(int ms){
        maxSize = ms;
    }

    public int getLength(){
        return length;
    }

    public void setLength(int l){
        length = l;
    }

    // Other Methods
    
	@SuppressWarnings({ "unchecked"})
	public void insert(E data){
    
    	// Insert an element into your heap.
    	
    	// When adding a node to your heap, remember that for every node n, 
    	// the value in n is less than or equal to the values of its children, 
    	// but your heap must also maintain the correct shape.
		// (ie there is at most one node with one child, and that child is the left child.)
		// (Additionally, that child is farthest left possible.)
		
		length++;
		int tempLen = length;
		myArray[tempLen] = data;
		//while tempLen is not Root and myArray[tempLen] is greater than myArray[tempLen/2]
        while((tempLen > 1) && (myArray[tempLen / 2].compareTo(myArray[tempLen]) < 0)){
        	//swaps myArray[tempLen] and myArray[tempLen/2]
        	E tempData = myArray[tempLen / 2];
        	myArray[tempLen / 2] = myArray[tempLen];
        	myArray[tempLen] = tempData; 
        	tempLen = tempLen / 2;
        	
        }
       }
	


    @SuppressWarnings("unchecked")
	public Comparable<E> maximum(){
        // return the maximum value in the heap
    	return myArray[1];
    }
    @SuppressWarnings("unchecked")
    public Comparable<E> extractMax(){
        // remove and return the maximum value in the heap
    	E max = myArray[1];
    	myArray[1] = myArray[length];
    	length--;
    	heapify(1);
    	return max;
    }
    

	public void heapify(int i){
    	// helper function for reshaping the array
    	int rightSide = i * 2 + 1;
    	int leftSide = i * 2;
    	int largest = i;
    	//for left child greater than condition
    	if((leftSide <= length) && ((int)myArray[largest] < (int) myArray[leftSide])){
    		largest = leftSide;
    	}
    	//for right child greater than condition
    	if(((rightSide <= length) && (int) myArray[largest] < (int) myArray[rightSide])){
    		largest = rightSide;	
    	}
    	//swaps the 2 values
    	if(largest != i){
    		E temp = myArray[largest];
    		myArray[largest] = myArray[i];
    		myArray[i] = temp;
    		heapify(largest);		
    	}	
    }

    public void buildHeap(E[] newArr){
		// used for the extra credit
    	//sets the build array and covers the old one then calls heapify on it
    	setArray(newArr);
    	for(int j = length/2; j > 0; j--){
    		heapify(j);
    	}
	}
}