import java.net.InetAddress;
import java.net.UnknownHostException;


public class TestURLDownload {

	public static void main(String[] args) {
		

		printInfoHost("www.google.cn");
		printInfoHost("localhost");

	}
	
	private static void printInfoHost (String url_host) {
		
		InetAddress direccionHost = null;
		InetAddress [] direccionesHost = null;
		
		try {
			
			direccionHost = InetAddress.getByName(url_host);
			
			System.out.println(direccionHost.toString());
			
			//---
			
			direccionesHost = InetAddress.getAllByName(url_host);
			
			for (InetAddress inetAddressIteracion : direccionesHost) {
				System.out.println(inetAddressIteracion.toString());
			}
			
			//---
			
			System.out.println("getByName(): " + direccionHost);
			System.out.println("getHostName(): " + direccionHost.getHostName());
			System.out.println("getHostAddress(): " + direccionHost.getHostAddress());
			System.out.println("getCanonicalHostName(): " + direccionHost.getCanonicalHostName());
			
			System.out.println("\n------\n");
		
		} catch (UnknownHostException e) { e.printStackTrace(); }
		
	}

	
	
}