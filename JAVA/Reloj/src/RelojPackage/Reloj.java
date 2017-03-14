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

public class Reloj extends Applet implements Runnable, ActionListener {

	private Thread hilo;
	private Font fuente;
	private String hora;
	private SimpleDateFormat sdf;
	private Calendar calendario;
	private Button boton;
	private boolean encendido;
	
	
	public void run() {
		
		Thread hiloActual = Thread.currentThread();
		
		while (hilo == hiloActual) {
			
			if (encendido) {
				actualizarHora();
				repaint();
			}
			
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			
		}
	}
	
	private void actualizarHora () {
		
		calendario = Calendar.getInstance();
		hora = sdf.format(calendario.getTime());
	}

	
	public void init() {
		super.init();
		
		encendido = true;
		fuente = new Font("Verdana", Font.BOLD, 26);
		hilo = null;
		boton = new Button("Parar");
		boton.addActionListener(this);
		this.add(boton);
		
		sdf = new SimpleDateFormat("HH:mm:ss");
		actualizarHora();
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
		ventana.drawString(hora, 35, 100);
	}

	public void actionPerformed(ActionEvent arg0) {
		
		encendido = !encendido;

	}

}
