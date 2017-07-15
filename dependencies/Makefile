all:
	echo "compiling jsoncpp"
	cd jsoncpp && \
	mkdir -p build && \
	cd build && \
	cmake -DCMAKE_BUILD_TYPE=release \
		-DBUILD_STATIC_LIBS=OFF \
	   	-DBUILD_SHARED_LIBS=ON \
		-DCMAKE_ARCHIVE_INSTALL_DIR=. \
		-DCMAKE_VERBOSE_MAKEFILE=true \
		-DCMAKE_INSTALL_INCLUDEDIR=include/jsoncpp \
		-G "Unix Makefiles" \
		../ && $(MAKE)

