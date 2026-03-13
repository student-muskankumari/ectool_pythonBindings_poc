import coolctl
import time

print("Initial fan level:", coolctl.read_fan_level())

coolctl.update_fan_level(75)

print("Updated fan level:", coolctl.read_fan_level())

while True:
    level = coolctl.read_fan_level()
    print("Fan level:", level)
    time.sleep(2)
