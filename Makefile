.SUFFIXES:


INCDIR::= include
COMDIR::= common
DATDIR::= data

TGT::= bin
SRC::= $(shell ls ${COMDIR}/* ${DATDIR}/*)






all: ${TGT}
down:
	@rm ${TGT}
	
e-main:
	@vim {${INCDIR},${COMDIR},${DATDIR}}/main.*
e-db:
	@vim {${INCDIR},${COMDIR},${DATDIR}}/db.*
e-str:
	@vim {${INCDIR},${COMDIR},${DATDIR}}/str.*






${TGT}: ${SRC}
	@gcc -I ${INCDIR} $^ -o $@
