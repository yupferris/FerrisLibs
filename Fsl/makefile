cc=g++
ar=ar
srcdir=src
incdir=include
libdir=lib
builddir=build
cflags=-c -std=c++11 -I$(incdir)
ldflags=
arflags=rcs
sources=BinaryReader.cpp BitReader.cpp Console.cpp EndOfStreamException.cpp Exception.cpp File.cpp FileStream.cpp MemoryStream.cpp Mutex.cpp NotSupportedException.cpp Random.cpp Stream.cpp Win32Console.cpp Win32Directory.cpp Win32Mutex.cpp Win32Threading.cpp Win32Time.cpp
objects=$(addprefix $(builddir)/,$(sources:.cpp=.o))
output=$(libdir)/Fsl.lib

all: $(builddir) $(output)

$(output): $(objects)
	$(ar) $(arflags) $@ $(objects)

$(objects): $(addprefix $(srcdir)/,$(sources))
	$(cc) $(cflags) $(srcdir)/$(@F:.o=.cpp) -o $@

$(builddir):
	mkdir $(builddir)

clean:
	rm -rf $(builddir)
	rm -rf $(libdir)/*
