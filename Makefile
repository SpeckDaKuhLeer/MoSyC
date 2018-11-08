SOURCE_DIR=./src
INSTALLATION_DIR=.
C_COMPILER=gcc -std=gnu99

TOOL=$(INSTALLATION_DIR)/mosyc

default: $(TOOL)

all: clean default

$(TOOL): $(SOURCE_DIR)/core.c
	$(C_COMPILER) -lm -o $@ $<

clean:
	rm -f $(TOOL)
