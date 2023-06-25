/*
    Copyright 2021 Picovoice Inc.

    You may not use this file except in compliance with the license. A copy of the license is located in the "LICENSE"
    file accompanying this source.

    Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on
    an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the
    specific language governing permissions and limitations under the License.
*/

#include <Picovoice_EN.h>

#include "params.h"

#define MEMORY_BUFFER_SIZE (70 * 1024)

#define LED   13
#define RED   22     
#define BLUE  24     
#define GREEN 23

static const char* ACCESS_KEY = "yNtI3NY9Qb7yokf6ocvOMim+pZpscE7S7CzKcgwxVNxnz0pWAa6nyg==";

static pv_picovoice_t *handle = NULL;

static int8_t memory_buffer[MEMORY_BUFFER_SIZE] __attribute__((aligned(16)));

static const float PORCUPINE_SENSITIVITY = 0.75f;
static const float RHINO_SENSITIVITY = 0.5f;
static const float RHINO_ENDPOINT_DURATION_SEC = 1.0f;
static const bool RHINO_REQUIRE_ENDPOINT = true;

static void wake_word_callback(void) {
    Serial.println("Wake word detected!");
     
    digitalWrite(LED, HIGH); // turn the LED on  
}

static void inference_callback(pv_inference_t *inference) {
    Serial.println("{");
    Serial.print("    is_understood : ");
    Serial.println(inference->is_understood ? "true" : "false");
    if (inference->is_understood) {
        Serial.print("    intent : ");
        Serial.println(inference->intent);
        if (inference->num_slots > 0) {
            Serial.println("    slots : {");
            for (int32_t i = 0; i < inference->num_slots; i++) {
                Serial.print("        ");
                Serial.print(inference->slots[i]);
                Serial.print(" : ");
                Serial.println(inference->values[i]);
            }
            Serial.println("    }");
        }
    }
    Serial.println("}\n");

    if (inference->is_understood == 0) {
      AllLedsOff();
    }

    // Communication with ESP32
    if (inference->is_understood) {
      if (strcmp(inference->intent,"Flu") == 0) {
        Serial1.println('5');
        digitalWrite(GREEN,LOW);
        delay(1000);
        AllLedsOff();
      }
      if (strcmp(inference->intent,"Headache") == 0) {
        Serial1.println('6');
        digitalWrite(RED,LOW);
        delay(1000);
        AllLedsOff();
      }
      if (strcmp(inference->intent,"cough") == 0) {
        Serial1.println('7');
        digitalWrite(BLUE,LOW);
        delay(1000);
        AllLedsOff();
      }
      if (strcmp(inference->intent,"emergency") == 0) {
        Serial1.println('1');
        digitalWrite(RED,LOW);
        digitalWrite(GREEN,LOW);
        delay(1000);
        AllLedsOff();
      }
    }
    
    pv_inference_delete(inference);
}

void AllLedsOff() {
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, HIGH);
    digitalWrite(LED, LOW);
}

void setup() {
    pinMode(RED, OUTPUT);
    pinMode(BLUE, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
    Serial1.begin(9600);

    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, HIGH);

    pv_status_t status = pv_audio_rec_init();
    if (status != PV_STATUS_SUCCESS) {
        Serial.print("Audio init failed with ");
        Serial.println(pv_status_to_string(status));
        while (1);
    }

    status = pv_picovoice_init(
        ACCESS_KEY,
        MEMORY_BUFFER_SIZE,
        memory_buffer,
        sizeof(KEYWORD_ARRAY),
        KEYWORD_ARRAY,
        PORCUPINE_SENSITIVITY,
        wake_word_callback,
        sizeof(CONTEXT_ARRAY),
        CONTEXT_ARRAY,
        RHINO_SENSITIVITY,
        RHINO_ENDPOINT_DURATION_SEC,
        RHINO_REQUIRE_ENDPOINT,
        inference_callback,
        &handle);
    if (status != PV_STATUS_SUCCESS) {
        Serial.print("Picovoice init failed with ");
        Serial.println(pv_status_to_string(status));
        while (1);
    }

    const char *rhino_context = NULL;
    status = pv_picovoice_context_info(handle, &rhino_context);
    if (status != PV_STATUS_SUCCESS) {
        Serial.print("retrieving context info failed with");
        Serial.println(pv_status_to_string(status));
        while (1);
    }
    Serial.println("Wake word: Picovoice");
    Serial.println(rhino_context);
}

void loop()
{
    const int16_t *buffer = pv_audio_rec_get_new_buffer();
    if (buffer) {
        const pv_status_t status = pv_picovoice_process(handle, buffer);
        if (status != PV_STATUS_SUCCESS) {
            Serial.print("Picovoice process failed with ");
            Serial.println(pv_status_to_string(status));
            while(1);
        }
    }
}
