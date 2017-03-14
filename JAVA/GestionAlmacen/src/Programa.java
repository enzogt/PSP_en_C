
public class Programa {

	public static void main(String[] args) {
		
		Almacen almacen = new Almacen(3);
		Productor productor = new Productor(almacen, "Productor 1: ", 50);
		Consumidor consumidor = new Consumidor(almacen, "Consumido 1: ", 55);
		productor.start();
		consumidor.start();
	}

}
