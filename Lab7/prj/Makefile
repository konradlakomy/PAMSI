
KOM=g++

__start__: program
	./program

program: obj obj/list.o obj/hash.o obj/bst.o obj/benchmark.o obj/main.o 
	$(KOM) -Wall -o program obj/list.o obj/hash.o obj/bst.o obj/benchmark.o obj/main.o -lrt 

obj/list.o: inc/list.hh src/list.cpp 
	$(KOM) -c -Wall -pedantic -iquote inc -o obj/list.o src/list.cpp 

obj/hash.o: inc/hash.hh src/hash.cpp
	$(KOM) -c -Wall -pedantic -iquote inc -o obj/hash.o src/hash.cpp 

obj/bst.o: inc/bst.hh src/bst.cpp
	$(KOM) -c -Wall -pedantic -iquote inc -o obj/bst.o src/bst.cpp

obj/benchmark.o: inc/benchmark.hh src/benchmark.cpp
	$(KOM) -c -Wall -pedantic -iquote inc -o obj/benchmark.o src/benchmark.cpp

obj/main.o: inc/main.hh src/main.cpp
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
