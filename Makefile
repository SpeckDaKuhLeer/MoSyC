SOURCE_DIR=./src
BUILD_DIR=./build
INSTALLATION_DIR=.
C_COMPILER=gcc
C_FLAGS=-std=c17 -O3
LD_FLAGS=
EXECUTABLE=$(INSTALLATION_DIR)/mosyc

default: $(EXECUTABLE)

$(EXECUTABLE): $(BUILD_DIR)/core.o $(BUILD_DIR)/consolegraphics.o
	$(C_COMPILER) $(LD_FLAGS) -lm -lcurses -o $@ $^

$(BUILD_DIR)/consolegraphics.o: $(SOURCE_DIR)/consolegraphics.c $(SOURCE_DIR)/consolegraphics.h
	$(C_COMPILER) $(C_FLAGS) -c -o $@ $<

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c
	$(C_COMPILER) $(C_FLAGS) -c $^ -o $@

all: clean default

clean:
	rm -f $(EXECUTABLE)
	rm -f $(BUILD_DIR)/*.o
	rm -f $(BUILD_DIR)/*.a
