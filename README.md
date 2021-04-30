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
<details>
<summary>Blink One LED with two different rates</summary>
  
  ![Blink one LED with two different rates](https://user-images.githubusercontent.com/39882376/111452481-88a9e800-874d-11eb-82bc-adde84f4ccc6.gif)

</details>

<details>
  <summary>Blink two LEDs, each with different rates</summary>
  
  ![Blink two LEDs](https://user-images.githubusercontent.com/39882376/114172966-f7ebb400-9968-11eb-807f-2d482238b881.gif)

</details> 

- [x] Part 3 - [Blink LED at given rate (from serial)](https://github.com/ahmadfaa1z/Real-Time-Systems/blob/main/Intro%20to%20RTOS%20-%20Exercises/3%20Task_Schedulling/Read_from_serial_to_blinkLED/Read_from_serial_to_blinkLED.ino)
- [x] Part 4 - [Send and receive message using heap memory (with LED notification)](https://github.com/ahmadfaa1z/Real-Time-Systems/blob/main/Intro%20to%20RTOS%20-%20Exercises/4%20Memory%20Allocation/Send_and_receive_using_memory/Send_and_receive_using_memory.ino)
- [x] Part 5 - [Applying two queues (send & receive messages) + struct](https://github.com/ahmadfaa1z/Real-Time-Systems/blob/main/Intro%20to%20RTOS%20-%20Exercises/5%20Queue/Two_queues_challenge/Two_queues_challenge.ino)
- [x] Part 6 - [Passing parameters through task creation](https://github.com/ahmadfaa1z/Real-Time-Systems/blob/main/Intro%20to%20RTOS%20-%20Exercises/6%20Mutex/Passing_Task_parameters/Passing_Task_parameters.ino)
- [ ] Part 7
- [ ] Part 8

### MINI PROJECTS
#### 1 Sequential LED
  - Arduino UNO
    - In this [code](https://github.com/ahmadfaa1z/Real-Time-Systems/blob/main/ESP32%20Applications/3_Diff_Sequential_LED/3_Diff_Sequential_LED.ino), the arduino was only able to run one task at a time. When attempting to press two buttons, the first task needs to finish before any buttons can be read again.
    - *There are probably workarounds in Arduino to be able to multitask.*
    - [Video of Sequential LED using Arduino](https://youtu.be/2j2qaQt21xA)

- ESP32
  - Using [ESP32](https://github.com/ahmadfaa1z/Real-Time-Systems/blob/main/ESP32%20Applications/Run_Multiple_Sequence_ESP32/Run_Multiple_Sequence_ESP32.ino), while a task is running, we can also run other tasks. This shows the ability to multitask with ESP32.
  - [Video of ESP32 (Running one task at a time)](https://youtu.be/n27mR-tzbkM)
  - [Video of ESP32 (Running multiple sequence tasks)](https://youtu.be/2B5idacvKn0)

#### 2 ...
