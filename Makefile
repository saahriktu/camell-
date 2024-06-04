ifeq ($(prefix),)
	prefix=/usr
endif
ifeq ($(shell which $(CXX)),)
	CXX=g++
endif
ifeq ($(libdir),)
	libdir=$(prefix)/lib
endif
all:
	$(CXX) -c -fPIC $(CXXFLAGS) -o camell++.o camell++.cpp
	$(CXX) -fPIC -shared $(CXXFLAGS) -o libcamell++.so.1 camell++.o -lX11
	ln -s libcamell++.so.1 libcamell++.so
install:
	install -pDm644 libcamell++.so $(DESTDIR)$(libdir)/libcamell++.so
	install -pDm644 libcamell++.so.1 $(DESTDIR)$(libdir)/libcamell++.so.1
	install -pDm644 camell++.hpp $(DESTDIR)$(prefix)/include/camell++/camell++.hpp
clean:
	rm camell++.o libcamell++.so libcamell++.so.1
