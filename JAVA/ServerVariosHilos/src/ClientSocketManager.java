import java.io.DataInputStream;
import java.io.IOException;
import java.net.*;
import java.util.*;


public class ClientSocketManager extends Thread {


	Socket socket;
	ArrayList<String> mensajes;
	
	public ClientSocketManager(Socket socket, ArrayList<String> mensajes) {
		super();
		this.socket = socket;
		this.mensajes = mensajes;
	}

	@Override
	public void run() {
		super.run();
		
		System.out.println("Gestionando conexion con: " + socket.getInetAddress().toString());
		
		try {
			DataInputStream dis = new DataInputStream(socket.getInputStream());
			
			String mensaje = socket.getInetAddress().toString() + dis.readUTF();
			
			synchronized (mensaje) {
				mensajes.add(mensaje);
			}
			
			socket.close();
			
		} catch (IOException e) {

			System.out.println("No se pudo cerrar el socket");
		}
	}
	
	

	

}
