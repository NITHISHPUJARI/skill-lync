#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>

static struct usb_device_id my_usb_device_table[] = {
    { USB_DEVICE(0x22d9, 0x2046) }, // Replace with your USB device's Vendor ID and Product ID
    {} // Terminating entry
};
MODULE_DEVICE_TABLE(usb, my_usb_device_table);

static int my_usb_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
    struct usb_device *dev = interface_to_usbdev(interface);

    // Print device information
    printk(KERN_INFO "USB Device: Vendor ID = 0x%X, Product ID = 0x%X\n", dev->descriptor.idVendor, dev->descriptor.idProduct);

    // Add your device handling code here

    return 0; // Return 0 to indicate successful probing
}

static void my_usb_disconnect(struct usb_interface *interface)
{
    // Add cleanup code here if necessary

    printk(KERN_INFO "USB Device Disconnected\n");
}

static struct usb_driver my_usb_driver = {
    .name = "my_usb_driver",
    .id_table = my_usb_device_table,
    .probe = my_usb_probe,
    .disconnect = my_usb_disconnect,
};

static int __init my_usb_init(void)
{
    int result;

    // Register the USB driver
    result = usb_register(&my_usb_driver);
    if (result < 0) {
        printk(KERN_ERR "Failed to register USB driver: %d\n", result);
        return result;
    }

    printk(KERN_INFO "USB Device Driver Registered\n");

    return 0;
}

static void __exit my_usb_exit(void)
{
    // Unregister the USB driver
    usb_deregister(&my_usb_driver);

    printk(KERN_INFO "USB Device Driver Unregistered\n");
}

module_init(my_usb_init);
module_exit(my_usb_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("USB Device Driver Example");

