// create array to put to camera_index.h from binary file
// use it on modified an gzipped index.html
// Taken from ESP32 Forum - written by HermannSW

#include <stdio.h>
#include <assert.h>

int main(int argc, char *argv[])
{
  unsigned char buf[10000];
  FILE *src;
  int len, i;
  assert(argc==2);
  src = fopen(argv[1], "rb");
  assert(src);
  fseek(src,0,SEEK_END);
  len=ftell(src);
  rewind(src);
  assert(fread(buf,len,1,src)==1);

  printf("#define index_ov2640_html_gz_len %d\n",len);
  printf("const unsigned char index_ov2640_html_gz[] = {\n");

  for(i=0; i<len; ++i)
  {
    printf(" 0x%02x", buf[i]);
    if (i!=len-1)
      printf(",");
    if (i%16==15)
      printf("\n");
  } 

  printf("\n};\n");
}
