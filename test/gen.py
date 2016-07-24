import sys

for line in sys.stdin:
    line = line.strip()
    sys.stdout.write(line)
    sys.stdout.write(chr(1))
