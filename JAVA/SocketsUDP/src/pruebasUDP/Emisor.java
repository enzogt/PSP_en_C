package pruebasUDP;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.UnknownHostException;

public class Emisor {

	public static void main(String[] args) throws IOException {
		
		final String cadena = "¡Hola mundo!";
		final byte[] bytes = cadena.getBytes();
		final InetAddress direccion = InetAddress.getLocalHost();
		final int puerto = 7777;
		
		
		DatagramPacket dp = new DatagramPacket(bytes, bytes.length, direccion, puerto);
		
		DatagramSocket socket = new DatagramSocket();

		socket.send(dp);
		
		System.out.println("Enviado");
		
	}

}
