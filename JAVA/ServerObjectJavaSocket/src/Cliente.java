import java.io.IOException;
import java.io.ObjectInputStream;
import java.net.Socket;
import java.net.UnknownHostException;


public class Cliente {
	
	static Socket socket;

	public static void main(String[] args) throws UnknownHostException, IOException, ClassNotFoundException {

		socket = new Socket(Servidor.DIR_SERVIDOR, Servidor.PUERTO);
		
		ObjectInputStream ois = new ObjectInputStream(socket.getInputStream());
		
		Persona persona = (Persona) ois.readObject();
	
		
		System.out.println(persona.toString());
		
		ois.close();
		socket.close();
	}

}
