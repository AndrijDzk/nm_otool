#!/usr/bin/env bash

mkdir -p tests
otool -t $@ > tests/sys_otool.txt;
./ft_otool $@ > tests/my_otool.txt;
diff tests/my_otool.txt tests/sys_otool.txt;
diff tests/my_otool.txt tests/sys_otool.txt > tests/otool_diff.txt;