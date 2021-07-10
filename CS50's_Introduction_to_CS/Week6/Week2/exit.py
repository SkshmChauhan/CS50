import sys

if len(sys.argv) != 2:
    print("missing command-line argument")
    sys.exit(1)
# Exits with explicit value, importing sys
print(f"hello, {sys.argv[1]}")
sys.exit(0)
