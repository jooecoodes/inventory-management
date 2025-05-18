CC = g++
CFLAGS = -std=c++20 -Wall -Wextra -pedantic
BUILD_DIR = build

TARGET = ${BUILD_DIR}/Main
OBJS = ${BUILD_DIR}/Main.o ${BUILD_DIR}/Utils.o ${BUILD_DIR}/Product.o ${BUILD_DIR}/Inventory.o ${BUILD_DIR}/FileManager.o ${BUILD_DIR}/InventoryApp.o ${BUILD_DIR}/ConsoleUI.o ${BUILD_DIR}/InputHandler.o ${BUILD_DIR}/ErrorConsoleUI.o ${BUILD_DIR}/InputConsoleUI.o

${TARGET}: ${OBJS}
	${CC} ${OBJS} -o $@
${BUILD_DIR}/Main.o: src/Main.cpp | ${BUILD_DIR}
	${CC} -c $< -o $@
${BUILD_DIR}/Utils.o: include/Utils.cpp | ${BUILD_DIR}
	${CC} -c $< -o $@
${BUILD_DIR}/Product.o: include/Product.cpp | ${BUILD_DIR}
	${CC} -c $< -o $@
${BUILD_DIR}/Inventory.o: include/Inventory.cpp | ${BUILD_DIR}
	${CC} -c $< -o $@
${BUILD_DIR}/FileManager.o: include/FileManager.cpp | ${BUILD_DIR}
	${CC} -c $< -o $@
${BUILD_DIR}/InventoryApp.o: include/InventoryApp.cpp | ${BUILD_DIR}
	${CC} -c $< -o $@
${BUILD_DIR}/ConsoleUI.o: include/ConsoleUI.cpp | ${BUILD_DIR}
	${CC} -c $< -o $@
${BUILD_DIR}/InputHandler.o: include/InputHandler.cpp | ${BUILD_DIR}
	${CC} -c $< -o $@
${BUILD_DIR}/ErrorConsoleUI.o: include/ErrorConsoleUI.cpp | ${BUILD_DIR}
	${CC} -c $< -o $@
${BUILD_DIR}/InputConsoleUI.o: include/InputConsoleUI.cpp | ${BUILD_DIR}
	${CC} -c $< -o $@

${BUILD_DIR}:
	mkdir -p ${BUILD_DIR}

clean:
	rmdir /S /Q ${BUILD_DIR}
