#include <cstdio>
#include <cstdint>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){

if (argc <= 1)
    {
	cout << "Convert iq8 (HackRF) to iq16 (LimeSDR)" << endl;
	cout << "Usage: iq8toiq16 infile.iq outfile.iq16" << endl;
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

	fread(&i8, sizeof(uint8_t), 1, fp0);
	fread(&q8, sizeof(uint8_t), 1, fp0);

	i16=short((i8*256));
	q16=short((q8*256));

	fwrite(&i16, sizeof(short), 1, fp1);
	fwrite(&q16, sizeof(short), 1, fp1);

}

fclose(fp1);
fclose(fp0);

cout << "Convertation finished" << endl;

}
