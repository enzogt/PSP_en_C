# -*- coding: utf-8 -*-
import Tkinter, smtplib
from Tkinter import *

def enviarMail (correo, asunto, mensaje, boton):

  ### Datos de Gmail desde donde se enviará ###
  gmail_user = 'enzogt.dev@gmail.com'
  gmail_pwd = 'enzogt.pass'

  ### Datos del correo ###
  FROM = 'Python <%s>' % (gmail_user)
  TO = correo.get()
  SUBJECT = asunto.get()
  TEXT = mensaje.get("1.0", END)

  ### Comprobacion de campos vacios ###
  if (len(TO) <= 0) or (len(SUBJECT) <= 0) or (len(TEXT) <= 0):
    boton.config(text="Revisa los datos")
    return

  MESSAGE = """From: %s\nTo: %s\nSubject: %s\n\n%s""" % (FROM, TO, SUBJECT, TEXT)

  try:
    server = smtplib.SMTP("smtp.gmail.com", 587)
    server.ehlo()
    server.starttls()
    server.login(gmail_user, gmail_pwd)
    server.sendmail(FROM, TO, MESSAGE)
    server.close()

    asunto.delete(0, 'end')
    mensaje.delete(1.0, END)
    boton.config(text="Correo enviado")
        
  except Exception as e:
    boton.config(text="Error")
    print(e)


################################################################################
########## ##### ### ## #           INICIO            # ##  ### ##### ##########
################################################################################

#Ventanas.
ventanaPrincipal = Tkinter.Tk()
ventanaPrincipal.resizable(width=False, height=False)
ventanaPrincipal.wm_title("Correo")


### Etiquetas ###
Label(ventanaPrincipal, text="Correo", width=10,
).grid(row=0, sticky=N, padx=2, pady=(20, 10))

Label(ventanaPrincipal, text="Asunto", width=10
).grid(row=1, sticky=N, padx=2, pady=10)

Label(ventanaPrincipal, text="Mensaje", width=10
).grid(row=2, sticky=N, padx=2, pady=10)


### Inputs ###
correo = Entry(ventanaPrincipal, width=50)
correo.grid(row=0, column=1, padx=20, pady=(20, 10))
correo.configure(font=("Calibri", 11))
correo.insert(0, "alumnodam1lorenzogiltesa@gmail.com")

asunto = Entry(ventanaPrincipal, width=50)
asunto.grid(row=1, column=1, padx=20, pady=10)
asunto.configure(font=("Calibri", 11))

mensaje = Text(ventanaPrincipal, width=50, height=5)
mensaje.grid(row=2, column=1, padx=20, pady=10)
mensaje.configure(font=("Calibri", 11))


### Boton ###
boton = Button(ventanaPrincipal, text="Enviar", width=20)
boton.grid(row=3, columnspan=2, padx=0, pady=(15, 20))
boton.configure(command = lambda: enviarMail(correo, asunto, mensaje, boton))
  
### Se lanza la ventana ###
ventanaPrincipal.mainloop()