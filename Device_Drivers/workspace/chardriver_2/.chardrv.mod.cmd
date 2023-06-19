cmd_/workspace/chardriver_2/chardrv.mod := printf '%s\n'   chardrv.o | awk '!x[$$0]++ { print("/workspace/chardriver_2/"$$0) }' > /workspace/chardriver_2/chardrv.mod
