#bin/bash/
gcc -shared -o myprintf.so -fpic test.c
export LD_PRELOAD=./myprintf.so:$LD_LIBRARY_PATH
