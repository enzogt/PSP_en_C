import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;


public class MensajeReceptor extends Thread{

	DataInputStream entrada;

	public MensajeReceptor(InputStream entrada_socket) {
		super();
		this.entrada = new DataInputStream(entrada_socket);
	}

	public void run() {
		super.run();
		String leido;
		
		while (true) {
			
			try {
				
				try { sleep(1000); } catch (InterruptedException e) { e.printStackTrace(); }
				
				try {
					
					System.out.println(entrada.readUTF());
					
				} catch (Exception ex) {}
				
				
				
				//if (leido != null) System.out.println(leido);
				
			} catch (Exception e) { e.printStackTrace(); }
			
		}
	
	}


}
