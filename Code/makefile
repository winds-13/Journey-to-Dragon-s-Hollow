F: Main.o Random.o Hero.o Journey.o Player.o Fighter.o Dragon.o Angel.o
	g++ -o F Main.o Random.o Journey.o Hero.o Player.o Fighter.o Dragon.o Angel.o

Main.o: Main.cc Journey.h
	g++ -c Main.cc

Random.o: Random.cc
	g++ -c Random.cc

Hero.o: Hero.cc
	g++ -c Hero.cc

Journey.o: Journey.cc Path.h
	g++ -c Journey.cc

Player.o: Player.cc
	g++ -c Player.cc

Fighter.o: Fighter.cc
	g++ -c Fighter.cc

Dragon.o: Dragon.cc
	g++ -c Dragon.cc

Angel.o: Angel.cc
	g++ -c Angel.cc

clean:
	rm -f *.o F