#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char *argv[]){
	FILE * fs = fopen(argv[1], "rb");
	FILE * fd = fopen(argv[2], "rb");
	//FILE * fs = fopen("thousand.bin", "rb");
	//FILE * fd = fopen("five-hundred.bin", "rb");
	
	uint32_t buffer1;
	uint32_t buffer2;
	fread(&buffer1, 1, sizeof(uint32_t), fs);
	fread(&buffer2, 1, sizeof(uint32_t), fd);
	//uint32_t* bp1 = reinterpret_cast<uint32_t*>(buffer1);
	//uint32_t* bp2 = reinterpret_cast<uint32_t*>(buffer2);
	
	uint32_t n1 = ntohl(buffer1);
	uint32_t n2 = ntohl(buffer2);
	
	printf("%d(0x%02x) + %d(0x%02x) = %d(0x%02x)\n",n1,n1,n2,n2,n1+n2,n1+n2);
	//printf("%02x\n",n1);
	//printf("%02x\n",n2);



	return 0;
}
