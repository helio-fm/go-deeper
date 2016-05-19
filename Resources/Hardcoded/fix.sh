#!/bin/bash

for f in *.c; do
	echo '#include <math.h>' | cat - $f > temp && mv temp $f
done
