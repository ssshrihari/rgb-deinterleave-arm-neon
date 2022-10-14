# rgb-deinterleave-arm-neon

This project is demonstrates a comparison between a naive C code and a optimized arm-neon C code

#Build instructions

Docker pull ssshriharis/shriharishetty

Docker run -i -t ssshriharis/shriharishetty bash

gcc -g -o3 rgbDeInterleave.c -o ex.out  

./ex.out
![image](https://user-images.githubusercontent.com/18069870/195958615-85d20a83-abb5-4714-b762-0488d2858863.png)
