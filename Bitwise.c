#include <stdint.h>
#include <stdio.h>

struct Packet
{
	uint32_t Crc :       2;
	uint32_t Status :    1;
	uint32_t Payload :   12;
	uint32_t Bat :       3;
	uint32_t Sensor :    3;
	uint32_t Longaddr :  8;
	uint32_t Shortaddr : 2;
	uint32_t Addrmode :  1;
};

int main(void)
{
	uint32_t Packetdata;
	printf("enter the Packet Data \n");
	fflush(stdout);
	scanf("%x",&Packetdata);
	struct Packet frame;
	frame.Crc       = (uint8_t)(Packetdata & 0x3);
	frame.Status    = (uint8_t)((Packetdata >> 2) &0x1);
	frame.Payload   = (uint8_t)((Packetdata >> 3) &0xFFF);
	frame.Bat       = (uint8_t)((Packetdata >> 15) &0x7);
	frame.Sensor    = (uint8_t)((Packetdata >> 18) &0x7);
	frame.Longaddr  = (uint8_t)((Packetdata >> 21) &0xFF);
	frame.Shortaddr = (uint8_t)((Packetdata >> 29) &0x3);
	frame.Addrmode  = (uint8_t)((Packetdata >> 31) &0x1);

	printf("Crc: %x \n",frame.Crc);
	fflush(stdout);
	printf("Status: %x \n",frame.Status);
	fflush(stdout);
	printf("Payload: %x \n",frame.Payload);
	fflush(stdout);
	printf("Bat: %x \n",frame.Bat);
	fflush(stdout);
	printf("Sensor: %x \n",frame.Sensor);
	fflush(stdout);
	printf("Longaddr: %x \n",frame.Longaddr);
	fflush(stdout);
	printf("Shortaddr: %x \n",frame.Shortaddr);
	fflush(stdout);
	printf("Addrmode: %x \n",frame.Addrmode);
	fflush(stdout);
	printf("size of struct is %I64lld \n",sizeof(frame));
}
