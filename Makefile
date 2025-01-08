.SUFFIXES:


INCDIR::= include
COMDIR::= common
DATDIR::= data

TGT::= bin
DBG::= dbg
SRC::= $(shell ls ${COMDIR}/* ${DATDIR}/*)






all: ${TGT}
debug: ${DBG}
down:
	@for f in *; do [ ! -d $$f ] && [ $$f != Makefile ] && rm -f $$f; done; true

emain:
	@vim {${INCDIR},${COMDIR},${DATDIR}}/main.*
estr:
	@vim {${INCDIR},${COMDIR},${DATDIR}}/strtree.*
edb:
	@vim {${INCDIR},${COMDIR},${DATDIR}}/db.*
eint:
	@vim {${INCDIR},${COMDIR},${DATDIR}}/int.*






${TGT}: ${SRC}
	@gcc -I ${INCDIR} $^ -o $@
${DBG}: ${SRC}
	@gcc -g -I ${INCDIR} $^ -o $@
