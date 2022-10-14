 #include <arm_neon.h>
 #include  <stdio.h>
 #include <time.h>

 void print_rgb_colors(uint8_t *r, uint8_t *g, uint8_t *b,int len){
     len/=3;
     for(int i = 0; i < len;i++){
         printf("%d ", r[i]);
     }
     printf("\n");
     for(int i = 0; i < len;i++){
         printf("%d ", g[i]);
     }
     printf("\n");
     for(int i = 0; i < len;i++){
         printf("%d ", b[i]);
     }
     printf("\n");
 }
 void rgb_deinterleave_naive(uint8_t *r, uint8_t *g, uint8_t *b, uint8_t *rgb, int len_color) {
    /*
     *  Iterate on "rgb" array and store the individual colors "r", "g", and "b" arrays
     */
    for (int i=0; i < len_color; i++) {
        r[i] = rgb[3*i];
        g[i] = rgb[3*i+1];
        b[i] = rgb[3*i+2];
    }
}
  void rgb_deinterleave_neon(uint8_t *r, uint8_t *g, uint8_t *b, uint8_t *rgb, int len_color) {
    /*
     * Iterate on "rgb" array and store the individual colors "r", "g", and "b" arrays
     */
    int num8x16 = len_color / 16;
    uint8x16x3_t intlv_rgb;
    for (int i=0; i < num8x16; i++) {
        intlv_rgb = vld3q_u8(rgb+3*16*i);
        vst1q_u8(r+16*i, intlv_rgb.val[0]);
        vst1q_u8(g+16*i, intlv_rgb.val[1]);
        vst1q_u8(b+16*i, intlv_rgb.val[2]);
    }
}

    int main(){

        int len = 999999;
        uint8_t r[len];
        uint8_t g[len];
        uint8_t b[len];
        uint8_t rgb[len];
        for(int i = 2; i < len; i+=3){
            rgb[i] = 3;
            rgb[i-1] = 2;
            rgb[i-2] = 1;
        }
        double time_spent1 = 0.0;
	    double time_spent2 = 0.0;
	    clock_t begin = clock();
        for(int j = 0; j < 10000; j++)
	       rgb_deinterleave_naive(r,g,b,rgb,len);

	    clock_t end = clock();
	    time_spent1 += (double)(end - begin) / CLOCKS_PER_SEC;

	    printf("Time elpased is %f seconds for deinterleaving RGB Colors using Naive approach.\n", time_spent1);
        //Please modify len to a smaller value before uncommenting the next line
        // print_rgb_colors(r,g,b,len);

    	begin = clock();
        for(int j = 0; j < 10000; j++)
	        rgb_deinterleave_neon(r,g,b,rgb,len/3);

    	end = clock();
	    time_spent2 += (double)(end - begin) / CLOCKS_PER_SEC;

    	printf("Time elpased is %f seconds for deinterleaving RGB Colors using ARM Neon instructions\n", time_spent2);
        //Please modify len to a smaller value before uncommenting the next line
        // print_rgb_colors(r,g,b,len);

	    printf("%f X time faster.\n", time_spent1/time_spent2);
        return 0;
    }