# makefile
# Pokemon
# created: 3/15/22
# g++ -std=c++11 -I C:\CPP\SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit\SFML-2.5.1\include -c main.cpp stdInclude.cpp WelcomeState.cpp TrainerName.cpp Moves.cpp Pokemon.cpp firePokemon.cpp grassPokemon.cpp waterPokemon.cpp Pokemonlist.cpp BattleSystem.cpp Function.cpp PokemonMenu.cpp
# g++ -std=c++11 -L C:\CPP\SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit\SFML-2.5.1\lib .\main.o stdInclude.o WelcomeState.o TrainerName.o Moves.o Pokemon.o firePokemon.o grassPokemon.o waterPokemon.o Pokemonlist.o BattleSystem.o Function.o PokemonMenu.o -o main.exe -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system
#	./main.exe

all: compile link	 
	
compile: 
	rm -f main *.o
	g++ -std=c++11 -I C:\CPP\SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit\SFML-2.5.1\include -c main.cpp stdInclude.cpp WelcomeState.cpp TrainerName.cpp PokemonMenu.cpp BattleSystem.cpp Function.cpp BattleBulVsGren.cpp BattleBlaVsGren.cpp BattleChariVsGren.cpp Moves.cpp Result.cpp Pokemon.cpp firePokemon.cpp grassPokemon.cpp waterPokemon.cpp Pokemonlist.cpp
link:
	g++ -std=c++11 -L C:\CPP\SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit\SFML-2.5.1\lib .\main.o stdInclude.o WelcomeState.o TrainerName.o PokemonMenu.o BattleSystem.o Function.o BattleBulVsGren.o BattleBlaVsGren.o BattleChariVsGren.o Moves.o Result.o Pokemon.o firePokemon.o grassPokemon.o waterPokemon.o Pokemonlist.o -o main.exe -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system
	./main.exe
clean:
	rm -f main *.o