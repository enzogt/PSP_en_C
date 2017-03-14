
public class Almacen {

	private int numero_elementos;
	

	public boolean isDisponible() {
		return numero_elementos > 0;
	}

	public boolean isDisponible(int unidades) {
		return unidades <= numero_elementos;
	}
	
	public Almacen(int numero_elementos) {
		super();
		this.numero_elementos = numero_elementos;
	}
	
	synchronized public void introducir (int unidades){
		if (unidades > 0){
			numero_elementos += unidades;
			notify();
		}
	}
	
	synchronized public void extraer (int unidades){
		if (isDisponible(unidades)){
			numero_elementos -= unidades;
		}else{
			System.out.println("No se dispone de " + unidades + " unidades, solo quedan " + numero_elementos);
			try { 
				System.out.println("Esperando reabastecimiento.");
				wait(); 
				
			} catch (InterruptedException e) { e.printStackTrace(); }
		}
	}
	
	public int stock(){
		return numero_elementos;
	}
}
