public class EjecutarComando{

	public static void main (String[] args){

		Runtime entorno = Runtime.getRuntime();
		
		final String comando = "xed";

		Process p;

		try {

			p = entorno.exec(comando);
			
		} catch (Exception ex){

			System.out.println("Error con el comando: " + comando);
		}
 
	}

}
