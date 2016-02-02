#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>

static struct proc_dir_entry *Hello_folder;
static struct proc_dir_entry *World_file;
static char HelloWorldBuffer[ 20 ] = { "Hello World\n\0" };

static int Read_HelloWorld( char *page, char **start, off_t off, int count, int *eof, void *data )
{
	if( off > 0 )
	{
		return 0;
	}

	*start = HelloWorldBuffer;
	return 12;
}

static int hello_init( void )
{
	Hello_folder = proc_mkdir( "hello", NULL );
	if( Hello_folder == NULL )
	{
		printk( "Create folder hello in /proc failed!\r\n" );
		return -1;
	}

	World_file = create_proc_read_entry( "world", 0644, Hello_folder, Read_HelloWorld, NULL );
	if( World_file == NULL )
	{
		printk( "Create file world in /proc/hello failed!\r\n" );
		remove_proc_entry( "hello", NULL );
		return -1;
	}
	
	printk( "\r\n" );
	printk( "\r\nWelcome to Procfs Test Module!\r\n" );
	printk( "Written by Huang Yongshen. No-201520130769. Phone:13570207709.\r\n" );
	printk( "\r\n" );
	printk( "Hello World is mounted in /proc.\r\n" );
	printk( "Check it using command \"cat /proc/hello/world\"\r\n" );
	printk( "\r\n" );
	return 0;
}

static void hello_exit( void )
{
	remove_proc_entry( "world", Hello_folder );
	remove_proc_entry( "hello", NULL );
	printk( "Procfs Test Module is removed!\r\n" );
}

module_init( hello_init );
module_exit( hello_exit );

MODULE_AUTHOR( "Huang Yongshen-201520130769-<Phone:13570207709>" );
MODULE_LICENSE( "GPL" );
MODULE_DESCRIPTION( "OS Course Design for Procfs Module Test" );
MODULE_ALIAS( "OS Course Design for Procfs Module Test" );



