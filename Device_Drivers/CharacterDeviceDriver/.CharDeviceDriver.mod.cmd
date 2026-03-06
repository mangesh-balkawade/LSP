savedcmd_CharDeviceDriver.mod := printf '%s\n'   CharDeviceDriver.o | awk '!x[$$0]++ { print("./"$$0) }' > CharDeviceDriver.mod
