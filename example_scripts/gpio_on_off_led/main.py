from pyb import LED, delay

leds = [LED(1), LED(2), LED(3), LED(4)]

while True:
  for i in range(4):
    leds[i].toggle()
    delay(150)
