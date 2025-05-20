# Inventory Management System

![Static Badge](https://img.shields.io/badge/build-20-blue?label=C%2B%2B)
![Static Badge](https://img.shields.io/badge/build-13.2.0-purple?label=g%2B%2B)
![Static Badge](https://img.shields.io/badge/build-3.82.90-brightgreen?label=Make)

![Flowchart](flow/flow.svg)

A Console-based inventory management application with file-based database (.dat). Final project for Computer Programming II.
# Features
- **Product Management**
  - Add new products with details (ID, Name, Category, Quantity, Price)
  - Remove existing products
  - Update product information
  - View complete inventory

- **Search Functionality**
  - Search products by name or partial matches
  - Case-sensitive searching

- **Data Persistence**
  - File-based storage (.dat format)
  - Automatic data directory creation
  - Error-resistant file operations

- **User Interface**
  - Color-coded console interface
  - Input validation and error handling
  - Responsive menu system

# System Design
- **Core:** Inventory and Product classes handle business logic
- **UI:** Console-based interface with ANSI coloring
- **Utilities:** Input validation and string manipulation
- **Storage:** FileManager handles all data persistence
# Technical Details
- **Language:** C++20
- **Dependencies:** Standard Library only
- **File Format:** CSV-style .dat files
- **Error Handling:** Comprehensive exception handling

# Installation

```bash
git clone https://github.com/jooecoodes/inventory-management.git
cd inventory-management
make
```
Create the ```data``` folder in the root directory, and then create a file inside that directory called ```inventory.dat```.
```bash
data/inventory.dat
```
## Running
First create the ```build``` directory.
```bash
mkdir build
```
### With make
```bash
make
```
And then run the ```.exe``` file.
```bash
build/Main.exe
```
### Without make
Generate the ```.o``` or ```object``` files.
```
g++ -std=c++20 -Wall -Wextra -pedantic -c src/Main.cpp -o build/Main.o
g++ -std=c++20 -Wall -Wextra -pedantic -c src/utils/Utils.cpp -o build/Utils.o
g++ -std=c++20 -Wall -Wextra -pedantic -c src/core/Product.cpp -o build/Product.o
g++ -std=c++20 -Wall -Wextra -pedantic -c src/core/Inventory.cpp -o build/Inventory.o
g++ -std=c++20 -Wall -Wextra -pedantic -c src/utils/FileManager.cpp -o build/FileManager.o
g++ -std=c++20 -Wall -Wextra -pedantic -c src/core/InventoryApp.cpp -o build/InventoryApp.o
g++ -std=c++20 -Wall -Wextra -pedantic -c src/ui/ConsoleUI.cpp -o build/ConsoleUI.o
g++ -std=c++20 -Wall -Wextra -pedantic -c src/utils/InputHandler.cpp -o build/InputHandler.o
g++ -std=c++20 -Wall -Wextra -pedantic -c src/ui/ErrorConsoleUI.cpp -o build/ErrorConsoleUI.o
g++ -std=c++20 -Wall -Wextra -pedantic -c src/ui/InputConsoleUI.cpp -o build/InputConsoleUI.o
```
Link them together.
```bash
g++ -std=c++20 -Wall -Wextra -pedantic build/Main.o build/Utils.o build/Product.o build/Inventory.o build/FileManager.o build/InventoryApp.o build/ConsoleUI.o build/InputHandler.o build/ErrorConsoleUI.o build/InputConsoleUI.o -o build/Main.exe
```
And finally, run the ```.exe``` file.
```bash
build/Main.exe
```
# Contributing
1. Fork the repository
2. Create your feature branch (```git checkout -b feature/AmazingFeature```)
3. Commit your changes (```git commit -m 'Add some AmazingFeature'```)
4. Push to the branch (```git push origin feature/AmazingFeature```)
5. Open a Pull Request
# License
Distributed under the MIT License. See ```LICENSE``` for more information.
# Future Enhancements
- Database integration (SQLite)
- Barcode scanning support
- Multi-user access control
- Reporting module
- Machine Learning Integration
