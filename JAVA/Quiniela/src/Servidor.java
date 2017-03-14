import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;


public class Servidor {

	public static final String DIR_SERVIDOR = "localhost";
	public static final int PUERTO = 7777;
	private static ServerSocket socketServidor;
	private static boolean finalizado = false;
	
	
	public static void main(String[] args) throws IOException {

		socketServidor = new ServerSocket(PUERTO);
		
		while (!finalizado){
			
			Socket s = socketServidor.accept();
			
			Generador gen = new Generador(s);
			gen.start();
		}
		
		socketServidor.close();
		
	}
	
	public static void finalizar () {
		
		System.out.println("Llamado");
		finalizado = true;
	}

}
