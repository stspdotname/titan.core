##############################################################################
# Copyright (c) 2000-2018 Ericsson Telecom AB
# All rights reserved. This program and the accompanying materials
# are made available under the terms of the Eclipse Public License v2.0
# which accompanies this distribution, and is available at
# https://www.eclipse.org/org/documents/epl-2.0/EPL-2.0.html
#
# Contributors:
#   Szabo, Bence Janos
#
##############################################################################
TOPDIR := ../../../..
include $(TOPDIR)/Makefile.regression

ifdef LCOV
COVERAGE_FLAG := -C
endif

# ${MAKEPROG} has the same content as the built-in ${MAKE},
# except the special handling of ${MAKE} does not apply.
# If we used ${MAKE} in the rules below, 'make -n' would succeed once,
# then fail on every subsequent invocation until a 'make clean' is done. 

#This tests that 'a' references 'b' and 'b' references 'c' and 'a' requires
#'b''s '1' configuration and 'c''s '2' configuration.
#Additionally and 'b''s '1' configuration requires 'c''s '1' config.
#This tests that two different configuration was required for 'c' and
#an error is produced.
#      a
#     / \
# b:1/   \c:2
#   /     \
#  b------>c
#   b:1=>c:1

MAKEPROG := ${MAKE}

all: CheckTpd 

BuildTpd:
	$(TTCN3_DIR)/bin/ttcn3_makefilegen -f $(MFGEN_FLAGS) $(COVERAGE_FLAG) \
	-t a.tpd -r -c -W -g 2>&1 | tee output

CheckTpd: BuildTpd
	if [ `grep -c "error: Required configuration is inconsistent or circular : Project 'c' cannot have 2 different configuration '2' and '1'" ./output` -ne 1 ]; \
	then echo "Makefilegen required config test 10 failed: Overall verdict: fail" && exit 1; fi

clean:
	-rm -rf output a_binDefault b_bin1

distclean: clean
	-rm -f *.out

.PHONY: all clean distclean BuildTpd CheckTpd

