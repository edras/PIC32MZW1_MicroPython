from umachine import Pin

class LED:
    def __init__(self, pin_number, on_time_ms, off_time_ms):
        self.led = Pin(pin_number, Pin.OUT)
        self.on_time = on_time_ms
        self.off_time = off_time_ms
        self.led.on()  # Start with LED off
        self.last_toggle = 0  # Keep track of last toggle time
        self.state = False  # Initial LED state
        self.current_time = 0 # Initial time
    def update(self):
        self.current_time += 1
        if self.state and self.current_time - self.last_toggle >= self.on_time:
            self.led.on()
            self.state = False
            self.last_toggle = self.current_time
        elif not self.state and self.current_time - self.last_toggle >= self.off_time:
            self.led.off()
            self.state = True
            self.last_toggle = self.current_time