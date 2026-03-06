savedcmd_Test.mod := printf '%s\n'   Test.o | awk '!x[$$0]++ { print("./"$$0) }' > Test.mod
