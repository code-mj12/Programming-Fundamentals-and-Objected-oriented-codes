CXXFLAGS = -g3 -Wall -fmessage-length=0 -fPIE #-Werror

OBJS =		wordshooter.o util.o #Board.o util.o #game.o

LIBS =-L/usr/X11R6/lib -lm -lpthread -L/usr/X11R6/lib -L/sw/lib -L/usr/sww/lib -L/usr/sww/bin -L/usr/sww/pkg/Mesa/lib -lglut -lGLU -lGL -lX11 -lfreeimage



TARGET = word-shooter	


$(TARGET):	$(OBJS) 
	 $(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
