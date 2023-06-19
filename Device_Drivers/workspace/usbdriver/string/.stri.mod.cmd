cmd_/workspace/usbdriver/string/stri.mod := printf '%s\n'   stri.o | awk '!x[$$0]++ { print("/workspace/usbdriver/string/"$$0) }' > /workspace/usbdriver/string/stri.mod
