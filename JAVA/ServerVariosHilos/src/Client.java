import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.net.UnknownHostException;
import java.time.ZoneId;
import java.time.ZonedDateTime;
import java.util.TimeZone;


public class Client {

	private static Socket socket;
	private static final int puerto = 5555;
	private static String server = "192.168.137.10"; //192.168.137.1.

	
	public static void main(String[] args) {
		
		DataOutputStream dos;
		ZonedDateTime zdt = ZonedDateTime.now(ZoneId.of("Europe/Madrid"));
		
		
		try {
			
			socket = new Socket(server, puerto);
			
			
		} catch (UnknownHostException e) {
			System.err.println("El servidor no se encuentra.");
		} catch (IOException e) {
			System.err.println("Error de I/O");
		}
		
		try {
			
			dos = new DataOutputStream(socket.getOutputStream());
			dos.writeUTF("Conectado a las: " + zdt.toString());
			
		} catch (IOException e) {

			e.printStackTrace();
		}
		

	}

}
