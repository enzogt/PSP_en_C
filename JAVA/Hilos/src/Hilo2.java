
public class Hilo2 extends Thread {
	
	public void run () {
		
		Thread.yield();
		System.out.println("this.getName() = " + this.getName());
		
		System.out.println("this.getPriority() = " + this.getPriority());
		this.setPriority(8);
		System.out.println("this.getPriority() = " + this.getPriority());
		
		
		System.out.println("El hilo2 se ha unido");
		
	}

}
