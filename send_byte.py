import serial
from time import sleep

# Configure the serial port
port = '/dev/ttyUSB0'  # Replace with the appropriate serial port
baudrate = 9600  # Adjust to match the serial port configuration
ser = serial.Serial(port, baudrate)
sleep(3)
print("Woke up...")

with open('gerash.eeprom', 'rb') as file:
    while True:
        # Read a byte
        byte_to_send = file.read(1)

        # Check if the end of the file is reached
        if not byte_to_send:
            break

        ser.write(byte_to_send)
        # Read the received byte
        received_byte = ser.read()

        # Compare the bytes as integers
        if ord(byte_to_send) != ord(received_byte):
            print("False", ord(byte_to_send), ":", ord(received_byte))
            sleep(1)
        sleep(0.5)
# Close the serial port after sending the byte
ser.close()
