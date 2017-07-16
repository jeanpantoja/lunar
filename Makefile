PROGRAM=lunar
INCLUDE+= -Isrc/
INCLUDE+= -Idependencies/jsoncpp/include
INCLUDE+= -Idependencies/jsonrpc-cpp/include/
SRC+= $(shell find src/ -name "*.cpp" )
COMPILER=g++
CPPFLAGS= -O2 -std=c++11
LDFLAGS=
LIBS= -ljsonrpc-cpp -ljsoncpp -lpthread
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
