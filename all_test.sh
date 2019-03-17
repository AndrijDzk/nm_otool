#!/usr/bin/env bash

TESTFILES="./ft_nm ./ft_otool ar_archive.a object32.o object64.o binary32 binary64 /usr/bin/python /usr/lib/libCRFSuite.dylib author Makefile"


./nm_test.sh $TESTFILES
./otool_test.sh $TESTFILES
