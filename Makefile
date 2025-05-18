CC = g++
CFLAGS = -std=c++20 -Wall -Wextra -pedantic
BUILD_DIR = build

TARGET = ${BUILD_DIR}/Main
OBJS = ${BUILD_DIR}/Main.o ${BUILD_DIR}/Utils.o ${BUILD_DIR}/Product.o ${BUILD_DIR}/Inventory.o ${BUILD_DIR}/FileManager.o ${BUILD_DIR}/InventoryApp.o ${BUILD_DIR}/ConsoleUI.o ${BUILD_DIR}/InputHandler.o ${BUILD_DIR}/ErrorConsoleUI.o ${BUILD_DIR}/InputConsoleUI.o

${TARGET}: ${OBJS}
	${CC} ${OBJS} -o $@
${BUILD_DIR}/Main.o: src/Main.cpp | ${BUILD_DIR}
	${CC} -c $< -o $@
${BUILD_DIR}/Utils.o: src/utils/Utils.cpp | ${BUILD_DIR}
	${CC} -c $< -o $@
${BUILD_DIR}/Product.o: src/core/Product.cpp | ${BUILD_DIR}
	${CC} -c $< -o $@
${BUILD_DIR}/Inventory.o: src/core/Inventory.cpp | ${BUILD_DIR}
	${CC} -c $< -o $@
${BUILD_DIR}/FileManager.o: src/utils/FileManager.cpp | ${BUILD_DIR}
	${CC} -c $< -o $@
${BUILD_DIR}/InventoryApp.o: src/core/InventoryApp.cpp | ${BUILD_DIR}
	${CC} -c $< -o $@
${BUILD_DIR}/ConsoleUI.o: src/ui/ConsoleUI.cpp | ${BUILD_DIR}
	${CC} -c $< -o $@
${BUILD_DIR}/InputHandler.o: src/utils/InputHandler.cpp | ${BUILD_DIR}
	${CC} -c $< -o $@
${BUILD_DIR}/ErrorConsoleUI.o: src/ui/ErrorConsoleUI.cpp | ${BUILD_DIR}
	${CC} -c $< -o $@
${BUILD_DIR}/InputConsoleUI.o: src/ui/InputConsoleUI.cpp | ${BUILD_DIR}
	${CC} -c $< -o $@

${BUILD_DIR}:
	mkdir -p ${BUILD_DIR}

clean:
	rmdir /S /Q ${BUILD_DIR}
