# {C} Copyright 2018 Pensando Systems Inc. All rights reserved.
PKG_PREREQS:= all

platform-clean:
    ifeq ($(ARCH),aarch64)
		cd ${TOPDIR}/platform && make BUILD_ARCHES=aarch64 clean
    else
		cd ${TOPDIR}/platform && make BUILD_ARCHES=x86_64 clean
    endif

package-clean:
	@rm -rf $(NICDIR)/../fake_root_target
	@rm -f  $(NICDIR)/nic.tgz
	@rm -f  $(NICDIR)/nic.tar

package: ${PKG_PREREQS}
    ifeq ($(ARCH),aarch64)
		${MAKE} -j1 BUILD_ARCHES=aarch64 -C ${TOPDIR}/platform
		${MAKE} package-clean
		cd $(NICDIR)/../ && python $(NICDIR)/tools/package/package.py
    else
        ifeq ($(PIPELINE),iris)
			${MAKE} -j1 BUILD_ARCHES=x86_64 -C ${TOPDIR}/platform
        endif
		${MAKE} package-clean
		cd $(NICDIR)/../ && python $(NICDIR)/tools/package/package.py \
			--pipeline $(PIPELINE) --target sim --no-strip
    endif

package-clean-debug:
	@rm -f  $(TOPDIR)/debug.tgz
	@rm -f  $(TOPDIR)/debug.tar

package-debug: package-clean-debug
	cd $(NICDIR)/../ && python $(NICDIR)/tools/package/package.py --target debug --no-strip

package-zebu: package-clean ${PKG_PREREQS}
    ifneq ($(ARCH),aarch64)
		cd $(NICDIR)/../ && python $(NICDIR)/tools/package/package.py --target zebu --no-strip
    endif

package-arm-dev: package-clean ${PKG_PREREQS}
	${MAKE} -j1 BUILD_ARCHES=aarch64 OPT=-g -C ${TOPDIR}/platform
	cd $(NICDIR)/../ && python $(NICDIR)/tools/package/package.py --target arm-dev --no-strip

package-haps-dbg: package-clean ${PKG_PREREQS}
	${MAKE} -j1 BUILD_ARCHES=aarch64 OPT=-g -C ${TOPDIR}/platform
	cd $(NICDIR)/../ && python $(NICDIR)/tools/package/package.py --target haps-dbg

package-storage-offload:
	${TOPDIR}/storage/offload/tools/drivers-linux.sh

release: ${PKG_PREREQS}
    ifneq ($(ARCH),aarch64)
	    ${NICDIR}/tools/release.sh
    endif

release-clean:
	@rm -rf obj/release
