script_content= """
from umachine import Pin
from umachine import Timer


cnt = 0

def mycallback(t):
    global cnt
    cnt = cnt + 1
    if (cnt % 2 != 0):
        print("yellow led off") 
        p1.on()
    else:
        print("yellow led on")
        p1.off()


p1 = Pin(34, Pin.OUT)


tim=Timer(0)
tim.init(period=2000, callback=mycallback)

while True:
  pass
"""

# Save the script to a file
filename = 'main.py'
with open(filename, 'w') as script_file:
    script_file.write(script_content)

print(f"Script saved to '{filename}'")
