include $(DEVKITPPC)/wii_rules

TARGET   := boot
OBJS     := main.o
LIBS     := -lwiiuse -lbte -logc -lm

all: $(TARGET).dol

$(TARGET).dol: $(TARGET).elf
$(TARGET).elf: $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET).elf $(TARGET).dol

