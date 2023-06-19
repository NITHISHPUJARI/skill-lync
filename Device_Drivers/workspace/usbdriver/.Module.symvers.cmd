cmd_/workspace/usbdriver/Module.symvers := sed 's/ko$$/o/' /workspace/usbdriver/modules.order | scripts/mod/modpost -m -a  -o /workspace/usbdriver/Module.symvers -e -i Module.symvers   -T -
