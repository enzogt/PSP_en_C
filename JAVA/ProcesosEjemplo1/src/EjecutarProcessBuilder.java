import java.io.IOException;
import java.util.Map;


public class EjecutarProcessBuilder {

	/**
	 * @param args
	 * @throws IOException 
	**/
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
	
		
		ProcessBuilder pb = new ProcessBuilder(new String[]{"mate-terminal", "-e", "ping 8.8.8.8"});
		
		Map variables_entorno = pb.environment();
		
		System.out.println(variables_entorno);
		
		pb.start();

	}

}
