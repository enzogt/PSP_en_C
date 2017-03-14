import java.io.IOException;
import java.net.SocketException;

import org.apache.commons.net.ftp.FTPClient;
import org.apache.commons.net.ftp.FTPFile;
import org.apache.commons.net.ftp.FTPReply;

public class ClienteFTP {

	
	public static void main(String[] args) throws SocketException, IOException {
		// TODO Auto-generated method stub
		
		FTPClient cliente = new FTPClient();
		String servidor = "ftp.udl.es";
		cliente.connect(servidor);
		cliente.login("anonymous", "anonymous");
		
		System.out.println(cliente.getReplyString());
		
		
		//int codigo_respuesta = cliente.getReply();
		
		//Respuesta falsa (fallo, rechazo...).
		//if (!FTPReply.isPositiveCompletion(codigo_respuesta)){
		//	
		//	cliente.disconnect();
		//	System.out.println("Conexión rechazada: " + codigo_respuesta);
		//	System.exit(0);
		//}
		
		
		System.out.println("Directorio actual: " + cliente.printWorkingDirectory());
		
		FTPFile[] ficheros = cliente.listFiles();
		
		for (FTPFile fichero : ficheros){
			
			System.out.println(fichero.getName());
			cliente.changeWorkingDirectory(fichero.getName());
			
			FTPFile[] ficheros2 = cliente.listFiles();
			
			for (FTPFile fichero2 : ficheros2){
				
				System.out.println(fichero2.getName());
			}
		}
		
		
		cliente.disconnect();
		System.out.println("Desconectado");

	}

}
