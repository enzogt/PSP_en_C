import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.net.UnknownHostException;


public class Cliente {


	public static void main(String[] args) throws UnknownHostException, IOException {
		

		Socket s = new Socket("localhost", 4545);
		
		new DataOutputStream(s.getOutputStream()).writeLong(7l);
		
		s.close();
		
	}

}