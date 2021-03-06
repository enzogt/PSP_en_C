

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.MulticastSocket;
import java.net.SocketException;
import java.net.UnknownHostException;

public class EmisorMulticast {

	public static void main(String[] args) throws IOException {
		
		final String cadena = "¡Hola por la carretera!";
		final byte[] bytes = cadena.getBytes();
		final InetAddress direccion = InetAddress.getByName("224.1.1.1");
		final int puerto = 12346;
		
		
		DatagramPacket dp = new DatagramPacket(bytes, bytes.length, direccion, puerto);
		
		MulticastSocket ms = new MulticastSocket();
		
		ms.send(dp);
		ms.close();
		
		System.out.println("Enviado");
		
	}

}
