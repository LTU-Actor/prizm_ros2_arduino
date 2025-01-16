from serial import Serial
import time

SERIAL_PORT = "/dev/ttyUSB0"
MOTOR_SPEED = -30

ser = Serial(SERIAL_PORT, 115200)


while True:

    for _ in range(500):
        ser.write(bytes(f"left:{MOTOR_SPEED},right:{MOTOR_SPEED};", "ascii"))
        time.sleep(0.01)

    time.sleep(2)

    for _ in range(500):
        ser.write(bytes(f"left:{-1 * MOTOR_SPEED},right:{-1 * MOTOR_SPEED};", "ascii"))
        time.sleep(0.01)

    time.sleep(2)