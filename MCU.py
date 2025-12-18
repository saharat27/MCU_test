import serial
import time

PORT = 'COM3'
BAUD = 115200
ROUNDS = 3
FILENAME = r'C:\Users\VICTUS\Downloads\MCU\data\data1.txt'

ser = serial.Serial(PORT, BAUD, timeout=1)
time.sleep(2)

def read_block(cmd):
    buffer = []
    ser.write(cmd.encode())
    time.sleep(0.1)

    while True:
        line = ser.readline()
        if line:
            value = line.decode('utf-8', errors='ignore').strip()
            print('Read:', value)
            buffer.append(value)

            if "End<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" in value:
                break
    return buffer


try:
    last_c_data = []
    last_d_data = []


    for i in range(1, ROUNDS + 1):
        print(f"\nread c round {i}")
        data = read_block('c')
        if i == ROUNDS:
            last_c_data = data  


    for i in range(1, ROUNDS + 1):
        print(f"\nread d round{i}")
        data = read_block('d')
        if i == ROUNDS:
            last_d_data = data  


    with open(FILENAME, 'w', encoding='utf-8') as file:
        file.write("===== LAST ROUND : C =====\n")
        file.write("\n".join(last_c_data))
        file.write("\n\n===== LAST ROUND : D =====\n")
        file.write("\n".join(last_d_data))

finally:
    ser.close()
    print("\nSaved to", FILENAME)
