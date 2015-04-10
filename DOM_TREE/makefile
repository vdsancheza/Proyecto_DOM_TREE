#	Victor Sanchez y Jesus Aguilar
#	Licenciatura en Ciencias de la Computacion.
#	Facultad Experimental de Ciencias Y Tecnologia.
#	Universidad de Carabobo.
#	4er Semestre.
#	Programacion II.
#	Profesora: Kiara Ottogalli.
#	CI: 22518142.

#VARIABLES

COMPILADOR = g++
WALLE = -Wall
PRINCIPAL = main.cpp
ARCHIVOS_CABECERA = node.hpp element.hpp DOM_tree.hpp
	
#CREACION DEL ARCHIVO EJECUTABLE
exe : $(PRINCIPAL) $(ARCHIVOS_CABECERA)
	$(COMPILADOR) $(WALLE) $(PRINCIPAL) $(ARCHIVOS_CABECERA) -o $@

#LISTA DE ARCHIVOS CABECERA
element.o : element.hpp
	$(COMPILADOR) -c $<
	
node.o : node.hpp
	$(COMPILADOR) -c $<
	
DOM_tree.o : DOM_tree.hpp
	$(COMPILADOR) -c $<

#ELIMINACION DE ARCHIVOS TEMPORALES
clean:
	rm *.o *~
