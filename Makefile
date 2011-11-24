# Platform Specifics
CC ?= gcc
LD ?= ld
SO ?= .so
O ?= .o

# Dependency on Radare2's r_cmd

R_CMD_CFLAGS ?= $(shell pkg-config --cflags r_cmd)
R_CMD_LIBS   ?= $(shell pkg-config --libs r_cmd)
CFLAGS += $(R_CMD_CFLAGS)
LIBS += $(R_CMD_LIBS)

# Target Definition
PLUGIN ?= cmd_sample$(SO)
OBJECTS ?= sample$(O)
CFLAGS += -fPIC
LDFLAGS += -shared

INSTALL_DIR ?= $(HOME)/radare2/plugins


build: $(PLUGIN)
	
install: $(PLUGIN)
	install $(PLUGIN) $(INSTALL_DIR)/$(PLUGIN)

clean:
	rm -f *.o *.so *.obj *.dll

$(PLUGIN): $(OBJECTS)
	$(LD) $(LDFLAGS) $(LIBS) $(OBJECTS) -o $(PLUGIN) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

