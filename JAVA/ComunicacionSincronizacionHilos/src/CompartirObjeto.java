
public class CompartirObjeto {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Contador cont = new Contador(200);
		
		HiloA hiloA = new HiloA("Hilo A: ", cont);
		HiloB hiloB = new HiloB("Hilo B: ", cont);

		hiloA.start();
		hiloB.start();
	}

}
