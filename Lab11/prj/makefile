
KOM=g++

__start__: program
	./program

program: obj obj/integral.o obj/main.o 
	$(KOM) -Wall -o program obj/integral.o obj/main.o

obj/integral.o: inc/integral.hh src/integral.cpp 
	$(KOM) -c -Wall -pedantic -iquote inc -o obj/integral.o src/integral.cpp 

obj/main.o: inc/integral.hh src/main.cpp
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
