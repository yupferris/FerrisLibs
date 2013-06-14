cc=g++
ar=ar
srcdir=src
incdir=include
fsldir=$(FERRISLIBS_DIR)Fsl
fgldir=$(FERRISLIBS_DIR)Fgl
libdir=lib
builddir=build
cflags=-c -std=c++11 -I$(incdir) -I$(fsldir)/$(incdir) -I$(fgldir)/$(incdir) -Ic:/mingw32/include -I"$(DXSDK_DIR)Include"
ldflags=
arflags=rcs
sources=Cpu32.cpp IAudioDriver.cpp IVideoDriver.cpp Win32AudioDriverFactory.cpp Win32DirectSoundAudioDriver.cpp Win32GLVideoDriver.cpp Win32VideoDriverFactory.cpp
objects=$(addprefix $(builddir)/,$(sources:.cpp=.o))
output=$(libdir)/Fel.lib

all: $(builddir) $(output)

$(output): $(objects)
	@$(ar) $(arflags) $@ $(objects)

$(objects): $(addprefix $(srcdir)/,$(sources))
	@$(cc) $(cflags) $(srcdir)/$(@F:.o=.cpp) -o $@

$(builddir):
	@mkdir $(builddir)

clean:
	@rm -rf $(builddir)
	@rm -rf $(libdir)/*
