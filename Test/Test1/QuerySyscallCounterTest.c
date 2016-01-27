#include <linux/unistd.h>
#include <stdlib.h>
#include <stdio.h>

/* define the syscall function */
#define __NR_querysyscallcounter	318
_syscall1( long, querysyscallcounter, unsigned int, syscall_number );

int StringIsDigit( char* teststring );

int main( int argc, void* argv[] )
{
	unsigned int QueryingNumber;
	long Result;
	int QueryAmount;
	int i;

	printf( "\r\nWelcome To QuerySyscallCounter Syscall Test Program!\r\n" );
	printf( "Written by Huang Yongshen. No-201520130769. Phone:13570207709.\r\n" );
	printf( "\r\n" );
	
	if( argc == 1 )
	{
		printf( "Please input the syscall number you want to query:" );
		scanf( "%d", &QueryingNumber );
		
		Result = querysyscallcounter( QueryingNumber );
		
		if( Result != -1 )
		{
			printf( "No.%d syscall has been called %ld times!\r\n", QueryingNumber, Result );
		}
		else
		{
			printf( "No.%d syscall does not exist!\r\n" );
		}
	}
	else
	{
		for( i = 1; i < argc; ++i )
		{
			if( StringIsDigit( argv[ i ] ) != 0 )
			{
				printf( "The %d argument is not a number!\r\n", i );
				continue;
			}
			
			QueryingNumber = ( unsigned int )atoi( argv[ i ] );
			Result = querysyscallcounter( QueryingNumber );
		
			if( Result != -1 )
			{
				printf( "No.%d syscall has been called %ld times!\r\n", QueryingNumber, Result );
			}
			else
			{
				printf( "No.%d syscall does not exist!\r\n" );
			}
		}
	}
	
	printf( "\r\n" );
	
	return 0;
}

int StringIsDigit( char* teststring )
{
	char *ptr = teststring;
	while( *ptr != '\0' && *ptr != '\r' && *ptr != '\n' )
	{
		if( *ptr < '0' || *ptr > '9' )
		{
			return 1;
		}
		++ptr;
	}
	
	if( ptr == teststring )
	{
		return 1;
	}
	
	return 0;
}
