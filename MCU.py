import serial
import time

PORT = 'COM7'
BAUD = 9600
FILENAME = r'Z:\Common Data for Line\ICT\Trainee\Kaorad\python\MCU\text\data1.txt'

ser = serial.Serial(PORT, BAUD, timeout=1)
time.sleep(2)

try:
    with open(FILENAME, 'w+') as file:
        for round_num in range(1, 4):  
            print(f"{round_num}")
            file.write(f"--- Round {round_num} ---\n") 

            while True:
                ser.write(b'c')  
                line = ser.readline()
                if line:
                    value = line.decode('utf-8', errors='ignore').strip()
                    print('Read:', value)
                    file.write(value + '\n')
        
                    if "End<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" in value:
                        print(f"พบ End! จบรอบที่ {round_num}\n")
                        file.write("\n")  
                        break
                else:
                    print('No data')

                time.sleep(0.1)

finally:
    ser.close()
    print('Saved to', FILENAME)
