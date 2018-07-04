CFLAGS=-std=c11 -Wall -Wextra -pedantic -g -O2
FICHEIROS=cgi.h estado.c estado.h exemplo.c Makefile tabuleiro.c verifica.c verifica.h mapas.c mapas.h tabuleiro.h helps.c helps.h undos.c undos.h new.c new.h puzzles.c
EXECUTAVEL=GandaGalo
GERAR=gerar

install: $(EXECUTAVEL)
	sudo cp $(EXECUTAVEL) /usr/lib/cgi-bin
	sudo chmod 777 -R /var/www/html
	touch install

$(EXECUTAVEL): exemplo.o estado.o tabuleiro.o verifica.o mapas.o helps.o undos.o new.o 
	cc -o $(EXECUTAVEL) exemplo.o estado.o tabuleiro.o verifica.o mapas.o helps.o undos.o new.o 

txt:	
	sudo cp files/*.txt /var/www/html

imagens:
	sudo mkdir -p /var/www/html/images
	sudo cp Imagens/*.png /var/www/html/images

GandaGalo.zip: $(FICHEIROS)
	zip -9 GandaGalo.zip $(FICHEIROS)

doc:
	doxygen -g
	doxygen

clean:
	rm -rf *.o $(EXECUTAVEL) Doxyfile latex html install

estado.o: estado.c estado.h
exemplo.o: exemplo.c cgi.h estado.h mapas.h
tabuleiro.o: tabuleiro.c tabuleiro.h verifica.h
verifica.o: verifica.c verifica.h estado.h
mapas.o: mapas.c estado.h
