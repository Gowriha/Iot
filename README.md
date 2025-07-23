# Smart Dustbin using IoT

## Project Overview
The Smart Dustbin automates waste collection by:
- Opening the lid automatically when trash is detected
- Monitoring fill level, fire, gas, and weight
- Sending real-time data to the cloud and mobile app

## Scope
- Remote waste status monitoring
- Fire/gas/vibration alerts
- Data visualization on Blynk
- Reduced manual effort
- Ideal for smart homes and cities

## Components Used

| Component                | Quantity |
|--------------------------|----------|
| ESP32 Microcontroller    | 1        |
| Ultrasonic Sensors       | 2        |
| MG995 Servo Motor        | 1        |
| MQ2 Gas Sensor           | 1        |
| LM393 Flame Sensor       | 1        |
| SW-420 Vibration Sensor  | 1        |
| Jumper Wires             | As needed |

## Methodology

1. Sensors Integration
2. ESP32 Wi-Fi Communication
3. Servo Motor Control
4. Real-Time Blynk Alerts
5. Cloud Data Logging


## How It Works

Lid Automation: Opens via servo when object detected   
Level Detection: Ultrasonic sensor measures fullness    
Fire/Gas/Vibration Detection: Sends safety alerts  
Weight Monitoring: HX711 tracks garbage weight   
Data Display: All sensor data visualized in Blynk app  

## Communication Protocol

MQTT over Wi-Fi (via Blynk Cloud)  
Real-time two-way communication for control and updates

# Output

<img width="1150" height="675" alt="Screenshot 2025-07-23 at 5 39 46 PM" src="https://github.com/user-attachments/assets/498350d9-6dce-494b-9743-107acea96e6a" />
<img width="505" height="714" alt="Screenshot 2025-07-23 at 5 40 40 PM" src="https://github.com/user-attachments/assets/8399c698-98d7-499f-bfd8-c5f333a4f626" />
<img width="507" height="671" alt="Screenshot 2025-07-23 at 5 41 02 PM" src="https://github.com/user-attachments/assets/a729624f-8c5f-4985-9324-dc5d082111a1" />
