SUBDIRS=Error
SUBDIRS_CLEAN=$(patsubst %, %.clean, $(SUBDIRS))


.PHONY: $(SUBDIRS) $(SUBDIRS_CLEAN) clean

$(SUBDIRS): 
	$(MAKE) build -C $(patsubst %,%, $@)

$(SUBDIRS_CLEAN):
	$(MAKE) clean -C $(patsubst %.clean,%, $@)

build: $(SUBDIRS)

install: 
	$(MAKE) install -C Error

clean: $(SUBDIRS_CLEAN)


