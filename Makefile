INSTALLATION_DIR=./
COMMAND=gcc -lm -std=gnu99 -lportaudio

MoSyC: core.c
	$(COMMAND) -o $(INSTALLATION_DIR)MoSyC core.c
