
KOM=g++

__start__: program
	./program

program: obj obj/graph.o obj/main.o 
	$(KOM) -Wall -o program obj/graph.o obj/main.o 

obj/graph.o: inc/graph.hh src/graph.cpp 
	$(KOM) -c -Wall -pedantic -iquote inc -o obj/graph.o src/graph.cpp 

obj/main.o: inc/graph.hh src/main.cpp
	$(KOM) -c -Wall -pedantic -iquote inc -o obj/main.o src/main.cpp 

obj:
	mkdir obj

clean:
	rm -f obj/* program

help:
	@echo
	@echo  " Dostarczony plik Makefile pozwala wywolac polecenie make"
	@echo  " w nastepujacy sposob:"
	@echo  
	@echo  "  make        - powoduje kompilacje, konsolidacje i uruchomienie programu,"
	@echo  "  make clean  - powoduj usuniecie produktow komilacji i konsolidacji."
	@echo
