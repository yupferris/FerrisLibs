cc=g++
ar=ar
srcdir=src
incdir=include
fsldir=$(FERRISLIBS_DIR)Fsl
libdir=lib
builddir=build
cflags=-c -std=c++11 -I$(incdir) -I$(fsldir)/$(incdir) -Ic:/mingw32/include
ldflags=
arflags=rcs
sources=Button.cpp Menu.cpp MenuChild.cpp MenuItem.cpp Panel.cpp Viewport.cpp Widget.cpp Win32Button.cpp Win32Controls.cpp Win32DialogWindow.cpp Win32Menu.cpp Win32MenuItem.cpp Win32MessageWindow.cpp Win32Viewport.cpp Win32Window.cpp Window.cpp
objects=$(addprefix $(builddir)/,$(sources:.cpp=.o))
output=$(libdir)/Fgl.lib

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
