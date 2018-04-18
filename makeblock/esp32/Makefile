#Basic configuration information

ESPIDF = /g/esp32_firefly_bak/esp-idf
PORT = COM3
FLASH_MODE = dio
BAUD = 921600
BUILD = build

mpy_cross_exe_file := ../../micropython/mpy-cross/mpy-cross.exe
mpy_cross_exe_file_path := ../../micropython/mpy-cross/mpy-cross.exe

all: copy_micropython copy_esp_idf compile_mpy_cross

#Copy and replace micropython's code
copy_micropython:
	cp ../micropython/after/lib/berkeley-db-1.xx/PORT/include/db.h ../../micropython/lib/berkeley-db-1.xx/PORT/include/db.h
	cp ../micropython/after/lib/berkeley-db-1.xx/PORT/include/mpool.h ../../micropython/lib/berkeley-db-1.xx/PORT/include/mpool.h
	cp ../micropython/after/lib/berkeley-db-1.xx/PORT/include/filevtable.h ../../micropython/lib/berkeley-db-1.xx/PORT/include/filevtable.h
	cp ../micropython/after/lib/berkeley-db-1.xx/PORT/include/bsd-queue.h ../../micropython/lib/berkeley-db-1.xx/PORT/include/bsd-queue.h
#Copy and replace esp-idf's code
copy_esp_idf:

#Check if mpy-cross is compiled, compile it if it has not yet been compiled
compile_mpy_cross:
ifeq ($(mpy_cross_exe_file), $(wildcard $(mpy_cross_exe_file_path)))
	@echo  mpy_cross has been compiled
else
	@echo  mpy_cross has not been compiled
endif

clean: clean_micropython clean_esp_idf clean_mpy_cross

#Clean and replace micropython's code
clean_micropython:
	cp ../micropython/before/lib/berkeley-db-1.xx/PORT/include/db.h ../../micropython/lib/berkeley-db-1.xx/PORT/include/db.h
	cp ../micropython/before/lib/berkeley-db-1.xx/PORT/include/mpool.h ../../micropython/lib/berkeley-db-1.xx/PORT/include/mpool.h
	cp ../micropython/before/lib/berkeley-db-1.xx/PORT/include/filevtable.h ../../micropython/lib/berkeley-db-1.xx/PORT/include/filevtable.h
	cp ../micropython/before/lib/berkeley-db-1.xx/PORT/include/bsd-queue.h ../../micropython/lib/berkeley-db-1.xx/PORT/include/bsd-queue.h

#Clean and replace esp-idf's code
clean_esp_idf:

#Check if mpy-cross is compiled, clean it if it has yet been compiled
clean_mpy_cross:
ifeq ($(mpy_cross_exe_file), $(wildcard $(mpy_cross_exe_file_path)))
	@echo  mpy_cross has been compiled
	rm -r ../../micropython/mpy-cross/mpy-cross.exe
	rm -r ../../micropython/mpy-cross/mpy-cross.map
	rm -rf ../../micropython/mpy-cross/build
else
	echo mpy_cross has not been compiled
endif
include GNUMakefile