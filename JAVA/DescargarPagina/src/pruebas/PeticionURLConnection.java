package pruebas;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.*;
import java.util.regex.Pattern;

public class PeticionURLConnection {

	public static void main(String[] args) throws IOException {
		
		URL url = new URL("http://www.meteoclimatic.net/perfil/ESARA2200000022194A");
		URLConnection urlConnection = url.openConnection();

		BufferedReader br;
		InputStream is = urlConnection.getInputStream();
		
		br = new BufferedReader(new InputStreamReader(is));
		
		
		String [] cadenas = new String [] {"Temperatura", "Humedad", "Viento", "Presión", "Precip.", "Episodio precipitación"};
		String inputLine;
		int resultados = 0;
				
		while ((inputLine = br.readLine()) != null){
			
			if (inputLine.indexOf("dadesactuals") > 0) {
								
				inputLine = inputLine.substring(inputLine.indexOf('>') + 1, inputLine.length());
				inputLine = inputLine.substring(0, inputLine.indexOf('<'));
				
				inputLine = inputLine.replace("&nbsp;", " ");
				inputLine = inputLine.replace("�", "º");
				
				
				System.out.print("- " + cadenas[resultados++] + ": ");
				System.out.println(inputLine);
			}
			
		}
		
		br.close();
	}
}
