
public class Productor extends Thread{

	Almacen almacen;
	int unidades_producidas;

	public Productor(Almacen almacen, String nombre_productor, int unidades) {
		this.almacen = almacen;
		this.unidades_producidas = unidades;
		setName(nombre_productor);
	}

	public void run() {
		
		int introducido = 0;
		
		while (introducido != unidades_producidas) {
			almacen.introducir(1);
			introducido++;
			
			try {
				sleep(100);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}	
			
			System.out.println(getName() + "introduce 1 unidades. Stock = " + almacen.stock());
		}
	}
}
