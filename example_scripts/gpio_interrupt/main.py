# This test is used to Pin 44 (Mirko bus AN pin) to trigger Pin 14 (Mirko bus CS pin) at rising edge
# To perfrom tests, connect Pin 44 (Mirko bus AN pin) to Pin 14 (Mirko bus CS pin)


from pyb import LED, delay
from umachine import Pin

led_blue = LED(4)
led_yellow = LED(2)

def callback_test(p):
    print("SW IRQ event is triggered ..")
    led_yellow.toggle()

switch = Pin(47, mode=Pin.IN)
switch.irq(handler=callback_test, trigger=Pin.IRQ_RISING)

while True:
    delay(500)
    led_blue.toggle()