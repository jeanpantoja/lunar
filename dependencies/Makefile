CURRENT_DIR=$(shell pwd)
JSONCPP_INC_DIR=$(CURRENT_DIR)/jsoncpp/include

all: libjsoncpp.so libjsonrpc-cpp.so

libjsoncpp.so:
	cd jsoncpp && \
	mkdir -p build && \
	cd build && \
	cmake -DCMAKE_BUILD_TYPE=release \
		-DBUILD_STATIC_LIBS=OFF \
	   	-DBUILD_SHARED_LIBS=ON \
		-DCMAKE_VERBOSE_MAKEFILE=true \
		-G "Unix Makefiles" ../ && \
	$(MAKE) && \
	ln -s $(CURRENT_DIR)/jsoncpp/build/src/lib_json/libjsoncpp.so $(CURRENT_DIR)

libjsonrpc-cpp.so:
# jsonrpc-cpp
	echo "compiling jsonrpc-cpp"
	cd jsonrpc-cpp && \
	./autogen.sh && \
	./configure \
		--with-jsoncpp-inc-dir=$(JSONCPP_INC_DIR) \
		LDFLAGS=" -L../" && \
	$(MAKE) && \
	ln -s $(CURRENT_DIR)/jsonrpc-cpp/src/.libs/libjsonrpc-cpp.so $(CURRENT_DIR)

clean:
	rm -f libjsoncpp.so libjsonrpc-cpp.so
