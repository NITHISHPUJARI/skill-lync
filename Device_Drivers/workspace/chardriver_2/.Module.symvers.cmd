cmd_/workspace/chardriver_2/Module.symvers := sed 's/ko$$/o/' /workspace/chardriver_2/modules.order | scripts/mod/modpost -m -a  -o /workspace/chardriver_2/Module.symvers -e -i Module.symvers   -T -
