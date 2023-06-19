cmd_/workspace/usbdriver/endpoints/pen_info.mod := printf '%s\n'   pen_info.o | awk '!x[$$0]++ { print("/workspace/usbdriver/endpoints/"$$0) }' > /workspace/usbdriver/endpoints/pen_info.mod
