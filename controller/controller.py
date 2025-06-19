import socket
import time
import keyboard

ESP32_IP = '192.168.0.8' 
PORT = 4210

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

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

            
        time.sleep(0.05)   
except KeyboardInterrupt:
    print('\nExiting')
finally:
    sock.close()