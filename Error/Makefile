CC=gcc
CPP=g++
IDIR=include
ODIR=obj
LDIR=lib
SDIR=src
CFLAGS=$(patsubst %, -I%, $(IDIR)) -std=c++17
LIBNAME=libgoerror

.PHONY: $(ERROR_UNINSTALL_HEADERS) clean

ERROR_SOURCES=$(wildcard $(SDIR)/*.cpp)
ERROR_OBJECTS=$(patsubst $(SDIR)/%.cpp, $(ODIR)/%.o, $(ERROR_SOURCES))

ERROR_DLIB_SOURCES = $(ERROR_SOURCES)

ERROR_DEPS = $(patsubst %, %/*, $(IDIR)) 

ERROR_HEADERS = $(wildcard $(IDIR)/*)

ERROR_UNINSTALL_HEADERS  = $(patsubst $(IDIR)/%, %, $(ERROR_HEADERS)) 

$(ERROR_UNINSTALL_HEADERS):
	rm -rf /usr/local/include/$@

build: build-dir $(ERROR_OBJECTS) build-lib

build-dir:
	mkdir -p $(ODIR)
	mkdir -p $(LDIR)

$(ERROR_OBJECTS): $(ODIR)/%.o : $(SDIR)/%.cpp $(ERROR_DEPS)
	$(CPP) -c $< -o $@ $(CFLAGS)


build-lib: $(ERROR_DLIB_SOURCES) $(ERROR_DEPS)
	ar -crs $(LDIR)/$(LIBNAME).a $(ERROR_OBJECTS)
	$(CPP) -shared -fPIC -o $(LDIR)/$(LIBNAME).so $(ERROR_DLIB_SOURCES) $(CFLAGS)
	
install:
	rm -f /usr/local/lib/$(LIBNAME).so
	cp $(LDIR)/$(LIBNAME).so /usr/local/lib
	cp include/* /usr/local/include

uninstall: $(ERROR_UNINSTALL_HEADERS)


install-docker:
	rm -f /usr/local/lib/$(LIBNAME).so
	cp $(LDIR)/$(LIBNAME).so /usr/local/lib
	cp include/* /usr/include

clean:
	rm -rf $(ODIR)
	rm -rf $(LDIR)