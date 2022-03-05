.SUFFIXES: .c .cpp .o .x .h
DIR = `basename $(CURDIR)`


.PHONY: run

run:
	 
	g++ -std=c++11 -Wall -o main main.cpp
	./main


.PHONY: clean tar

clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out; rm -rf ${LIB_DIR}, main

tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )


.SILENT: