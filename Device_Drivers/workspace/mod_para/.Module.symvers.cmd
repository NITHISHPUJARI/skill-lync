cmd_/workspace/mod_para/Module.symvers := sed 's/ko$$/o/' /workspace/mod_para/modules.order | scripts/mod/modpost -m -a  -o /workspace/mod_para/Module.symvers -e -i Module.symvers   -T -
