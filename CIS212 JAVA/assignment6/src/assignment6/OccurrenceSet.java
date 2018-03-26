package assignment6;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.Map;
import java.util.Map.Entry;


public class OccurrenceSet<T> implements Set<T>{
	HashMap<T, Integer> map = new HashMap<>();
	
	@Override
	public boolean add(T m1){
		boolean track = false;
		if(map.get(m1) == null){
			map.put(m1, 1);
		}
		else{
			map.put(m1, map.get(m1) + 1);
			track = true;
		}
		return track;
	}
	
	@Override
	public boolean remove(Object m1) {
		boolean check = false;
		if(map.get(m1) != null){
			map.remove(m1);
			check = true;
		}
		return check;
	}
	
	@Override
	public boolean contains(Object o) {
		return map.containsKey(o);
	}
	
	@Override
	public boolean removeAll(Collection<?> c) {
		boolean track = false;
		for(Object i: c){
			if(map.get(i) == null){
				track = false;
			}
			else{
				map.remove(i);
				track = true;
			}
		}
		return track;
	}
	
	@Override
	public boolean containsAll(Collection<?> c) {
		boolean track = true;
		for (Object i: c){	
			if(map.get(i) == null){
				track = false;
			}
		}
		return track;
	}
	
	@Override
	public boolean retainAll(Collection<?> c) {
		boolean track = false;
		Set<T> hash = map.keySet();
		ArrayList<T> myList = new ArrayList<T>(hash);
		for(T i : myList){
			if(c.contains(i) == false){
				remove(i);
				track = true;
			}
		}
		return track;
	}
	
	@Override
	public boolean addAll(Collection<? extends T> c) {
		boolean check = false;
		int counter = 0;
		for(T i: c){
			check = add((T) i);
			if(check == false){
				counter++;
			}
		}
		if(counter > 0){
			check = true;
		}
		return check;
	}

	@Override
	public int size() {
		return map.size();
	}

	@Override
	public boolean isEmpty() {
		boolean track = false;
		if(map.size() == 0){
			track = true;
		}
		return track;
	}


	@Override
	public Iterator<T> iterator() {
		Set<Entry<T, Integer>> entrySet = map.entrySet();
		ArrayList<Entry<T, Integer>> entryList = new ArrayList<>(entrySet);
		Collections.sort(entryList, 
				new Comparator<Map.Entry<T,Integer>>() {
					@Override
					public int compare(Map.Entry<T, Integer> o1, Map.Entry<T, Integer> o2) {
						return o1.getValue().compareTo(o2.getValue());
					}		
		});
		Iterator<T> it = new Iterator<T>(){
			int _index = 0;
			
			@Override
			public boolean hasNext(){
				return _index < entryList.size();
			}
			@SuppressWarnings("unchecked")
			@Override
			public T next() {
				return (T) entryList.get(_index++);
			}
			@Override
			public void remove(){
				entryList.remove(_index);
			}
		};
		return it;
	}

	@SuppressWarnings("unchecked")
	@Override
	public Object[] toArray() {
		Iterator<T> it = iterator();
		Object[] arraySorted = new Object[map.size()];
		int count = 0;
		while(it.hasNext()) {
			arraySorted[count] = it.next();
			arraySorted[count] = ((Entry<T, Integer>) arraySorted[count]).getKey();
			count++;
		}
		return arraySorted;
			

	}

	@Override
	public <T> T[] toArray(T[] List) {
			Arrays.sort(List);
			return List;
		}
	

	@Override
	public void clear() {
		map.clear();
	}
	
	public String toString(){
		Object[] newArr = toArray();
		String[] strEntry = new String[newArr.length];
		for (int i = 0; i < newArr.length; i++){
			strEntry[i] = newArr[i].toString();
		}
		return Arrays.toString(strEntry);
		
	}
}
	
	
		

	
