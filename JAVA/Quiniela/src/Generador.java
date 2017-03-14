import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.Random;


public class Generador extends Thread {

	Socket s;
	String opciones = "1X2";
	char[] quiniela = new char[15];

	public Generador(Socket s) {
		super();
		this.s = s;
	}



	public void run() {
		
		try {
			
			DataOutputStream dos = new DataOutputStream(s.getOutputStream());
			byte [] opcionByte = opciones.getBytes();
			
			for (int i = 0; i < 15; i++)
				dos.writeChar( opcionByte[new Random().nextInt(opcionByte.length)] );
		
		
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
