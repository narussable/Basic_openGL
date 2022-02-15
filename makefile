Com = c++
GL = -lglut -lGL -lGLU

Vechpp:
	$(Com) VectorND.hpp

com:
	vim VectorND.hpp
	make

gogo:
	$(Com) geomGL.hpp

hpp:
	vim geomGL.hpp
	make gogo

prueba:
	$(Com) VectorND.hpp
	$(Com) gohan.cpp VectorND.cpp
	./a.out
