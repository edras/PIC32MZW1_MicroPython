from umachine import Pin
from umachine import Timer

def mycallback(t):
    if p1.value() == 1:
        print("yellow led on") 
        p1.off()
    else:
        print("yellow led off")
        p1.on()


p1 = Pin(16, Pin.OUT)
timer=Timer(0)
timer.init(period=2000, callback=mycallback)

while True:
    pass