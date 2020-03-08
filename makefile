BANDERAS = -g -lm --std=c11
SALIDA = enlazada

all:
	gcc $(BANDERAS) enlazada.c  -o $(SALIDA)
	
run:
	./$(SALIDA)
	
.PHONY clean:
	rm *.o $(SALIDA)
