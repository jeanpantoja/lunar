all: dependencies
	echo "compiling lunar"
	cd dependencies && $(MAKE)

