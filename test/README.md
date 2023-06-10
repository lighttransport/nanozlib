Generate zlib compressed file using pigz.

https://unix.stackexchange.com/questions/22834/how-to-uncompress-zlib-data-in-unix

```
# compress
$ pigz -z input.file

# decompress
$ pigz -d -z input.zz
```

# Uncompressed size

* test-000.txt : 11
