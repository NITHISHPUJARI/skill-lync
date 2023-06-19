#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>
 
static struct usb_device *device;
 
static int pen_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
    char buff[15];
    
    device = interface_to_usbdev(interface);
    pr_info("pen probe function");
    usb_string(device,1,buff,15);
    pr_info("string 1 is %s",buff);
    return 0;
}
 
static void pen_disconnect(struct usb_interface *interface)
{
    printk(KERN_INFO "Pen i/f %d now disconnected\n",
            interface->cur_altsetting->desc.bInterfaceNumber);
}
 
static struct usb_device_id pen_table[] =
{
    { USB_DEVICE(0x0781, 0x5590) },
    {} /* Terminating entry */
};
MODULE_DEVICE_TABLE (usb, pen_table);
 
static struct usb_driver pen_driver =
{
    .name = "pen_driver",
    .probe = pen_probe,
    .disconnect = pen_disconnect,
    .id_table = pen_table,
};
 
static int __init pen_init(void)
{
    return usb_register(&pen_driver);
}
 
static void __exit pen_exit(void)
{
    usb_deregister(&pen_driver);
}
 
module_init(pen_init);
module_exit(pen_exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Anil Kumar Pugalia <email@sarika-pugs.com>");
MODULE_DESCRIPTION("USB Pen Info Driver");
