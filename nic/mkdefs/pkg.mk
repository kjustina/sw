# {C} Copyright 2018 Pensando Systems Inc. All rights reserved.
PKG_PREREQS:= all

package-clean:
	@rm -rf $(NICDIR)/../fake_root_target
	@rm -f  $(NICDIR)/nic.tgz
	@rm -f  $(NICDIR)/nic.tar

package: ${PKG_PREREQS}
    ifeq ($(ARCH),aarch64)
		${MAKE} BUILD_ARCHES=aarch64 -C ${TOPDIR}/platform
		${MAKE} package-clean
		cd $(NICDIR)/../ && python $(NICDIR)/tools/package/package.py
    else
		${MAKE} BUILD_ARCHES=x86_64 -C ${TOPDIR}/platform
		${MAKE} package-clean
		cd $(NICDIR)/../ && python $(NICDIR)/tools/package/package.py --target sim --no-strip
    endif

package-zebu: package-clean ${PKG_PREREQS}
    ifneq ($(ARCH),aarch64)
		cd $(NICDIR)/../ && python $(NICDIR)/tools/package/package.py --target zebu --no-strip
    endif

package-arm-dev: package-clean ${PKG_PREREQS}
	${MAKE} BUILD_ARCHES=aarch64 -C ${TOPDIR}/platform
	cd $(NICDIR)/../ && python $(NICDIR)/tools/package/package.py --target arm-dev --no-strip

package-haps-dbg: package-clean ${PKG_PREREQS}
	${MAKE} BUILD_ARCHES=aarch64 -C ${TOPDIR}/platform
	cd $(NICDIR)/../ && python $(NICDIR)/tools/package/package.py --target haps-dbg

release: ${PKG_PREREQS}
    ifneq ($(ARCH),aarch64)
	    ${NICDIR}/tools/release.sh
    endif

release-clean:
	@rm -rf obj/release
