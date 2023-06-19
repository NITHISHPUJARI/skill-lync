cmd_/workspace/usbdriver/string/modules.order := {   echo /workspace/usbdriver/string/stri.ko; :; } | awk '!x[$$0]++' - > /workspace/usbdriver/string/modules.order
