#include <linux/unistd.h>
#include <stdlib.h>
#include <stdio.h>

/* define the syscall function */
#define __NR_querypagefaultcounter	320
_syscall0( long, querypagefaultcounter );

int main( int argc, void* argv[] )
{
	long Result;

	printf( "\r\nWelcome To QueryPageFaultCounter Syscall Test Program!\r\n" );
	printf( "Written by Huang Yongshen. No-201520130769. Phone:13570207709.\r\n" );
	printf( "\r\n" );

		
	Result = querypagefaultcounter();
	
	printf( "Page fault has been occured %ld times!\r\n", Result );
	
	printf( "\r\n" );
	
	return 0;
}


