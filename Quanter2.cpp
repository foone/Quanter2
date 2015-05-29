#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//#include <magick/api.h>
#include <Magick++.h>
using namespace Magick;

int main(int argc, char *argv[]){
	if(argc!=5){
		printf("Usage: Quanter2 <infile> <outfile> <palettefile> <dither>\n");
		return 1;
	}
	std::string infile=argv[1];
	std::string outfile=argv[2];
	std::string palettefile=argv[3];
	bool dither=true;
	if(strcmp(argv[4],"off")==0){
		dither=false;
	}
	Image image;
	Image palette;
	try {
    image.read( infile );
		palette.read(palettefile);
		image.compressType(NoCompression);
    image.map(palette,dither!=0);
		image.write( outfile );
		return 0;
  }
  catch( Exception &error )
    {
			printf("Error converting: %s\n",error.what());
      return 2;
    }
	return 3;
}