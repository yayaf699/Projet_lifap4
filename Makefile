all: bin/main 

clean:
	rm bin/* obj/*

bin/main: obj/main.o obj/Joueur.o obj/Menu.o obj/Partie.o obj/Inventaire.o obj/Objet.o obj/Combat.o obj/Statistiques.o obj/Attaque.o obj/Arme.o obj/IA.o obj/jeuSdl.o obj/Map.o
	g++ obj/* -o bin/main -ljsoncpp -lSDL2 -lSDL2_image -lSDL2_ttf

obj/Map.o: src/Map.h src/Map.cpp src/Joueur.h src/jeuSdl.h
	g++ -ggdb -Wall -o obj/Map.o -c src/Map.cpp

obj/main.o: src/main.cpp src/Partie.h src/Joueur.h src/Menu.h 
	g++ -ggdb -Wall -o obj/main.o -c src/main.cpp

obj/jeuSdl.o: src/jeuSdl.cpp src/jeuSdl.h 
	g++ -ggdb -Wall -o obj/jeuSdl.o -c src/jeuSdl.cpp

obj/IA.o: src/IA.cpp src/IA.h src/Joueur.h src/Inventaire.h src/Arme.h src/Objet.h src/Statistiques.h
	g++ -ggdb -Wall -o obj/IA.o -c src/IA.cpp

obj/Arme.o: src/Arme.cpp src/Arme.h src/Attaque.h
	g++ -ggdb -Wall -o obj/Arme.o -c src/Arme.cpp

obj/Combat.o: src/Combat.cpp src/Combat.h src/Joueur.h src/IA.h
	g++ -ggdb -Wall -o obj/Combat.o -c src/Combat.cpp

obj/Attaque.o: src/Attaque.cpp src/Attaque.h 
	g++ -ggdb -Wall -o obj/Attaque.o -c src/Attaque.cpp

obj/Statistiques.o: src/Statistiques.cpp src/Statistiques.h 
	g++ -ggdb -Wall -o obj/Statistiques.o -c src/Statistiques.cpp

obj/Inventaire.o: src/Inventaire.h src/Inventaire.cpp src/Objet.h
	g++ -ggdb -Wall -o obj/Inventaire.o -c src/Inventaire.cpp

obj/Objet.o: src/Objet.cpp src/Objet.h
	g++ -ggdb -Wall -o obj/Objet.o -c src/Objet.cpp

obj/Joueur.o: src/Joueur.cpp src/Joueur.h src/Inventaire.h src/Arme.h src/Objet.h src/Statistiques.h
	g++ -ggdb -Wall -o obj/Joueur.o -c src/Joueur.cpp

obj/Menu.o: src/Menu.cpp src/Menu.h src/Joueur.h src/jeuSdl.h
	g++ -ggdb -Wall -o obj/Menu.o -c src/Menu.cpp

obj/Partie.o: src/Partie.cpp src/Partie.h
	g++ -ggdb -Wall -o obj/Partie.o -c src/Partie.cpp

