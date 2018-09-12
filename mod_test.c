#include <linux/module.h>
#include <linux/init.h>
#include <linux/version.h>
#include <linux/moduleparam.h>
#include <linux/fs.h>
#include <linux/cdev.h>

static int num = 0;
static dev_t dev = -1;
static const char *dev_name = "jool_mod";
struct cdev *jool_cdev = NULL;

static int jool_open(struct inode *inode, struct file *filp)
{
	struct 
	return 0;
}

static int jool_release(struct inode *inode, struct file *filp)
{
	return 0;
}

struct file_operations jool_fops = {
	.owner =	THIS_MODULE,
	.open =		jool_open,
	.release =	jool_release,
};

module_param(num, int, S_IRUGO);

static int __init initialize(void)
{
	if (alloc_chrdev_region(&dev, 0, 1, dev_name)) {
		printk(KERN_ALERT "Failed alloc char device \"%s\" region!\n", dev_name);
		return -1;
	}
	printk(KERN_WARNING "Successfully alloced char device \"%s\" region! %d", dev_name, MAJOR(dev));

//	jool_cdev = cdev_alloc();
//	jool_cdev->ops = jool_fops;

//	cdev.owner = THIS_MODULE;

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

MODULE_LICENSE("GPL");
MODULE_AUTHOR("jool");


