CFLAGS=-std=c11 -Wall -Wextra -pedantic -g -O2
GERAR=gerar

install: $(GERAR)
	sudo chmod 777 -R /var/www/html

$(GERAR): ../puzzles.o ../verifica.o ../estado.o ../helps.o ../mapas.o ../undos.o 
	cc -o $(GERAR) ../puzzles.o ../verifica.o ../estado.o ../helps.o ../mapas.o ../undos.o
