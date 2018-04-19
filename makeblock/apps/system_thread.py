from machine import UART
import time
import _thread

uart0 = UART(0, 115200)  # init with given baudrate
uart1 = UART(2, 115200)  # init with given baudrate

def init_uart():
    uart0.init(115200, bits=8, parity=None, stop=1)    # init with given parameters                     
    uart1.init(115200, bits=8, parity=None, stop=1)    # init with given parameters

def system_protocol_deal_thread():
    while True:
        uart0.write("Hello Yanminge\r\n")
        uart1.write("Hello World\r\n")
        time.sleep(1)

def main():
    _thread.stack_size(1024 * 4)
    _thread.start_new_thread(system_protocol_deal_thread, ())

if __name__ == '__main__':
    main()