cmd_/workspace/mod_para/hello-5.mod := printf '%s\n'   hello-5.o | awk '!x[$$0]++ { print("/workspace/mod_para/"$$0) }' > /workspace/mod_para/hello-5.mod
