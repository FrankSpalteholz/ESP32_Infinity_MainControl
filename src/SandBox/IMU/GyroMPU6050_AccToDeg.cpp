// #include <Wire.h>
// #include <Adafruit_Sensor.h>
// #include <Adafruit_MPU6050.h>
// #include <Adafruit_I2CDevice.h>

// Adafruit_MPU6050 mpu;

// void setup() {
//   Serial.begin(115200);
//   while (!Serial)
//     delay(10); // for Leonardo/Micro/Zero

//   if (!mpu.begin()) {
//     Serial.println("Failed to find MPU6050 chip");
//     while (1) {
//       delay(10);
//     }
//   }
//   Serial.println("MPU6050 Found!");

//   mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
//   mpu.setGyroRange(MPU6050_RANGE_250_DEG);
// }

// void loop() {
//   sensors_event_t accel, gyro, temp;

//   mpu.getEvent(&accel, &gyro, &temp);

//   // Calculate rotation angles (in degrees)
//   float pitch = atan2(accel.acceleration.y, sqrt(accel.acceleration.x * accel.acceleration.x + accel.acceleration.z * accel.acceleration.z)) * 180 / PI;
//   float roll = atan2(-accel.acceleration.x, accel.acceleration.z) * 180 / PI;
//   float yaw = gyro.gyro.z;

//   Serial.print("Pitch: ");
//   Serial.print(pitch);
//   Serial.print(" degrees | Roll: ");
//   Serial.print(roll);
//   Serial.print(" degrees | Yaw: ");
//   Serial.print(yaw);
//   Serial.println(" degrees/sec");

//   delay(500);
// }
