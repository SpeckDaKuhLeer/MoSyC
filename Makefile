SOURCE_DIR=./src
BUILD_DIR=./build
INSTALLATION_DIR=.
C_COMPILER=gcc
C_FLAGS=-std=gnu99

EXECUTABLE=$(INSTALLATION_DIR)/mosyc

default: $(EXECUTABLE)

all: clean default

$(EXECUTABLE): $(BUILD_DIR)/core.o
	$(C_COMPILER) $(LD_FLAGS) -lm -o $@ $<

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c
	$(C_COMPILER) $(C_FLAGS) -c $< -o $@

clean:
	rm -f $(EXECUTABLE)
	rm -f $(BUILD_DIR)/*
