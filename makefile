liblibcore.a:book.o library.o
	ar cr liblibcore.a book.o library.o
book.o:book.cpp book.h
	g++ -c book.cpp
library.o:library.cpp library.h function.h book.h
	g++ -c library.cpp
clean:
	rm liblibcore.a book.o library.o