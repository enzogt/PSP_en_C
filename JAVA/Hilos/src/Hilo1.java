
public class Hilo1 extends Thread {
	
	
	public void run (){
		
		System.out.println("Hola desde el primer hilo.");
		try {
			Thread.sleep(2000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.println("El hilo 1 se va.");
	}

}
