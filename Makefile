SOURCE_DIR=./src/
INSTALLATION_DIR=./
C_COMPILER=gcc -std=gnu99

mosyc: $(SOURCE_DIR)core.c
	$(C_COMPILER) -lm -o $(INSTALLATION_DIR)mosyc $(SOURCE_DIR)core.c
