# Configuração padrão para compilar Homebrew de Wii
TARGET		:= boot
include $(DEVKITPPC)/wii_rules

CFLAGS		:= -g -O2 -mrvl -Wall
CXXFLAGS	:= $(CFLAGS)

LIBS		:= -lwiiuse -lbte -logc -lm

OBJS		:= main.o

all: $(TARGET).dol

$(TARGET).dol: $(TARGET).elf
$(TARGET).elf: $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET).elf $(TARGET).dol

