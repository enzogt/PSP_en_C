
public class HiloB extends Thread{

	private Contador contador;
	
	public HiloB(String nombre_hilo, Contador c){
		this.contador = c;
		setName(nombre_hilo);
	}

	public void run() {
		
		for (int i = 0; i < 3000000; i++){
//			try {
//			sleep(100);
//		} catch (InterruptedException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
			
//			synchronized (contador){
				contador.decrementar();
//			}
			
			System.out.println(getName() + contador.getCont());
		}
	}

}
