# rgb-deinterleave-arm-neon

This project is demonstrates a comparison between a naive C code and a optimized arm-neon C code

## Build instructions
``` Docker
Docker pull ssshriharis/shriharishetty
```
### Run the image
``` Docker
Docker run -i -t ssshriharis/shriharishetty bash
```
### Compile the program
``` Docker
gcc -g -o3 rgbDeInterleave.c -o ex.out  
```
### Run the Program
``` Docker
./ex.out
```

