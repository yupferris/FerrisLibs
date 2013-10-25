CC = clang++
CXXFLAGS = -std=c++11  -stdlib=libc++ -Os -Wall
INCLUDES = -I$(FSL_INCLUDE_PATH)
LFLAGS = 
OUTDIR = $(FSL_LIB_PATH)

LIBS = 
SRCS = \
	src/BinaryReader.cpp \
	src/BitReader.cpp \
	src/Console.cpp \
	src/EndOfStreamException.cpp \
	src/Exception.cpp \
	src/File.cpp \
	src/FileStream.cpp \
	src/MemoryStream.cpp \
	src/Mutex.cpp \
	src/NotSupportedException.cpp \
	src/Random.cpp \
	src/Stream.cpp
OBJS = $(SRCS:.cpp=.o)
MAIN = $(OUTDIR)/libfsl.a

all: $(MAIN)

$(MAIN): $(OBJS) $(OUTDIR)
	ar crv $(MAIN) $(OBJS)

$(OUTDIR):
	mkdir $(OUTDIR)

%.o: %.cpp
	$(CC) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean: $(SRCS) $(OUTDIR)
	$(RM) *.o $(MAIN) src/*.o
