cmd_/workspace/usbdriver/modules.order := {   echo /workspace/usbdriver/usbdev.ko; :; } | awk '!x[$$0]++' - > /workspace/usbdriver/modules.order
