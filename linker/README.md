```
uname -a > blob
ld -s -r -b binary -o blob.o blob
objdump -t blob.o
strings blob.o
readelf -s blob.o
gcc test.c blob.o -o test
readelf -S test
```

https://github.com/vogelchr/objcopy_to_carray
https://github.com/f9micro/f9-kernel/blob/master/Documentation/init-hooks.txt
