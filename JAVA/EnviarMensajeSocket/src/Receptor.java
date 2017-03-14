import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;


public class Receptor {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		final int puerto = 5555;
		final String direccion = "localhost";
		Socket socket = null;
		DataOutputStream salida;
		DataInputStream entrada;
		
		try {
			socket = new Socket(direccion, puerto);
			System.out.println("Cliente >>> Conectado");
		
			salida = new DataOutputStream(socket.getOutputStream());
			entrada = new DataInputStream(socket.getInputStream());
			
			System.out.println("Mensaje recibido" + entrada.readUTF());
			
			socket.close();
		
		} catch (IOException e) { e.printStackTrace(); }

	}

}
