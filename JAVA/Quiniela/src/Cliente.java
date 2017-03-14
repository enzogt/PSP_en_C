import java.io.DataInputStream;
import java.io.IOException;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.ArrayList;


public class Cliente {


	public static void main(String[] args) throws UnknownHostException, IOException {
		

		Socket socket = new Socket(Servidor.DIR_SERVIDOR, Servidor.PUERTO);

		DataInputStream dis = new DataInputStream(socket.getInputStream());
		
		ArrayList<Character> combinacion = new ArrayList<Character>();
		
		for (int i = 0; i < 15; i++)
			combinacion.add(dis.readChar());
		
		
		int i = 0;
		for (Character c : combinacion){
			
			System.out.println(((i + 1 < 10) ? " " + (i + 1) : i + 1) + ".- " + c);
			i++;
		}
		
		dis.close();
		socket.close();
	}

}
