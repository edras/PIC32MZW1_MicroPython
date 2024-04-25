from umachine import Timer
from led.led_class import LED

led1 = LED(pin_number=16, on_time_ms=100, off_time_ms=500)
led2 = LED(pin_number=17, on_time_ms=500, off_time_ms=500)
led3 = LED(pin_number=18, on_time_ms=500, off_time_ms=100)

def mycallback(t):
     led1.update()
     led2.update()
     led3.update()

timer=Timer(0)
timer.init(period=1, callback=mycallback)

while True:
     pass

