package ClienteServidor;

import java.io.IOException;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;

public class Cliente {

	public static void main(String[] args) {
		

		final String server = "192.168.137.173";
		final int port = 5555;
		Socket socket;
		InetAddress clienteAddress, serverAddress;
		
		
		
		try {
			socket = new Socket(server, port);
			
			clienteAddress = socket.getLocalAddress();
			serverAddress = socket.getInetAddress();
			
			
			System.out.println("Conectado con: " + clienteAddress.toString());
			System.out.println("Por el puerto:" + socket.getLocalPort());
			System.out.println("Mi informacion IP es: " + serverAddress.toString());
			System.out.println("Puerto server: " + socket.getPort());
			
			socket.close();
			
		} catch (UnknownHostException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		

	}

}
