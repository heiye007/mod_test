#include <linux/module.h>
#include <linux/init.h>
#include <linux/version.h>
#include <linux/moduleparam.h>
#include <linux/fs.h>

MODULE_LICENSE("LGPL");

static int num = 0;
static dev_t dev = -1;
static const char *dev_name = "jool_mod";

module_param(num, int, S_IRUGO);

static int __init initialize(void)
{
	if (alloc_chrdev_region(&dev, 0, 1, dev_name)) {
		printk(KERN_ALERT "Failed alloc char device \"%s\" region!\n", dev_name);
		return -1;
	}
	printk(KERN_ALERT "Successfully alloced char device \"%s\" region! %d\n", dev_name, dev);
	return 0;
}

static void __exit shutdown(void) {
	printk(KERN_ALERT "Bye!");
	if (dev != -1) {
		unregister_chrdev_region(dev, 1);
	}
}

module_init(initialize);
module_exit(shutdown);


