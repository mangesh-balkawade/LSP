savedcmd_MarvellousDriver.mod := printf '%s\n'   MarvellousDriver.o | awk '!x[$$0]++ { print("./"$$0) }' > MarvellousDriver.mod
