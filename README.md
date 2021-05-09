# MCTE 4324 - Real Time Systems

Activities & Challenges from https://www.youtube.com/playlist?list=PLEBQazB0HUyQ4hAPU1cJED6t3DU0h34bz
### Demos
- [x] Part 2 - [Blink](https://github.com/ahmadfaa1z/Real-Time-Systems/blob/main/Intro%20to%20RTOS%20-%20Exercises/2%20Blink_LED/Blink_demo/Blink_demo.ino)
- [x] Part 3 - [Task Schedulling](https://github.com/ahmadfaa1z/Real-Time-Systems/blob/main/Intro%20to%20RTOS%20-%20Exercises/3%20Task_Schedulling/Task_Schedulling_demo/Task_Schedulling_demo.ino)
- [x] Part 4 - [Memory, static, stack, heap](https://github.com/ahmadfaa1z/Real-Time-Systems/blob/main/Intro%20to%20RTOS%20-%20Exercises/4%20Memory%20Allocation/stack_overflow_demo/stack_overflow_demo.ino)
- [x] Part 5 - [Queue](https://github.com/ahmadfaa1z/Real-Time-Systems/blob/main/Intro%20to%20RTOS%20-%20Exercises/5%20Queue/Queue_demo/Queue_demo.ino), [Queue_full](https://github.com/ahmadfaa1z/Real-Time-Systems/blob/main/Intro%20to%20RTOS%20-%20Exercises/5%20Queue/Queue_full_demo/Queue_full_demo.ino), atomic operation, kernel objects...
- [x] Part 6 - [Mutex](https://github.com/ahmadfaa1z/Real-Time-Systems/blob/main/Intro%20to%20RTOS%20-%20Exercises/6%20Mutex/Mutex_demo/Mutex_demo.ino), [race condition](https://github.com/ahmadfaa1z/Real-Time-Systems/blob/main/Intro%20to%20RTOS%20-%20Exercises/6%20Mutex/race_condition_demo/race_condition_demo.ino), shared resources, restroom key analogy
- [x] Part 7 - Semaphores, [binary semaphores](https://github.com/ahmadfaa1z/Real-Time-Systems/blob/main/Intro%20to%20RTOS%20-%20Exercises/7%20Semaphore/Binary_Semaphore_demo/Binary_Semaphore_demo.ino), [counting semaphores](https://github.com/ahmadfaa1z/Real-Time-Systems/blob/main/Intro%20to%20RTOS%20-%20Exercises/7%20Semaphore/Counting_Sempahore_demo/Counting_Sempahore_demo.ino)
- [x] Part 8 - Software Timers, [one-shot timer, auto-reload timer](https://github.com/ahmadfaa1z/Real-Time-Systems/blob/main/Intro%20to%20RTOS%20-%20Exercises/8%20Software%20Timers/Software_Timer_demo/Software_Timer_demo.ino)
- [ ] Part 9 - Hardware Interrupts, 
- [ ] Part 10
- [ ] Part 11
- [ ] Part 12

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
- [x] Part 7 - Writing (0-4) three times with Producer-Consumer design
  - [Solution using Counting Semaphores](https://github.com/ahmadfaa1z/Real-Time-Systems/blob/main/Intro%20to%20RTOS%20-%20Exercises/7%20Semaphore/Sempahore_challenge_counting_sempahore/Sempahore_challenge_counting_sempahore.ino)
  - [Solution using Queue](https://github.com/ahmadfaa1z/Real-Time-Systems/blob/main/Intro%20to%20RTOS%20-%20Exercises/7%20Semaphore/Semaphore_challenge_queue/Semaphore_challenge_queue.ino)
- [x] Part 8 - Turn on LED when entering serial commands and off if serial is inactive, [Code link](https://github.com/ahmadfaa1z/Real-Time-Systems/blob/main/Intro%20to%20RTOS%20-%20Exercises/8%20Software%20Timers/LED_dim_delay_serial_input/LED_dim_delay_serial_input.ino)
- [ ] Part 9
- [ ] Part 10
- [ ] Part 11
- [ ] Part 12

### GPS NEO 6M
<details>
  <summary>Circuit overview</summary>

![m_ESP32 + GPS NEO](https://user-images.githubusercontent.com/39882376/117571244-517a0680-b100-11eb-980e-040dcbdac5ce.jpg)

</details> 

<details>
  <summary>Serial Output View</summary>

![Serial Output](https://user-images.githubusercontent.com/39882376/117542546-ab6cc480-b04b-11eb-8828-c6c979e56253.gif)

</details> 

### OTHER ESP32 PROJECTS
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
