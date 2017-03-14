
public class AbrirComando {
	
	public static void main (String[] args){
		
		
		Runtime entorno = Runtime.getRuntime();
		
		if (args.length != 1){
			
			System.out.println("Error!, número de argumentos incorrecto.");
			
		} else {
			
			Process p;
			
			try {
				
				p = entorno.exec(args[0]);
				
				
			} catch (Exception ex) {
				
				System.err.println("Fallo: " + ex.getMessage());
				
				
				
			}
			
			
		}
		
		
		
	}

}
