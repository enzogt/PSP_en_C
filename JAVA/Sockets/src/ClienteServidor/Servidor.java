package ClienteServidor;

import java.io.IOException;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;

public class Servidor {

	public static void main(String[] args) {

		final int port = 5555;
		ServerSocket serverSocket = null;
		Socket clienteSocket = null;
		InetAddress clienteAddress, myAddress;
		
				
		try {
			System.out.println("Esperando al cliente");
			serverSocket = new ServerSocket(port);
			clienteSocket = serverSocket.accept();
			
			System.out.println("Conectado");
			
			clienteAddress = serverSocket.getInetAddress();
			myAddress = clienteSocket.getLocalAddress();
			
			System.out.println("Conectado con: " + clienteAddress.toString());
			System.out.println("Por el puerto:" + clienteSocket.getPort());
			System.out.println("Mi informacion IP es: " + myAddress.toString());
			System.out.println("Puerto local: " + clienteSocket.getLocalPort());
			
			clienteSocket.close();
			serverSocket.close();
			
			
		} catch (IOException e) { e.printStackTrace(); }

	}

}
