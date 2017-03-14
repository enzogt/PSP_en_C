import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;


public class Omnipotente {

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		final int puerto = 5555;
		final String direccion = "localhost";
		
		MensajeEmisor mensajeEmisor;
		MensajeReceptor mensajeReceptor;
		
		//ServerSocket socketServidor = null;
		Socket socket = null;
		DataOutputStream salida;
		DataInputStream entrada;
			
		try {
			
			try {
				socket = new Socket(direccion, puerto);
				System.out.println("Conectado");
			} catch (IOException e) { socket = null; }
			
			
			if (socket == null) {
				//socketServidor = new ServerSocket(puerto);
				//socket = socketServidor.accept();
				socket = new ServerSocket(puerto).accept();
				System.out.println("Conectado");
			}
			
			mensajeEmisor = new MensajeEmisor(socket.getOutputStream());
			mensajeReceptor = new MensajeReceptor(socket.getInputStream());
			
			System.out.print("### Listo para chatear ###");
			
			mensajeEmisor.start();
			mensajeReceptor.start();
			
			socket.close();
		
		} catch (IOException e) { e.printStackTrace(); }

	}

}
