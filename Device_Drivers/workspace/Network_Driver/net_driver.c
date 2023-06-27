#include <linux/module.h>
#include <linux/netdevice.h>

static struct net_device *my_netdev;

static int my_netdev_open(struct net_device *dev)
{
    printk(KERN_INFO "my_netdev: Device opened\n");
    // Additional code for device initialization and configuration can be added here
    return 0;
}

static int my_netdev_close(struct net_device *dev)
{
    printk(KERN_INFO "my_netdev: Device closed\n");
    // Additional code for device cleanup can be added here
    return 0;
}

static const struct net_device_ops my_netdev_ops = {
    .ndo_open = my_netdev_open,
    .ndo_stop = my_netdev_close,
};

static int __init my_netdev_init(void)
{
    my_netdev = alloc_netdev(0, "my_netdev", NET_NAME_UNKNOWN, ether_setup);
    if (!my_netdev) {
        printk(KERN_ERR "my_netdev: Failed to allocate net_device\n");
        return -ENOMEM;
    }

    my_netdev->netdev_ops = &my_netdev_ops;
    register_netdev(my_netdev);

    printk(KERN_INFO "my_netdev: Device registered\n");
    return 0;
}

static void __exit my_netdev_exit(void)
{
    unregister_netdev(my_netdev);
    free_netdev(my_netdev);

    printk(KERN_INFO "my_netdev: Device unregistered\n");
}

module_init(my_netdev_init);
module_exit(my_netdev_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Simple Network Device Driver");
