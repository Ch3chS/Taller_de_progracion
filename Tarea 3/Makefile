# Directorios de origen y destino
SRC_DIR := src
TEST_DIR := test
BUILD_DIR := build
BIN_DIR := bin
INC_DIR := inc
TESTBIN_DIR := testbin

# Flags del compilador
CXX := g++
CXXFLAGS := -std=c++11 -Wall -I$(INC_DIR)

# Archivos fuente
MAIN_SRC := $(SRC_DIR)/main.cpp
TEST_SRCS := $(wildcard $(TEST_DIR)/*.cpp)

# Encontrar todos los archivos .cpp en el directorio src
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)

# Generar una lista de archivos objeto reemplazando .cpp con .o y src/ con build/
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))
COMMON_OBJS := $(filter-out $(BUILD_DIR)/main.o,$(OBJ_FILES))

# Objetos
MAIN_OBJ := $(BUILD_DIR)/main.o
TEST_OBJS := $(patsubst $(TEST_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(TEST_SRCS))
TEST_EXECUTABLES := $(patsubst $(TEST_DIR)/%.cpp,$(TESTBIN_DIR)/%,$(TEST_SRCS))

# Nombre del ejecutable principal
EXECUTABLE := $(BIN_DIR)/main

# Regla principal
all: create_dirs $(EXECUTABLE) $(TEST_EXECUTABLES)

# Crear directorios bin y testbin
create_dirs:
	mkdir -p $(BIN_DIR)
	mkdir -p $(TESTBIN_DIR)
	mkdir -p $(BUILD_DIR)

# Regla de compilación para el programa principal
$(MAIN_OBJ): $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla de compilación para los archivos de prueba
$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla de patrón para construir archivos objeto a partir de archivos fuente
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla de enlace para el programa principal
$(EXECUTABLE): $(MAIN_OBJ) $(COMMON_OBJS)
	$(CXX) $^ -o $@

# Regla de enlace para los ejecutables de pruebas
$(TESTBIN_DIR)/%: $(BUILD_DIR)/%.o $(COMMON_OBJS)
	$(CXX) $^ -o $@

# Limpiar los archivos objeto y los ejecutables
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR) $(TESTBIN_DIR)
