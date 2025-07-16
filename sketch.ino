#include <Wire.h>
#include <Adafruit_SSD1306.h>

// Pin Definitions
#define SOUND_SENSOR_PIN 34   // Microphone output
#define BUZZER_PIN 25         // Buzzer
#define LED_PIN 2             // LED
#define LOW_SOUND_THRESHOLD 60  // Adjust based on testing
#define HIGH_SOUND_THRESHOLD 100

// OLED Display Settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
    Serial.begin(115200);

    // Pin Modes
    pinMode(SOUND_SENSOR_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);

    // Initialize OLED Display
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println("SSD1306 allocation failed!");
        while (1);
    }
    
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(10, 10);
    display.println("Sound Detector Ready");
    display.display();
    delay(2000);
}

void loop() {
    int soundLevel = analogRead(SOUND_SENSOR_PIN);
    float voltage = soundLevel * (3.3 / 4095.0);
    float dB = 20 * log10(voltage / 0.00631);
    Serial.print("Sound Level: ");
    Serial.println(soundLevel);

    if (dB >= LOW_SOUND_THRESHOLD && dB <= HIGH_SOUND_THRESHOLD) {
        digitalWrite(LED_PIN, HIGH);
        digitalWrite(BUZZER_PIN, HIGH);

        // Update OLED display
        display.clearDisplay();
        display.setCursor(10, 10);
        display.println("Loud Sound Detected!");
        display.display();
        delay(30000);
    }
    
    else {
        digitalWrite(LED_PIN, LOW);
        digitalWrite(BUZZER_PIN, LOW);

        // Keep OLED normal
        display.clearDisplay();
        display.setCursor(10, 10);
        display.println("Normal Sound");
        display.display();
    }

    delay(500);
}
