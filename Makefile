all:libae.a 

libae.a: ae.o
	ar -rs $@ $<
	mkdir -p lib/
	mv $@ lib/

.PHONY:clean

clean:
	rm -rf *.o lib/