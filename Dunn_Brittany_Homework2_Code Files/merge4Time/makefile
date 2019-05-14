merge4Time: merge4TimeMain.o merge4.o
	g++ merge4TimeMain.o merge4.o -std=c++0x -o merge4Time

merge4TimeMain.o: merge4TimeMain.cpp
	g++ -std=c++0x -c merge4TimeMain.cpp

merge4.o: merge4.cpp merge4.hpp
	g++ -std=c++0x -c merge4.cpp

clean: 
	rm *.o merge4Time
