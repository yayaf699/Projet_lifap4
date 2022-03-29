all: bin/main

clean:
	rm bin/* obj/*

bin/main: obj/main.o obj/Joueur.o obj/Partie.o obj/Inventaire.o obj/Objet.o obj/Combat.o obj/Statistiques.o obj/Attaque.o 
	g++ obj/* -o bin/main

obj/main.o: src/main.cpp src/Partie.h src/Joueur.h 
	g++ -ggdb -Wall -o obj/main.o -c src/main.cpp

obj/Combat.o: src/Combat.cpp src/Combat.h src/Joueur.h
	g++ -ggdb -Wall -o obj/Combat.o -c src/Combat.cpp

obj/Attaque.o: src/Attaque.cpp src/Attaque.h 
	g++ -ggdb -Wall -o obj/Attaque.o -c src/Attaque.cpp

obj/Statistiques.o: src/Statistiques.cpp src/Statistiques.h 
	g++ -ggdb -Wall -o obj/Statistiques.o -c src/Statistiques.cpp

obj/Inventaire.o: src/Inventaire.h src/Inventaire.cpp src/Objet.h
	g++ -ggdb -Wall -o obj/Inventaire.o -c src/Inventaire.cpp

obj/Objet.o: src/Objet.cpp src/Objet.h
	g++ -ggdb -Wall -o obj/Objet.o -c src/Objet.cpp

obj/Joueur.o: src/Joueur.cpp src/Joueur.h src/Inventaire.h src/Arme.h
	g++ -ggdb -Wall -o obj/Joueur.o -c src/Joueur.cpp

obj/Partie.o: src/Partie.cpp src/Partie.h
	g++ -ggdb -Wall -o obj/Partie.o -c src/Partie.cpp

