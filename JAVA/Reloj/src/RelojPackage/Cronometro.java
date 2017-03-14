package RelojPackage;

import java.applet.Applet;
import java.awt.Button;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.SimpleDateFormat;
import java.util.Calendar;

public class Cronometro extends Applet implements Runnable, ActionListener {

	private Thread hilo;
	private Font fuente;
	
	private int decimas, segundos, minutos;
	
	private SimpleDateFormat sdf;
	private Calendar calendario;
	private Button boton;
	private boolean encendido;
	
	
	public void run() {
		
		Thread hiloActual = Thread.currentThread();
		
		while (hilo == hiloActual) {
			
			actualizarCronometro();
				
			if (encendido) {
				repaint();
			}
			
			try {
				Thread.sleep(100);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			
		}
	}
	
	private void actualizarCronometro () {
		
		decimas += 1;
		
		if (decimas == 10){
			decimas = 0;
			segundos++;
		}
		
		if (segundos == 60) {
			segundos = 0;
			minutos++;
		}
		
	}

	
	public void init() {
		super.init();
		
		encendido = true;
		fuente = new Font("Verdana", Font.BOLD, 26);
		hilo = null;
		boton = new Button("Parar");
		boton.addActionListener(this);
		this.add(boton);
		
		decimas = 0;
		segundos = 0;
		minutos = 0;
		
		actualizarCronometro();
	}


	public void start() {
		super.start();
		
		if (hilo == null) {
			
			hilo = new Thread(this);
			hilo.start();
		}
	}


	public void stop() {
		super.stop();
	}


	public void paint(Graphics ventana) {
		super.paint(ventana);
		ventana.clearRect(0, 0, getSize().width, getSize().height);
		setBackground(Color.decode("#F1F1F1"));
		ventana.setFont(fuente);
		
		ventana.drawString((minutos < 10 ? "0" : "") + String.valueOf(minutos) + ":" + (segundos < 10 ? "0" : "") + String.valueOf(segundos) + ":" + String.valueOf(decimas) + "0", 35, 100);
	}

	public void actionPerformed(ActionEvent arg0) {
		
		encendido = !encendido;

	}

}
