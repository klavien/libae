
all:ae_test

ae_test:main.o
	gcc -o $@ -I../ $< -L../lib -lae

.c.o:
	gcc -c -I../ $< -o $@

.PHONY: clean

clean:
	rm *.o ae_test