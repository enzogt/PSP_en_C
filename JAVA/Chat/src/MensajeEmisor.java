import java.io.DataOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.util.Scanner;


public class MensajeEmisor extends Thread{

	DataOutputStream salida;
	Scanner scanner;

	public MensajeEmisor(OutputStream salida_socket) {
		super();
		this.salida = new DataOutputStream(salida_socket);
		this.scanner = new Scanner(System.in);;
	}

	public void run() {
		super.run();
		String cadena;
		
		while (true) {
			
			try {
				cadena = scanner.nextLine();
				salida.writeUTF(cadena);
				salida.flush();
				
			} catch (IOException e) { e.printStackTrace(); }
		}
	}
	
	

}
