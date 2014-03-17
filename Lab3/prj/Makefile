
KOM=g++

__start__: pomiar
	./pomiar

pomiar: obj obj/PomiarCzasu.o obj/Stackk.o obj/Queue.o obj/main.o 
	$(KOM) -Wall -o pomiar obj/PomiarCzasu.o obj/Stackk.o obj/Queue.o obj/main.o -lrt

obj/PomiarCzasu.o: inc/PomiarCzasu.hh inc/Stackk.hh inc/main.hh src/PomiarCzasu.cpp
	$(KOM) -c -Wall -pedantic -iquote inc -o obj/PomiarCzasu.o src/PomiarCzasu.cpp 

obj/Stackk.o: inc/Stackk.hh inc/main.hh src/Stackk.cpp
	$(KOM) -c -Wall -pedantic -iquote inc -o obj/Stackk.o src/Stackk.cpp 

obj/Queue.o: inc/Queue.hh inc/main.hh src/Queue.cpp
	$(KOM) -c -Wall -pedantic -iquote inc -o obj/Queue.o src/Queue.cpp 

obj/main.o: inc/main.hh src/main.cpp
	$(KOM) -c -Wall -pedantic -iquote inc -o obj/main.o src/main.cpp 

obj:
	mkdir obj

clean:
	rm -f obj/* pomiar

help:
	@echo
	@echo  " Dostarczony plik Makefile pozwala wywolac polecenie make"
	@echo  " w nastepujacy sposob:"
	@echo  
	@echo  "  make        - powoduje kompilacje, konsolidacje i uruchomienie programu,"
	@echo  "  make clean  - powoduj usuniecie produktow komilacji i konsolidacji."
	@echo
