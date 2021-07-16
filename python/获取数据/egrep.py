import sys, re

# sys.argv 是命令行参数的列表 
# sys.argv[0] 是程序自身的名字 "egrep.py"
regex = sys.argv[1]

for line in sys.stdin:
    if re.search(regex, line):
        sys.stdout.write(line)
