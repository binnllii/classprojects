public class BST<E extends Comparable<E>> {
    private static final String red = null;
	private Node<E> root;
    public BST(){
        root = null;
    }

    public Node<E> getRoot(){
        return root;
    }
    
    
    
    public void insert(E data){
        boolean done = false;
        Node<E> temp = root;

        while(!done){
            if (root == null) {
                root = new Node<E>(data);
                done = true;
            } else if (temp.getData().compareTo(data) > 0){
                if (temp.getLeftChild() == null){
                    temp.setLeftChild(new Node<E>(data));
                    temp.getLeftChild().setParent(temp);
                    done = true;
                }
                temp = temp.getLeftChild();
            } else if (temp.getData().compareTo(data) <= 0){
                if (temp.getRightChild() == null){
                    temp.setRightChild(new Node<E>(data));
                    temp.getRightChild().setParent(temp);
                    done = true;
                }
                temp = temp.getRightChild();
            }
            
        }
    }


    public Node<E> find(E data){

        // Search the tree for a node whose data field is equal to data
    	Node<E> current = getRoot();
    	boolean track = true;
    	
    	while(track){
    		if(current == null){
    			track = false;
    			return null;
    		}
    		else if(data == current.getData()){
    			track = false;
    			return current;
    		}
    		else if(data.compareTo(current.getData()) > 0){
    			current = current.getRightChild();
    		}
    		else if(data.compareTo(current.getData()) < 0){
    			current = current.getLeftChild();
    		}
    	}
    	return null;
    }
 

    public void delete(E data){
        // Find the right node to be deleted

        // If said node has no children, simply remove it by setting its parent to point to null instead of it.
        // If said node has one child, delete it by making its parent point to its child.
        // If said node has two children, then replace it with its successor,
        //          and remove the successor from its previous location in the tree.
        // The successor of a node is the left-most node in the node's right subtree.
        // If the value specified by delete does not exist in the tree, then the structure is left unchanged.

        // Hint: You may want to implement a findMin() method to find the successor when there are two children
    	
    	
    	Node<E> current = find(data);
    	Node<E> parent = current.getParent();
  
    	if(current != null){
    		if(current == getRoot()){
    			if(current.getRightChild() == null && current.getLeftChild() == null){
    				root = null;
    			}
    			else if(current.getRightChild() != null && current.getLeftChild() == null){
    				root = current.getRightChild();
    				root.setParent(null);
    			}
    			else if(current.getRightChild() == null && current.getLeftChild() != null){
    				root = current.getLeftChild();
    				root.setParent(null);
    			}
    			else if(current.getRightChild() != null && current.getLeftChild() != null){
    				
    				Node<E> successor = findMin(current.getRightChild());
    				successor.getParent().setLeftChild(null);
    				successor.setRightChild(current.getRightChild());
        			successor.setLeftChild(current.getLeftChild());
        			successor.setParent(parent);
        			current.getLeftChild().setParent(successor);
        			current.getRightChild().setParent(successor);
        			root = successor;
    			}
    		}else{
    		
	    	if(current.getRightChild() == null && current.getLeftChild() == null){
	    		if(parent.getLeftChild() == current){
	    			parent.setLeftChild(null);
	    		}
	    		else{
	    			parent.setRightChild(null);
	    		}
	    	}
	    	//Right child
	    	else if(current.getRightChild() != null && current.getLeftChild() == null){
	    		if(parent.getRightChild() == current){
	    			parent.setRightChild(current.getRightChild());
	    			current.getRightChild().setParent(parent);
	    		}
	    		else{
	    			parent.setLeftChild(current.getRightChild());
	    			current.getRightChild().setParent(parent);
	    		}
	    	}
	    	//left Child
	    	else if(current.getRightChild() == null && current.getLeftChild() != null){
	    		if(parent.getLeftChild() == current){
	    			parent.setLeftChild(current.getLeftChild());
	    			current.getLeftChild().setParent(parent);
	    		}
	    		else{
	    			parent.setRightChild(current.getLeftChild());
	    			current.getLeftChild().setParent(parent);
	    		}
	    	}
	    	//2 childs
	    	else if(current.getRightChild() != null && current.getLeftChild() != null){
	    		Node<E> successor = findMin(current.getRightChild());
	    		if(parent.getRightChild() == current){
	    			successor.getParent().setLeftChild(null);
	    			successor.setRightChild(current.getRightChild());
	    			successor.setLeftChild(current.getLeftChild());
	    			successor.setParent(parent);
	    			current.getLeftChild().setParent(successor);
	    			current.getRightChild().setParent(successor);
	    			parent.setRightChild(successor);
	    		}
	    		else{
	    			successor.getParent().setLeftChild(null);
	    			successor.setRightChild(current.getRightChild());
	    			successor.setLeftChild(current.getLeftChild());
	    			successor.setParent(parent);
	    			current.getLeftChild().setParent(successor);
	    			current.getRightChild().setParent(successor);
	    			parent.setLeftChild(successor);
	    		}
	    	}
    	}
    }
    }
    public Node<E> findMin(Node<E> node){
    	Node<E> current = node;
    	
    	while(current.getLeftChild() != null){
    		current = current.getLeftChild();
    	}
    	return current;
    }

    public void traverse(String order, Node<E> top) {
        if (top != null){
        	
            switch (order) {
                case "preorder":
                    // Your Code here
                	if(top != null){
                		System.out.printf("%d ",top.getData());
                		traverse("preorder", top.getLeftChild());
                		traverse("preorder", top.getRightChild());
                	}
                    break;
                case "inorder":
                    // Your Code here
                	if(top != null){
                		traverse("inorder", top.getLeftChild());
                		System.out.printf("%d ",top.getData());
                		traverse("inorder", top.getRightChild());
                		
                	}
                    break;
                case "postorder":
                    // Your Code here
                	if(top != null){
                		traverse("postorder", top.getLeftChild());
                		traverse("postorder", top.getRightChild());
                		System.out.printf("%d ",top.getData());
                	}
                    break;
            }
    }
}
}

