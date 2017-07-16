PROGRAM=lunar
SRC=src/main.cpp
INCLUDE+= -Idependencies/jsoncpp/include
INCLUDE+= -Idependencies/jsonrpc-cpp/include/
COMPILER=g++
CPPFLAGS= -O2
LDFLAGS=
LIBS= -ljsonrpc-cpp -ljsoncpp
PATHLIB= -Ldependencies

all:
	echo "compiling lunar"
	cd dependencies && $(MAKE)
	#
	$(COMPILER) $(CPPFLAGS) $(INCLUDE) $(SRC) $(LDFLAGS) $(PATHLIB) $(LIBS) -o $(PROGRAM)

clean_dependencies:
	cd dependencies && $(MAKE) clean

install:
	cp -fv lunar /usr/local/bin

uninstall:
	rm -fv /usr/local/bin/lunar
