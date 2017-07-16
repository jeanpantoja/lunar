all: dependencies
	echo "compiling lunar"
	cd dependencies && $(MAKE)

clean_dependencies:
	cd dependencies && $(MAKE) clean

