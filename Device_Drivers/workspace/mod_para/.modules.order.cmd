cmd_/workspace/mod_para/modules.order := {   echo /workspace/mod_para/hello-5.ko; :; } | awk '!x[$$0]++' - > /workspace/mod_para/modules.order
