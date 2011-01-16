#include "highgui.h"
#include <stdio.h>

void applyMaskFilter(uchar* data, int width, int height, int channels, int step);

int main(int argc, char *argv[])
{
  IplImage* img = 0; 
  int height,width,step,channels;
  uchar *data;

  if(argc<2){
    printf("Usage: main <image-file-name>\n\7");
    exit(0);
  }

  // load an image  
  img=cvLoadImage(argv[1], CV_LOAD_IMAGE_COLOR);
  if(!img){
    printf("Could not load image file: %s\n",argv[1]);
    exit(0);
  }

  // get the image data
  height    = img->height;
  width     = img->width;
  step      = img->widthStep;
  channels  = img->nChannels;
  data      = (uchar *)img->imageData;
  printf("Processing a %dx%d image with %d channels\n",height,width,channels); 
  printf("widthStep %d", step);

  // create a window
  cvNamedWindow("mainWin", CV_WINDOW_AUTOSIZE); 
  cvMoveWindow("mainWin", 100, 100);

  // invert the image
  applyMaskFilter(data, width, height, channels, step);

  // show the image
  cvShowImage("mainWin", img );

  // wait for a key
  cvWaitKey(0);

  // release the image
  cvReleaseImage(&img );
  return 0;
}


void applyMaskFilter(uchar* data, int width, int height, int channels, int step) {
  int i, j, k, index;
  for( i=0; i<height; i++ ) 
    for( j=0; j<width; j++ ) 
      for( k=0; k<channels; k++ ) {
        index = i*step+j*channels+k;
        if ( index % 1000  == 0 )
          printf("%d * %d + %d * %d + %d = %d\n", i, step, j, channels, k, index);
        data[index]=255 - data[index];
      }
}

