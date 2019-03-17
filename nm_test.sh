#!/usr/bin/env bash

mkdir -p tests
nm $@ > tests/sys_nm.txt;
./ft_nm $@ > tests/my_nm.txt;
diff tests/my_nm.txt tests/sys_nm.txt;
diff tests/my_nm.txt tests/sys_nm.txt > tests/nm_diff.txt;
