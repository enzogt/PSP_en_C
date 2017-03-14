
public class Consumidor extends Thread{
	
	Almacen almacen;
	int unidades_necesarias;

	public Consumidor(Almacen almacen, String nombre_consumidor, int unidades) {
		this.almacen = almacen;
		this.unidades_necesarias = unidades;
		setName(nombre_consumidor);
	}

	public void run() {
		
		int extraido = 0;
		
		while (extraido != unidades_necesarias) {
			almacen.extraer(1);
			extraido++;
			
			try {
				sleep(20);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			System.out.println(getName() + "extrae 1 unidades. Stock = " + almacen.stock());
		}
	}

}
