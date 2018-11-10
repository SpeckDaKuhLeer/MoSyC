SOURCE_DIR=./src
BUILD_DIR=./build
INSTALLATION_DIR=.
C_COMPILER=gcc
C_FLAGS=-std=c99 -O3
LD_FLAGS=
EXECUTABLE=$(INSTALLATION_DIR)/mosyc

default: $(EXECUTABLE)

$(EXECUTABLE): $(BUILD_DIR)/core.o $(BUILD_DIR)/gui_manager.o
	$(C_COMPILER) $(LD_FLAGS) -lm -lcurses -o $@ $^

$(BUILD_DIR)/gui_manager.o: $(SOURCE_DIR)/gui_manager.c $(SOURCE_DIR)/gui_manager.h
	$(C_COMPILER) $(C_FLAGS) -c -o $@ $<

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c
	$(C_COMPILER) $(C_FLAGS) -c $^ -o $@

clean:
	rm -f $(EXECUTABLE)
	rm -f $(BUILD_DIR)/*.o
	rm -f $(BUILD_DIR)/*.a
