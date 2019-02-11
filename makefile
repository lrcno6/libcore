liblibcore.a:book.o library.o
	ar cr liblibcore.a book.o library.o
book.o:book.cpp book.h
	g++ -c book.cpp
library.o:library.cpp library.h function.h book.h
	g++ -c library.cpp
debug:book.cpp library.cpp book.h library.h function.h
	g++ -c book.cpp -g
	g++ -c library.cpp -g
	ar cr liblibcore.a book.o library.o
clean:
	rm liblibcore.a book.o library.o
windows:
	cl /c book.cpp library.cpp /EHsc
	lib book.obj library.obj /out:libcore.lib