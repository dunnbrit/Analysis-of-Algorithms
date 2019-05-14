merge4: merge4Main.o merge4.o
	g++ merge4Main.o merge4.o -std=c++0x -o merge4

merge4Main.o: merge4Main.cpp
	g++ -std=c++0x -c merge4Main.cpp

merge4.o: merge4.cpp merge4.hpp
	g++ -std=c++0x -c merge4.cpp

clean: 
	rm *.o merge4
