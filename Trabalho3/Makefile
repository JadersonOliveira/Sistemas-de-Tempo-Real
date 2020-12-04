
all:
	g++ -std=c++11 -c trabalho3_4.cpp -I/home/joanderson/sfml/include -lpthread
	g++ -std=c++11 trabalho3_4.o -o sfml-app_2 -L/home/joanderson/sfml/lib -lpthread -lsfml-graphics -lsfml-window -lsfml-system  -lsfml-audio
	export LD_LIBRARY_PATH=/home/joanderson/sfml/lib && ./sfml-app_2
run:
	echo "Makefile Executado!!"

clean:
	rm ./trabalho3_4.o
	rm ./sfml-app_2
