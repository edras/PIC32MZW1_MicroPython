from umachine import I2C

i2c = I2C(1, freq=100000)

# light sensor address = 68
# light sensor registers (16 bit)
# 0 - result
# 1 - configuration
# 2 - low limit
# 3 - high limit
# 126 - manufacturer
# 127 - device id

# read light sensor manufacturer
manufacturer = i2c.readfrom_mem(68, 126, 2)
print("light manufacturer:", manufacturer)

# temperature sensor address = 24
# temp sensor registers (16 bit)
# 0 - reserved
# 1 - configuration
# 2 - alert upper temp
# 3 - alert lower temp
# 4 - critical temp
# 5 - temperature [ >TCRIT >TUP <tLW SIGN T7 T6 T5 T4 T3 T2 T1 T0 . T-1 T-2 T-3 T-4 ]
# 6 - manufacturer ID
# 7 - device ID
# 8 - Resolution register

manufacturer = i2c.readfrom_mem(24, 6, 2)
print("temp manufacturer:", hex(manufacturer[1]))
temp = i2c.readfrom_mem(24, 5, 2)
temp[1]

