cmd_/workspace/usbdriver/string/Module.symvers := sed 's/ko$$/o/' /workspace/usbdriver/string/modules.order | scripts/mod/modpost -m -a  -o /workspace/usbdriver/string/Module.symvers -e -i Module.symvers   -T -