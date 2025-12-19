import serial
import time

PORT = 'COM11'
BAUD = 9600
ROUNDS = 3
FILENAME = r'Z:\Common Data for Line\ICT\Trainee\Kaorad\python\MCU\text\data1.txt'

ser = serial.Serial(PORT, BAUD, timeout=2)
time.sleep(2)


def read_block(cmd):
    buffer = []
    ser.write((cmd + '\n').encode())
    time.sleep(0.2)

    while True:
        line = ser.readline()
        if not line:
            continue

        value = line.decode('utf-8', errors='ignore').strip()
        print('Read:', value)
        buffer.append(value)

        if "End<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" in value:
            break
        if value.startswith("End_bc"):
            break

    return buffer

try:

    last_wob_data = []
    last_bc_data = {} 

    for i in range(1, ROUNDS + 1):
        print(f"\nRead WOB round {i}")
        data = read_block('wob')

        if i == ROUNDS:
            last_wob_data = data

    for bc in range(1, 19):
        for i in range(1, ROUNDS + 1):
            print(f"\nRead BC{bc} round {i}")
            data = read_block(f'bc{bc}')

            if i == ROUNDS:
                last_bc_data[f'bc{bc}'] = data

    with open(FILENAME, 'w', encoding='utf-8') as file:
        file.write("===== WOB =====\n")
        file.write("\n".join(last_wob_data))
        file.write("\n\n")

        for bc in range(1, 19):
            key = f'bc{bc}'
            file.write(f"===== {key.upper()} =====\n")
            file.write("\n".join(last_bc_data.get(key, [])))
            file.write("\n\n")

finally:
    ser.close()
    print("\nSaved to", FILENAME)
