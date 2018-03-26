public class RBT<E extends Comparable<E>> {
	private Node<E> root;
	private Node<E> nil;

    public RBT(){
        nil = new Node<E>(null);
        nil.setColor('B');
        root = nil;
        root.setLeftChild(nil);
        root.setRightChild(nil);
        root.setParent(nil);
    }

    public Node<E> getRoot(){
        return root;
    }

    public void insert(E data){
        // Preform a regular insert
        // Check to make sure the tree remains an RBT tree
    	Node<E> z = new Node<E>(data);
    	Node<E> y = nil;
    	Node<E> x = root;

    	while(x != nil){
    		y = x;
    		if(z.getData().compareTo(x.getData()) < 0){
    			x = x.getLeftChild();
    		} else{
    			x = x.getRightChild();
    		}
    	}
    	
        z.setParent(y);  
        
        if(y == nil){
        	root = z;
        } else if(z.getData().compareTo(y.getData()) < 0){
        	y.setLeftChild(z);
        } else{
        	y.setRightChild(z);	
        }
        z.setLeftChild(nil);
    	z.setRightChild(nil);
    	z.setColor('R');
        insertFixup(z);
        
    }
    
    public void insertFixup(Node<E> z){
    	while(z.getParent().getColor() == 'R'){
    		if(z.getParent() == z.getParent().getParent().getLeftChild()){
    			Node<E> y = z.getParent().getParent().getRightChild();
    			//case 1
    			if(y.getColor() == 'R'){
    				z.getParent().setColor('B');
    				y.setColor('B');
    				z.getParent().getParent().setColor('R');
    				z = z.getParent().getParent();
    			
    			}
    			//case 2
    			else{
    				if(z == z.getParent().getRightChild()){
    				z = z.getParent();
    				leftRotate(z);
    			}
    			//case 3
    			z.getParent().setColor('B');
    			z.getParent().getParent().setColor('R');
    			rightRotate(z.getParent().getParent());
    			}
    		}
    		else{
        		Node<E> y = z.getParent().getParent().getLeftChild();
        		//case 1
        		if(y.getColor() == 'R'){
        			z.getParent().setColor('B');
        			y.setColor('B');
        			z.getParent().getParent().setColor('R');
        			z = z.getParent().getParent();
        		}
        		//case 2
        		else {
        			if(z == z.getParent().getLeftChild()){
        				z = z.getParent();
        				rightRotate(z);
        			}
        			//case 3
        			z.getParent().setColor('B');
        			z.getParent().getParent().setColor('R');
        			leftRotate(z.getParent().getParent());
        			}
    			}	
    		}       	
    	getRoot().setColor('B');
    }
    
    public Node<E> search(E data){
        boolean done = false;
        Node<E> temp = root;
        while(!done){
            if (temp == nil){
                return null;
            }
            if(temp.getData().compareTo(data) == 0){
                done = true;
            } else if (temp.getData().compareTo(data) > 0){
                temp = temp.getLeftChild();
            } else if (temp.getData().compareTo(data) < 0){
                temp = temp.getRightChild();
            }
        }
        return temp;
    }
//    public Node<E> search(E data){
//        // Return the node that corresponds with the given data
//        // Note: No need to worry about duplicate values added to the tree
//    	
//    	Node<E> current = getRoot();
//    	boolean track = true;
//    	while(track){
//    		if(current == nil){
//    			track = false;
//    			return null;
//    		}
//    		else if(current.getData() == data){
//    			return current;
//    		}
//    		else if(current.getData().compareTo(data) > 0){
//    			current = current.getLeftChild();
//    		}
//    		else if(current.getData().compareTo(data) < 0){
//    			current = current.getRightChild();
//    		}
//    		
//    	}
//    	return current;
//    }
    public Node<E> treeMin(Node<E> x){
    	while(x.getLeftChild() != nil){
    		x = x.getLeftChild();
    	}
    	return x;
    }

    public void delete(E data){
    	Node<E> z = search(data);
    	if(z == null){
    		System.out.println("Not Found");
    		return;
    	}
    	Node<E> y = z;
    	Node<E> x;
    	char Color = y.getColor();
    	//when no left child
    	if(z.getLeftChild() == nil){
    		x = z.getRightChild();
    		transplant(z, z.getRightChild());
    	}
    	//when no right child
    	else if(z.getRightChild() == nil){ 
    		x = z.getLeftChild();
    		transplant(z, z.getLeftChild());
    	}
    	//when has 2 children. Its successor y is in its right subtree
        // and has no left child.
    	else{
    		y = getMin(z.getRightChild());
    		Color = y.getColor();
        	x = y.getRightChild();
        	if(y.getParent() == z){
        		x.setParent(y);
        	}
        	else{
        		transplant(y, y.getRightChild());
        		y.setRightChild(z.getRightChild());
        		y.getRightChild().setParent(y);
        	}
        	transplant(z,y);
        	y.setLeftChild(z.getLeftChild());
        	y.getLeftChild().setParent(y);
        	y.setColor(z.getColor());
        	
    	}
    	if(Color == 'B'){
    		deleteFixup(x);
    	}
    	
    }
    public void deleteFixup(Node<E> x){
    	while(x != root && x.getColor() == 'B'){
    		if(x == x.getParent().getLeftChild()){
    			// cases for parents right child
    			Node<E> w = x.getParent().getRightChild();
    			//case 1
    			if(w.getColor() == 'R'){
    				w.setColor('B');
    				x.getParent().setColor('R');
    				leftRotate(x.getParent());
    				w = x.getParent().getRightChild();
    			}
    			//case 2
    			if(w.getLeftChild().getColor() == 'B' && w.getRightChild().getColor() == 'B'){
    				w.setColor('R');
    				x = x.getParent();
    				
    			}
    			//case 3
    			else{
    				if(w.getRightChild().getColor() == 'B'){
    				w.getLeftChild().setColor('B');
    				w.setColor('R');
    				rightRotate(w);
    				w = x.getParent().getRightChild();
    			}
    			//case 4
    			w.setColor(x.getParent().getColor());
    			x.getParent().setColor('B');
    			w.getRightChild().setColor('B');
    			leftRotate(x.getParent().getParent());
    			x = root;
    		}
    		}
    		//cases for parents left child
    		else{
    			Node<E> w = x.getParent().getLeftChild();
    			if(w.getColor() == 'R'){
    				w.setColor('B');
    				x.getParent().setColor('R');
    				rightRotate(x.getParent());
    				w = x.getParent().getLeftChild();
    			}
    			if(w.getRightChild().getColor() == 'B' && w.getLeftChild().getColor() == 'B'){
    				w.setColor('R');
    				x = x.getParent();		
    			}else {
    				if(w.getLeftChild().getColor() == 'B'){
    				w.getRightChild().setColor('B');
    				w.setColor('R');
    				leftRotate(w);
    				w = x.getParent().getLeftChild();
    			}
    			w.setColor(x.getParent().getColor());
    			x.getParent().setColor('B');
    			w.getLeftChild().setColor('B');
    			rightRotate(x.getParent().getParent());
    			x = root;
    			}
    		}
    	}
    	
    	x.setColor('B');
    }
    
    
    public void transplant(Node<E> u, Node<E> v){
    	if(u.getParent() == nil){
    		root = v;
    	}else if(u == u.getParent().getLeftChild()){
    		u.getParent().setLeftChild(v);
    	}else{
    		u.getParent().setRightChild(v);
    	}
    	v.setParent(u.getParent());
    }
    public Node<E> getMin(Node<E> top){
        boolean done = false;
        Node<E> temp = top;
        while(!done) {
            if (temp.getLeftChild() == nil) {
                done = true;
            } else {
                temp = temp.getLeftChild();
            }
        }
        return temp;
    }
    
    public void traverse(String order, Node<E> top) {
        // Preform a preorder traversal of the tree
    	if (top != nil){
            switch (order) {
                case "preorder":
                    // Your Code here
                	if(top != nil){
                		System.out.printf("%d ",top.getData());
                		traverse("preorder", top.getLeftChild());
                		traverse("preorder", top.getRightChild());
                	}
                	break;
                
            }
    	}
    }

    public void rightRotate(Node<E> y){
    	
    	/*
    	If x is the root of the tree to rotate with left child subtree T1 and right child y, 
    	where T2 and T3 are the left and right children of y:
			x becomes left child of y and T3 as its right child of y
			T1 becomes left child of x and T2 becomes right child of x
		*/
		Node<E> x = y.getLeftChild();
		y.setLeftChild(x.getRightChild());
		if(x.getRightChild() != nil){
			x.getRightChild().setParent(y);
		}
		x.setParent(y.getParent());
		if(y.getParent() == nil ){
			root = x;
		}else if(y == y.getParent().getRightChild()){
			y.getParent().setRightChild(x);
		}else {
			y.getParent().setLeftChild(x);
		}
		x.setRightChild(y);
		y.setParent(x);
    }

    public void leftRotate(Node<E> x){
    
    	/*
    	If y is the root of the tree to rotate with right child subtree T3 and left child x, 
    	where T1 and T2 are the left and right children of x:
			y becomes right child of x and T1 as its left child of x
			T2 becomes left child of y and T3 becomes right child of y
		*/
    	//sets y
		Node<E> y = x.getRightChild(); 
		//turn y left subtree into x's
		x.setRightChild(y.getLeftChild());
		if(y.getLeftChild() != nil){
			y.getLeftChild().setParent(x);
		}
		//links x parent to y
		y.setParent(x.getParent());
		if(x.getParent() == nil ){
			root = y;
		} else if(x == x.getParent().getLeftChild()){
			x.getParent().setLeftChild(y);
		} else {
			x.getParent().setRightChild(y);
			
		}
		
		//puts x on y's left
		y.setLeftChild(x);
		x.setParent(y);
    }
    
//  public boolean isRBT(Node<E> node){
//	  boolean track = false;
//	  root = node;
//  }
}