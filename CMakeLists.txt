cmake_minimum_required(VERSION 3.20)
project(EECS3221_Porject_CPU_master)

set(CMAKE_CXX_STANDARD 14)

include_directories(StartKit-Code)

add_executable(EECS3221_Porject_CPU_master
        StartKit-Code/.fcfs.swp
        StartKit-Code/book.txt
        StartKit-Code/CPU.c
        StartKit-Code/cpu.h
        StartKit-Code/CPU.o
        StartKit-Code/driver.c
        StartKit-Code/driver.o
        StartKit-Code/fcfs
        StartKit-Code/list.c
        StartKit-Code/list.h
        StartKit-Code/list.o
        StartKit-Code/Makefile
        StartKit-Code/pri-schedule.txt
        StartKit-Code/rr-schedule.txt
        StartKit-Code/schedule.txt
        StartKit-Code/schedule_fcfs.c
        StartKit-Code/schedule_fcfs.o
        StartKit-Code/schedule_priority.c
        StartKit-Code/schedule_priority_rr.c
        StartKit-Code/schedule_rr.c
        StartKit-Code/schedule_sjf.c
        StartKit-Code/schedulers.h
        StartKit-Code/task.h)
