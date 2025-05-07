CC = g++
CFLAGS = -std=c++20 -Wall -Wextra -pedantic
BUILD_DIR = build

TARGET = ${BUILD_DIR}/Main
OBJS = ${BUILD_DIR}/Main.o ${BUILD_DIR}/Utils.o ${BUILD_DIR}/Product.o

${TARGET}: ${OBJS}
	${CC} ${OBJS} -o $@
${BUILD_DIR}/Main.o: src/Main.cpp | ${BUILD_DIR}
	${CC} -c $< -o $@
${BUILD_DIR}/Utils.o: include/Utils.cpp | ${BUILD_DIR}
	${CC} -c $< -o $@
${BUILD_DIR}/Product.o: include/Product.cpp | ${BUILD_DIR}
	${CC} -c $< -o $@

${BUILD_DIR}:
	mkdir -p ${BUILD_DIR}

clean:
	rmdir /S /Q ${BUILD_DIR}
