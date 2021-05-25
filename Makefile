SUBDIRS=Error
SUBDIRS_CLEAN=$(patsubst %, %.clean, $(SUBDIRS))


.PHONY: $(SUBDIRS) $(SUBDIRS_CLEAN) clean

$(SUBDIRS): 
	$(MAKE) build -C $(patsubst %,%, $@)

$(SUBDIRS_CLEAN):
	$(MAKE) clean -C $(patsubst %.clean,%, $@)

build: install-headers $(SUBDIRS)

build-docker: install-headers-docker $(SUBDIRS)


install: 
	$(MAKE) install -C Error

install-headers:
	mkdir -p /usr/local/include/cpperror
	$(MAKE) install-headers -C Error

install-headers-docker:
	mkdir -p /usr/include/cpperror
	$(MAKE) install-headers-docker -C Error

install-docker: 
	$(MAKE) install-docker -C Error

uninstall: 
	rm -rf /usr/local/include/cpperror
	$(MAKE) uninstall -C Error


clean: $(SUBDIRS_CLEAN)


