cmd_/workspace/usbdriver/usbdev.mod := printf '%s\n'   usbdev.o | awk '!x[$$0]++ { print("/workspace/usbdriver/"$$0) }' > /workspace/usbdriver/usbdev.mod
