import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;


public class Emisor {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		final int port = 5555;
		ServerSocket socketServidor = null;
		Socket socketCliente = null;
		DataOutputStream salida;
		DataInputStream entrada;
		
		
		try {
			System.out.println("Esperando conexion");
			socketServidor = new ServerSocket(port);
			socketCliente = socketServidor.accept();
			System.out.println("Servidor >>> Conectado");
		

			
			salida = new DataOutputStream(socketCliente.getOutputStream());
			entrada = new DataInputStream(socketCliente.getInputStream());
			
			
			salida.writeUTF("¿Como va eso cliente?");
			System.out.println("Mensaje enviado");
			
			
			socketCliente.close();
			socketServidor.close();
		
		} catch (IOException e) { 
			System.out.println("Fallo en la conexion");
			e.printStackTrace();
		}
		
	}

}
