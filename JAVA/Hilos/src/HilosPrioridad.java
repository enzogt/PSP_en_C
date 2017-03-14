
public class HilosPrioridad {


	HiloPrioridad h1, h2, h3, h4, h5, h6;
	
	public void main(String[] args) throws InterruptedException {
		

		h1 = new HiloPrioridad();
		h2 = new HiloPrioridad();
		h3 = new HiloPrioridad();
		h4 = new HiloPrioridad();
		h5 = new HiloPrioridad();
		h6 = new HiloPrioridad();
		
		h1.setPriority(Thread.MIN_PRIORITY);
		h2.setPriority(1);
		h3.setPriority(2);
		h4.setPriority(3);
		h5.setPriority(4);
		h6.setPriority(Thread.MAX_PRIORITY);
		
		
		h1.start();
		h2.start();
		h3.start();
		h4.start();
		h5.start();
		h6.start();
		
		
		Thread.sleep(1000);
		
		h1.pararHilo();
		h2.pararHilo();
		h3.pararHilo();
		h4.pararHilo();
		h5.pararHilo();
		h6.pararHilo();
		
		System.out.println("h1: " + h1.getContador());
		System.out.println("h2: " + h2.getContador());
		System.out.println("h3: " + h3.getContador());
		System.out.println("h4: " + h4.getContador());
		System.out.println("h5: " + h5.getContador());
		System.out.println("h6: " + h6.getContador());
		

	}

}
