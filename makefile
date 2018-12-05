all: mem.c 
	gcc mem.c

run: 
	./a.out

clean: 
	rm -rf *.out

