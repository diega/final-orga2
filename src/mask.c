#include "highgui.h"
#include <stdio.h>

extern void applyMaskFilter(uchar* data, int width, int height, int channels, int step, uchar mask);

int main(int argc, char *argv[])
{
  IplImage* img = 0; 
  int height,width,step,channels,mask;
  uchar *data;

  if(argc<3){
    printf("Usage: %s <image-file-name> <mask>\n\7", argv[0]);
    exit(0);
  }

  // load an image  
  img=cvLoadImage(argv[1], CV_LOAD_IMAGE_COLOR);
  if(!img){
    printf("Could not load image file: %s\n",argv[1]);
    exit(0);
  }
  mask = atoi(argv[2]);

  // get the image data
  height    = img->height;
  width     = img->width;
  step      = img->widthStep;
  channels  = img->nChannels;
  data      = (uchar *)img->imageData;
  printf("Processing a %dx%d image with %d channels\n",height,width,channels); 

  // create a window
  cvNamedWindow("mainWin", CV_WINDOW_AUTOSIZE); 
  cvMoveWindow("mainWin", 100, 100);

  // invert the image
  applyMaskFilter(data, width, height, channels, step, mask);

  // show the image
  cvShowImage("mainWin", img );

  // wait for a key
  cvWaitKey(0);

  // release the image
  cvReleaseImage(&img );
  return 0;
}

/*
void applyMaskFilter(uchar* data, int width, int height, int channels, int step, uchar mask) {
  int i, j, k, index;
  for( i=0; i<height; i++ ) 
    for( j=0; j<width; j++ ) 
      for( k=0; k<channels; k++ ) {
        index = i*step+j*channels+k;
        if (k == 1)
          data[index] = 0;
      }
}
*/

