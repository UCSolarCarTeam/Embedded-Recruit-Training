# FreeRTOS

## What is FreeRTOS?

FreeRTOS is an open-source, real-time operating system (RTOS) for embedded systems. It allows you to manage tasks, memory, and hardware efficiently, making it ideal for time-critical applications. Key features include:

- Multitasking: Supports concurrent tasks with priority-based scheduling.
- Task Scheduling: Preemptive scheduler ensures high-priority tasks run when needed.
- Inter-task Communication: Uses queues, semaphores, and mutexes to synchronize tasks.
- Deterministic: Provides predictable execution for real-time applications.
- Portability: Runs on various microcontrollers like STM32.

FreeRTOS is widely used in IoT, automation, and embedded systems due to its lightweight and efficient design.

## What is CMSIS RTOS v2?

CMSIS RTOS v2 is a standardized RTOS API developed by ARM, often used with FreeRTOS. It provides a common interface for real-time applications on ARM Cortex-M microcontrollers like STM32. Key points:

- Standardized API: Allows easy switching between different RTOS kernels without changing code.
- ARM Ecosystem Integration: Works seamlessly with STM32 and other ARM-based microcontrollers.
- Built on FreeRTOS: Provides a unified interface with the flexibility of FreeRTOS.

CMSIS RTOS v2 simplifies real-time task management and is commonly used in embedded systems with STM32.

## Important Functions 

`osThreadId_t osThreadNew (osThreadFunc_t func, void *argument, const osThreadAttr_t *attr)`
Function: Creates a new thread (task).
Explanation: This function is used to create and initialize a thread (task) with specific attributes like priority, stack size, and a function to execute. It allows for multitasking by running multiple threads concurrently.
Usage: Similar to xTaskCreate() in FreeRTOS, used to define the behavior of tasks in your embedded system.

`osStatus_t osDelay (uint32_t millisec)`
Function: Delays a thread for a given time period.
Explanation: This function suspends the calling thread for a specified number of milliseconds, allowing other threads to run during the delay. It's useful for implementing time-based operations.
Usage: Commonly used to introduce a wait time between thread executions or manage periodic tasks.

`osMutexId_t osMutexNew (const osMutexAttr_t *attr)`
Function: Creates a new mutex.
Explanation: A mutex (mutual exclusion) is used to protect shared resources from simultaneous access by multiple threads. osMutexNew() creates a mutex that threads can lock and unlock.
Usage: Essential for preventing data corruption when multiple threads need to access shared variables or hardware peripherals.

`osSemaphoreId_t osSemaphoreNew (uint32_t max_count, uint32_t initial_count, const osSemaphoreAttr_t *attr)`
Function: Creates a semaphore.
Explanation: Semaphores are synchronization tools used to signal between threads or manage access to limited resources. osSemaphoreNew() creates a counting semaphore that threads can acquire and release.
Usage: Useful in resource-limited situations where a fixed number of resources are available (e.g., a limited number of hardware peripherals).

`osMessageQueueId_t osMessageQueueNew (uint32_t msg_count, uint32_t msg_size, const osMessageQueueAttr_t *attr);`
Function: Creates a message queue.
Explanation: This function creates a message queue that allows threads to send and receive messages in a FIFO manner. Message queues are used for inter-task communication and data sharing between threads.
Usage: Ideal for passing data between threads, such as sensor readings or control commands.


Below is the struct used to define thread attributes
If you dont define a value to an attribute, then it will initialize to it's default value

```c
typedef struct {
    const char *name; /* Thread name */
    uint32_t attr_bits; /* Bitmask to configure the thread: this is meaningless in FreeR\
    TOS */
    void *cb_mem; /* Control block to hold thread's data (default: NULL).
    Used only for static allocation */
    uint32_t cb_size; /* Size of provided memory for control block (default: 0) */
    void *stack_mem; /* Pointer to the memory holding the thread stack (default: NULL)\
    Used only for static allocation */
    uint32_t stack_size; /* Size of provided memory for stack (default: 128 * 4) */
    osPriority_t priority; /* Initial thread priority (default: osPriorityNormal) */
    TZ_ModuleId_t tz_module; /* TrustZone module identifier (used in Cortex-M33 based MCUs) */
    uint32_t reserved; /* Reserved (must be 0) */
} osThreadAttr_t;
```

```c
/* Sample Thread Definition */

// This is the actual function/TASK that will be run in the thread
void blinkyThread (void *argument) {
  // ...
  for (;;) {
    // blink LED or something
  }
}
 
// Think of this as the handle for the thread
osThreadId_t blinkThreadID;

// Define attributes for the thread
const osThreadAttr_t blinkThread_attr = {
    .name = "blinkThread"
    .stack_size = 1024,                             // Create the thread stack with a size of 1024 bytes
    .priority = (osPriority_t) osPriorityNormal     
};

int main (void) {
    /* Init scheduler */
    osKernelInitialize()

    /* Creation of thread1 Task */
    blinkThreadID = osThreadNew(blinkThread, NULL, &blinkThread_attr);    // Create thread with custom sized stack memory
    
    /* Start scheduler */
    osKernelStart();

    /* We should never get here as control is now taken by the scheduler */
    while (1);
}
```

--- 
# TODO...

## Task 1: SPI Task
- Read data from accelerometer
- Send through UART line
- Priority: osPriorityNormal  

## Task 2: I2C Task
- Read data from Lux Sensor
- Send through UART line
- Priority: osPriorityNormal

## Task 3: ADC Task
- Read ADC data from potentiometer
- Send through UART line
- Priority: osPriorityNormal

## Task 4: Blink LED (Optional) Do this after everything before
- Suspend all tasks
- Blink LEDs three times
- This occurs every 5 seconds
- Priority: osPriorityAboveNormal

## Note:
You must include `"cmsis_os2.h"` in your task file in order to use the CMSIS RTOS API


