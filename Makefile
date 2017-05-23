all:
	g++ -c -fPIC -o camell++.o camell++.cpp
	g++ -fPIC -shared -o libcamell++.so camell++.o
install:
	cp libcamell++.so /usr/lib/
	mkdir /usr/include/camell++
	cp camell++.hpp /usr/include/camell++
clean:
	rm camell++.o libcamell++.so
