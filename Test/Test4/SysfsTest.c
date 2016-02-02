#include <linux/init.h>
#include <linux/module.h>
#include <linux/kobject.h>
#include <linux/device.h>
#include <linux/sysfs.h>
#include <linux/string.h>

decl_subsys( hello, NULL, NULL );
EXPORT_SYMBOL_GPL( hello_subsys );

static char Hello_Buffer[] = { "Hello world\n" };

static ssize_t hello_show( struct subsystem *subsys, char *buffer )
{
	strcpy( buffer, Hello_Buffer );
	return strlen( buffer );
}

static struct subsys_attribute hello_attr = __ATTR( world, 0444, hello_show, NULL );

static int hello_init( void )
{

	if( subsystem_register( &hello_subsys ) != 0 )
	{
		printk( "Subsystem_register for hello_subsys error!\n" );
		return -1;
	}

	if( subsys_create_file( &hello_subsys, &hello_attr ) != 0 )
	{
		subsystem_unregister( &hello_subsys );	
		printk( "Sysfs_create_file for World error!\n" );
		return -1;
	}

	printk( "\r\n" );
	printk( "\r\nWelcome to Sysfs Test Module!\r\n" );
	printk( "Written by Huang Yongshen. No-201520130769. Phone:13570207709.\r\n" );
	printk( "\r\n" );
	printk( "Hello World is mounted in /sys.\r\n" );
	printk( "Check it using command \"cat /sys/hello/world\"\r\n" );
	
	return 0;
}

static void hello_exit( void )
{
	sysfs_remove_file( &( hello_subsys.kset.kobj ), ( const struct attribute * )&( hello_attr.attr ) );
	subsystem_unregister( &hello_subsys );	
	printk( "\r\nSysfs Test Module is removed!\r\n" );
}

module_init( hello_init );
module_exit( hello_exit );

MODULE_AUTHOR( "Huang Yongshen-201520130769-<Phone:13570207709>" );
MODULE_LICENSE( "GPL" );
MODULE_DESCRIPTION( "OS Course Design for Sysfs Module Test" );
MODULE_ALIAS( "OS Course Design for Sysfs Module Test" );



