#include <linux/unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define __NR_resetpagefaultcounter	321
_syscall0( long, resetpagefaultcounter );

int main( int argc, void* argv[] )
{

	printf( "\r\nWelcome To ResetPageFaultCounter Syscall Test Program!\r\n" );
	printf( "Written by Huang Yongshen. No-201520130769. Phone:13570207709.\r\n" );
	printf( "\r\n" );
	printf( "Reseting the Page Fault Counter...Please wait a moument...\r\n" );
	
	if( resetpagefaultcounter() == 0 )
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

