cmd_/workspace/usbdriver/endpoints/modules.order := {   echo /workspace/usbdriver/endpoints/pen_info.ko; :; } | awk '!x[$$0]++' - > /workspace/usbdriver/endpoints/modules.order
