#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>

static struct proc_dir_entry *FileSystemInfomation;

static int FileSystemTest_init( void )
{
	FileSystemInfomation = proc_symlink( "FsInfo", NULL, "/proc/self/mounts" );
	
	printk( "\r\n" );
	printk( "\r\nWelcome to FileSystem Test Module!\r\n" );
	printk( "Written by Huang Yongshen. No-201520130769. Phone:13570207709.\r\n" );
	printk( "\r\n" );

	printk( "Check it using command \"cat /proc/FsInfo\"\r\n" );
	printk( "\r\n" );

	return 0;
}

static void FileSystemTest_exit( void )
{
	remove_proc_entry( "FsInfo", NULL );

	printk( "\r\nFileSystem Test Module is removed!\r\n" );
}

module_init( FileSystemTest_init );
module_exit( FileSystemTest_exit );

MODULE_AUTHOR( "Huang Yongshen-201520130769-<Phone:13570207709>" );
MODULE_LICENSE( "GPL" );
MODULE_DESCRIPTION( "OS Course Design for File System Module Test" );
MODULE_ALIAS( "OS Course Design for File System Module Test" );



