all: bin/main

clean:
	rm bin/* obj/*

bin/main: obj/main.o obj/Joueur.o obj/Partie.o
	g++ obj/main.o obj/Joueur.o obj/Partie.o -o bin/main

obj/main.o: src/main.cpp src/Partie.h src/Joueur.h 
	g++ -ggdb -Wall -o obj/main.o -c src/main.cpp

obj/Joueur.o: src/Joueur.cpp src/Joueur.h
	g++ -ggdb -Wall -o obj/Joueur.o -c src/Joueur.cpp

obj/Partie.o: src/Partie.cpp src/Partie.h
	g++ -ggdb -Wall -o obj/Partie.o -c src/Partie.cpp

