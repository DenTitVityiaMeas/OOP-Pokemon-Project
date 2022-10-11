# makefile
# Pokemon
# created: 11/10/2022

all: compile link
    
compile: 
	 g++ -c main.cpp -o main.o -I "C:\\CPP\\SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit\\SFML-2.5.1\\include" -DSFML_STATIC    

link:
	g++ main.o -o main.exe -L "C:\CPP\SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit\SFML-2.5.1\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-audio-s -lsfml-network-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows -lsfml-main
	./main.exe

clean:
	rm -f main *.o