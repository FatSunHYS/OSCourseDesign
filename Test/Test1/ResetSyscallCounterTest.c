#include <linux/unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define __NR_resetsyscallcounter	319
_syscall0( long, resetsyscallcounter );

int main( int argc, void* argv[] )
{

	printf( "\r\nWelcome To QuerySyscallCounter Syscall Test Program!\r\n" );
	printf( "Written by Huang Yongshen. No-201520130769. Phone:13570207709.\r\n" );
	printf( "\r\n" );
	printf( "Reseting the Syscall Counter...Please wait a moument...\r\n" );
	
	if( resetsyscallcounter() == 0 )
	{
		printf( "Reset counter successfully!\r\n" );
	}
	else
	{
		printf( "Reset counter failed!\r\n" );
	}

	printf( "\r\n" );

	return 0;
}

