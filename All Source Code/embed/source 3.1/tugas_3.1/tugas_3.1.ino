/**
* TaskScheduler Test
*
* Initially only tasks 1 and 2 are enabled
* Task1 runs every 2 seconds 10 times and then stops
* Task2 runs every 3 seconds indefinitely
* Task1 enables Task3 at its first run
* Task3 run every 5 seconds
* Task1 disables Task3 on its last iteration and changed Task2 to run every 1/2 seconds
* At the end Task2 is the only task running every 1/2 seconds
*/
#include <TaskScheduler.h>
// Callback methods prototypes
void t1Callback();
void t2Callback();
void t3Callback();
void t4Callback();
void t5Callback();

//Tasks
Task t1(2000, 10, &t1Callback);//task 1 runs every 2000ms 10 times only
Task t2(3000, TASK_FOREVER, &t2Callback);//task 2 runs every 3000ms forever
Task t3(5000, TASK_FOREVER, &t3Callback);//task 3 runs every 5000ms forever
Task t4(10000, TASK_FOREVER,&t4Callback);
Task t5(20000, TASK_FOREVER,&t5Callback);

Scheduler runner;
void t1Callback() {
Serial.print("t1: ");
Serial.println(millis());
if (t1.isFirstIteration()) {
runner.addTask(t3);//add task 3 to chain
t3.enable();//enable task 3
Serial.println("t1: enabled t3 and added to the chain");
runner.addTask(t4);
t4.enable();
Serial.println("t1: enabled t4 and added to the chain");
runner.addTask(t5);//add task 3 to chain
t5.enable();//enable task 3
Serial.println("t1: enabled t5 and added to the chain");
}
if (t1.isLastIteration()) {
t3.disable();//disable task 3
runner.deleteTask(t3);

t2.setInterval(500);
t4.setInterval(2000);
t5.setInterval(5000);
Serial.println("t1: disable t3 and delete it from the chain. t2 interval set to 500\nt4 interval to 2000\nt5 interval to 5000");
}
}
void t2Callback() {
Serial.print("t2: ");
Serial.println(millis());
}
void t3Callback() {
Serial.print("t3: ");
Serial.println(millis());
}
void t4Callback() {
Serial.print("t4: ");
Serial.println(millis());
}
void t5Callback() {
Serial.print("t5: ");
Serial.println(millis());
}
void setup () {
Serial.begin(115200);
Serial.println("Scheduler TEST");
runner.init();
Serial.println("Initialized scheduler");
runner.addTask(t1);//add task 1 to chain
Serial.println("added t1");
runner.addTask(t2);//add task 2 to chain
Serial.println("added t2");
delay(5000);
t1.enable();//enable task 1
Serial.println("Enabled t1");
t2.enable();//enable task 2
Serial.println("Enabled t2");
}
void loop () {
runner.execute();//execute task scheduler
}
