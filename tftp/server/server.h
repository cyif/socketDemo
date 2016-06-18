#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h> // for open flags
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <signal.h>


#define DEBUG_PRINTS 0 // For debugging.


#define DEFAULT_PORT "6900"
#define MAX_DATA_SIZE 512
#define MODE "octet"
#define RRQ 1
#define WRQ 2
#define DATA 3
#define ACK 4
#define ERROR 5
//error types macros

#define OTHER 0
#define FILE_NOT_FOUND 1
#define ACCESS_VIOLATION 2
#define FULL_DISK 3
#define ILLEGAL_OPERATION 4
#define FILE_EXIST 6

#pragma pack(push, 1)
typedef struct {
	u_short opcode;
	u_short block_num;
	char data[MAX_DATA_SIZE];
}data_packet;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct {
	u_short opcode;
	char file_name[FILENAME_MAX];
	char zero_byte;
	char mode[5];
	char zero_byte_2;
}rw_packet;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct {
	u_short opcode;
	u_short block_num;
}ack_packet;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct {
	u_short opcode;
	u_short err_code;
	char err_msg[MAX_DATA_SIZE];
	char zero_byte;
}error_packet;
#pragma pack(pop)
