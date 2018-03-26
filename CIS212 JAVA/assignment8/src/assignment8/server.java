package assignment8;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;

public class server {
	private static final int PORT = 1337;
	
	public static void main(String[] args) {		
		System.out.println("running server!");
		
		ServerSocket serverSocket = null;
		Socket socket = null;
		ObjectOutputStream outputStream = null;
		ObjectInputStream inputStream = null;	
		ArrayList<Integer> primeList = new ArrayList<Integer>();
		
		try {
			serverSocket = new ServerSocket(PORT);
			//server socket create server socket connected to specified port
			System.out.println("server socket created");
			
			socket = serverSocket.accept();
			
			System.out.println("got socket: " + socket);
			
			// Always flush an object output stream preemptively (see docs).
			outputStream = new ObjectOutputStream(socket.getOutputStream());
			outputStream.flush();
			
			inputStream = new ObjectInputStream(socket.getInputStream());

			@SuppressWarnings("unchecked")
			ArrayList<Integer> sentList = (ArrayList<Integer>) inputStream.readObject();
			sentList = decryptList(sentList);
			
		
			for(int index = 0; index < sentList.size(); index++){
				if(isPrime(sentList.get(index))){
					primeList.add(sentList.get(index));
				}
			}
			
			
			System.out.println("client rec test: " + primeList);
			primeList = encryptList(primeList);
			outputStream.writeObject(primeList);
			outputStream.flush();
		} catch (IOException ex) {
			ex.printStackTrace();
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			// Close resources in finally block so that they
			// get closed even if we hit an exception above.
			try {
				if (serverSocket != null) {
					serverSocket.close();
				}
				if (socket != null) {
					socket.close();
				}
				if (outputStream != null) {
					outputStream.close();
				}
				if (inputStream != null) {
					inputStream.close();
				}
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}
		
		System.out.println("server finished");
	}
	static boolean isPrime(int n) {
	    if (n % 2 == 0 || n <= 1) {
	    	return false;
	    }
	    for(int i = 3; i*i <= n; i += 2) {
	        if(n % i == 0){
	            return false;
	        }
	    }
	    return true;
	}
	//source
	//https://www.mkyong.com/java/how-to-determine-a-prime-number-in-java/
	static ArrayList<Integer> encryptList(ArrayList<Integer> encrypt){
		ArrayList<Integer> encrypted = new ArrayList<Integer>();
		for(int i = 0; i < encrypt.size(); i++){
			encrypted.add(encrypt.get(i) + 1001);
			
		}
		return encrypted;
	}
	static ArrayList<Integer> decryptList(ArrayList<Integer> encrypt){
		ArrayList<Integer> decrypt = new ArrayList<Integer>();
		for(int i = 0; i < encrypt.size(); i++){
			decrypt.add(encrypt.get(i) - 1001);
			
		}
		return decrypt;
	}

}