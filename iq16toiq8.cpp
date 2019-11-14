#include <cstdio>
#include <cstdint>
#include <iostream>

using namespace std;


int main(int argc, char *argv[]){

if (argc <= 1)
    {
	cout << "Convert iq16 (LimeSDR) to iq8 (HackRF)" << endl;
	cout << "Usage: iq16toiq8 infile.iq16 outfile.iq" << endl;
	cout << "Big green ugly code." <<endl;
	exit(1);
    }


FILE *fp0;
FILE *fp1;

short int i16;
short int q16;
uint8_t  i8;
uint8_t  q8;

cout << "Convertation start" << endl;

fp0=fopen(argv[1],"rb");
fp1=fopen(argv[2],"wb");

    while (!feof(fp0)){

	fread(&i16, sizeof(short int), 1, fp0);
	fread(&q16, sizeof(short int), 1, fp0);

	i8=uint8_t((i16/256));
	q8=uint8_t((q16/256));

	fwrite(&i8, sizeof(uint8_t), 1, fp1);
	fwrite(&q8, sizeof(uint8_t), 1, fp1);

}

fclose(fp1);
fclose(fp0);

cout << "Convertation finished" << endl;

}
