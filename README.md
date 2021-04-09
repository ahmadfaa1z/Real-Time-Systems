# MCTE 4324 - Real Time Systems

Activities & Challenges from https://www.youtube.com/playlist?list=PLEBQazB0HUyQ4hAPU1cJED6t3DU0h34bz
### Demos
- [x] Part 2 - [Blink](https://github.com/ahmadfaa1z/Real-Time-Systems/blob/main/Intro%20to%20RTOS%20-%20Exercises/2%20Blink_LED/Blink_demo/Blink_demo.ino)
- [x] Part 3 - [Task Schedulling](https://github.com/ahmadfaa1z/Real-Time-Systems/blob/main/Intro%20to%20RTOS%20-%20Exercises/3%20Task_Schedulling/Task_Schedulling_demo/Task_Schedulling_demo.ino)
- [x] Part 4 - [Memory, static, stack, heap](https://github.com/ahmadfaa1z/Real-Time-Systems/blob/main/Intro%20to%20RTOS%20-%20Exercises/4%20Memory%20Allocation/stack_overflow_demo/stack_overflow_demo.ino)
- [x] Part 5 - [Queue](https://github.com/ahmadfaa1z/Real-Time-Systems/blob/main/Intro%20to%20RTOS%20-%20Exercises/5%20Queue/Queue_demo/Queue_demo.ino), [Queue_full](https://github.com/ahmadfaa1z/Real-Time-Systems/blob/main/Intro%20to%20RTOS%20-%20Exercises/5%20Queue/Queue_full_demo/Queue_full_demo.ino), atomic operation, kernel objects...
- [x] Part 6 - [Mutex](https://github.com/ahmadfaa1z/Real-Time-Systems/blob/main/Intro%20to%20RTOS%20-%20Exercises/6%20Mutex/Mutex_demo/Mutex_demo.ino), [race condition](https://github.com/ahmadfaa1z/Real-Time-Systems/blob/main/Intro%20to%20RTOS%20-%20Exercises/6%20Mutex/race_condition_demo/race_condition_demo.ino), shared resources, bathroom key analogy
- [ ] Part 7
- [ ] Part 8

### Challenges
- [x] Part 2 - [Blink LED at different rates](https://github.com/ahmadfaa1z/Real-Time-Systems/blob/main/Intro%20to%20RTOS%20-%20Exercises/2%20Blink_LED/Blink_diff_rates/Blink_diff_rates.ino)
- [x] Part 3 - [Blink LED at given rate (from serial)](https://github.com/ahmadfaa1z/Real-Time-Systems/blob/main/Intro%20to%20RTOS%20-%20Exercises/3%20Task_Schedulling/Read_from_serial_to_blinkLED/Read_from_serial_to_blinkLED.ino)
- [x] Part 4 - [Send and receive message using heap memory (with LED notification)](https://github.com/ahmadfaa1z/Real-Time-Systems/blob/main/Intro%20to%20RTOS%20-%20Exercises/4%20Memory%20Allocation/Send_and_receive_using_memory/Send_and_receive_using_memory.ino)
- [x] Part 5 - [Applying two queues (send & receive messages) + struct](https://github.com/ahmadfaa1z/Real-Time-Systems/blob/main/Intro%20to%20RTOS%20-%20Exercises/5%20Queue/Two_queues_challenge/Two_queues_challenge.ino)
- [ ] Part 6
- [ ] Part 7
- [ ] Part 8

### MINI PROJECT
#### 1 Sequential LED
  - Arduino UNO
    - In this [code](), the arduino was only able to run one task at a time. When attempting to press two buttons, the first task needs to finish before any buttons can be read again.
    - *There are probably workarounds in Arduino to be able to multitask.*
https://user-images.githubusercontent.com/39882376/114168857-66c60e80-9963-11eb-8fa3-61fc3be661ed.mp4

- ESP32
  - Using [ESP32](), while a task is running, we can also run other tasks. ESP32 shows ability to multitask.
  - Sequential LED (Running one task at a time)
https://user-images.githubusercontent.com/39882376/114169003-99700700-9963-11eb-9d4e-5474eceb0073.mp4
  - Sequential LED (Running multiple sequence tasks)
https://user-images.githubusercontent.com/39882376/114169033-a260d880-9963-11eb-8c75-fd894c7241a3.mp4

---
![Blink](https://user-images.githubusercontent.com/39882376/111452481-88a9e800-874d-11eb-82bc-adde84f4ccc6.gif)
