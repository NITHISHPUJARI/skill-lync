cmd_/workspace/chardriver_2/modules.order := {   echo /workspace/chardriver_2/chardrv.ko; :; } | awk '!x[$$0]++' - > /workspace/chardriver_2/modules.order
