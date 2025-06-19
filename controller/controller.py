import socket
import time
import keyboard

ESP32_IP = '[IP ADDRESS GOES HERE]' 
PORT = 0000 #Replace this for port numbers 1024 and above

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# send UDP commands to the ESP32
def send_command(command):
    sock.sendto(command.encode(), (ESP32_IP, PORT))

try:
    while True:
        if keyboard.is_pressed('t'):
            send_command('t')
        elif keyboard.is_pressed('g'):
            send_command('g')
        elif keyboard.is_pressed('f'):
            send_command('f')
        elif keyboard.is_pressed('h'):
            send_command('h')
        elif keyboard.is_pressed('x'):
            send_command('x')
        elif keyboard.is_pressed('b'):
            send_command('b')
        #you can change these

            
        time.sleep(0.05)   
except KeyboardInterrupt:
    print('\nExiting')
finally:
    sock.close()
