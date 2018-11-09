SOURCE_DIR=./src
BUILD_DIR=./build
INSTALLATION_DIR=.
C_COMPILER=gcc
C_FLAGS=-std=c11 -O3
LD_FLAGS=
EXECUTABLE=$(INSTALLATION_DIR)/mosyc

default: $(EXECUTABLE)

$(EXECUTABLE): $(BUILD_DIR)/core.o
	$(C_COMPILER) $(LD_FLAGS) -lm -o $@ $<

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c
	$(C_COMPILER) $(C_FLAGS) -c $< -o $@

clean:
	rm -f $(EXECUTABLE)
	rm -f $(BUILD_DIR)/*.o
