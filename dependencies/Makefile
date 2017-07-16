CURRENT_DIR=$(shell pwd)
JSONCPP_INC_DIR=$(CURRENT_DIR)/jsoncpp/include

all: libjsoncpp.a libjsonrpc-cpp.a

libjsoncpp.a:
	cd jsoncpp && \
	rm -rfv build && \
	mkdir -p build && \
	cd build && \
	cmake -DCMAKE_BUILD_TYPE=release \
		-DBUILD_STATIC_LIBS=ON \
	   	-DBUILD_SHARED_LIBS=OFF \
		-DCMAKE_VERBOSE_MAKEFILE=true \
		-G "Unix Makefiles" ../ && \
	$(MAKE) && \
	ln -sf $(CURRENT_DIR)/jsoncpp/build/src/lib_json/libjsoncpp.a $(CURRENT_DIR)

libjsonrpc-cpp.a:
# jsonrpc-cpp
	echo "compiling jsonrpc-cpp"
	cd jsonrpc-cpp && \
	./autogen.sh && \
	./configure \
		--with-jsoncpp-inc-dir=$(JSONCPP_INC_DIR) \
		--enable-shared=no \
		LDFLAGS="" && \
	$(MAKE) && \
	ln -sf $(CURRENT_DIR)/jsonrpc-cpp/src/.libs/libjsonrpc-cpp.a $(CURRENT_DIR)

clean:
	rm -f libjsoncpp.a libjsonrpc-cpp.a
