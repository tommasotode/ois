import sys, subprocess, os
try: exit(subprocess.run(sys.argv[1]).returncode)
except KeyboardInterrupt: exit(-1073741510)
finally: os.rename("input.txt", sys.argv[2])
