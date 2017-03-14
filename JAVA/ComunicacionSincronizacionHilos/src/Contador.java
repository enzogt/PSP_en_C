
public class Contador {

	private int cont;

	public int getCont() {
		return cont;
	}

	public void setCont(int cont) {
		this.cont = cont;
	}

	public Contador(int cont) {
		super();
		this.cont = cont;
	}
	
	synchronized public void incrementar(){
		this.cont++;
	}
	
	synchronized public void decrementar(){
		this.cont--;
	}

}
