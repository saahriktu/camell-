ifeq ($(prefix),)
	prefix=/usr/local
endif
ifeq ($(shell which $(CXX)),)
	CXX=g++
endif
ifeq ($(libdir),)
	libdir=$(prefix)/lib
endif
all:
	$(CXX) -c -fPIC $(CXXFLAGS) -o camell++.o camell++.cpp
	$(CXX) -fPIC -shared $(CXXFLAGS) -o libcamell++.so camell++.o -lX11
install:
	if [ ! -d "$(DESTDIR)$(libdir)" ]; then mkdir -p $(DESTDIR)$(libdir); fi
	if [ ! -d "$(DESTDIR)$(prefix)/include/camell++" ]; then mkdir -p $(DESTDIR)$(prefix)/include/camell++; fi
	install -m755 libcamell++.so $(DESTDIR)$(libdir)
	install -m644 camell++.hpp $(DESTDIR)$(prefix)/include/camell++
clean:
	rm camell++.o libcamell++.so
