make=make
subdirs=Fsl Fgl Fel

all: .
	@$(foreach dir,$(subdirs),$(make) -C $(dir);)

clean: .
	@$(foreach dir,$(subdirs),$(make) clean -C $(dir);)