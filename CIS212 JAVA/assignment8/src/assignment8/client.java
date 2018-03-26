package assignment8;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.InetAddress;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Scanner;

public class client {
	private static final int PORT = 1337;
	
	public static void main(String[] args) {
		Socket socket = null;
		ObjectOutputStream outputStream = null;
		ObjectInputStream inputStream = null;
		ArrayList<Integer> sentList = new ArrayList<Integer>(); 
		Scanner reader = new Scanner(System.in);
		
		
		System.out.println("Enter a number, blank line to quit: ");
		String nextCheck = reader.nextLine();
		while(true){
			if(nextCheck.equals("")){
				break;
			}
			try{
				int n = Integer.parseInt(nextCheck);
				sentList.add(n);
			}
			catch(Exception e){
				System.out.println("not an int");
			}
			System.out.println("Enter a number, blank line to quit: ");
			nextCheck = reader.nextLine();
		}
		reader.close();
		
		try {
			InetAddress address = InetAddress.getLocalHost();
			socket = new Socket(address, PORT);
			//socket creates stream socket and connect to specified port number.
			System.out.println("server socket created");
			//
			outputStream = new ObjectOutputStream(socket.getOutputStream());
			outputStream.flush();
			//writes tospecified output stream
			inputStream = new ObjectInputStream(socket.getInputStream());
			//objectinputstream creates object input stream that reads from specified input stream
			
			outputStream.writeObject(encryptList(sentList));
			outputStream.flush();
			System.out.println("client sent: " + sentList);
			@SuppressWarnings("unchecked")
			ArrayList<Integer> encryptServer = (ArrayList<Integer>) inputStream.readObject();
			encryptServer = decryptList(encryptServer);
			System.out.println("client recieved: " + encryptServer);
			
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			// Close resources in finally block so that they
			// get closed even if we hit an exception above.
			try {
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
		
		System.out.println("client finished");
		
	}
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