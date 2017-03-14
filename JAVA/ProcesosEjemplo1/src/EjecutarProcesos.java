import java.io.IOException;


public class EjecutarProcesos {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub

		Runtime entorno = Runtime.getRuntime();
		Process p1, p2;
		
		p1 = entorno.exec("java proceso1");
		
		p2 = entorno.exec("java proceso2");
		
		
	}

}
