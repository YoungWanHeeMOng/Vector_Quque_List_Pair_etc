#include <SPI.h>
#include <SD.h>
#include <Json.h>

// for easier access
typedef JsonReader<2048> JsonReader2k;

// our reader. if we declare this locally it would require slightly over 2k on the stack
JsonReader2k jsonReader;

void dumpJsonFile() {
        // open data.json off the SD reader. You wired in an SD reader, right?
        File file = SD.open("/data.json", FILE_READ);
        if (!file) {
                Serial.println(F("/data.json not found or could not be opened"));
                while (true); // halt - no, no you did not. or you didn't insert the card
        }
        // initialize the reader with our file
        jsonReader.begin(file);

        // pull parsers return portions of the parse which you retrieve
        // by calling their parse/read method in a loop.
        while (jsonReader.read()) {
                // what kind of JSON element are we on?
                switch (jsonReader.nodeType()) {
                case JsonReader2k::Value: // we're on a scalar value
                        Serial.print("Value ");
                        switch (jsonReader.valueType()) { // what type of value?
                        case JsonReader2k::String: // a string!
                                Serial.print("String: ");
                                jsonReader.undecorate(); // remove all the nonsense
                                Serial.println(jsonReader.value()); // print it
                                break;
                        case JsonReader2k::Number: // a number!
                                Serial.print("Number: ");
                                Serial.println(jsonReader.numericValue()); // print it
                                break;
                        case JsonReader2k::Boolean: // a boolean! 
                                Serial.print("Boolean: ");
                                Serial.println(jsonReader.booleanValue()); // print it!
                                break;
                        case JsonReader2k::Null: // a null!
                                Serial.print("Null: ");
                                Serial.println("null"); // print it!
                                break;
                        }
                        break;
                case JsonReader2k::Key: // this is a key
                        Serial.print("Key ");
                        Serial.println(jsonReader.value());
                        break;
                case JsonReader2k::Object: // an object start {
                        Serial.println("Object");
                        break;
                case JsonReader2k::EndObject: // an object end }
                        Serial.println("End Object");
                        break;
                case JsonReader2k::Array: // an array start [
                        Serial.println("Array");
                        break;
                case JsonReader2k::EndArray: // an array end ]
                        Serial.println("End Array");
                        break;
                case JsonReader2k::Error: // a bad thing
                  // maybe we ran out of memory, or the document was poorly formed
                        Serial.println("Error!");
                        break;
                }
        }
        // don't forget this
        file.close();
}
void dumpId(bool recurse) {
        // open the file
        File file = SD.open("/data.json", FILE_READ);
        if (!file) {
                Serial.println(F("/data.json not found or could not be opened"));
                while (true); // halt
        }
        jsonReader.begin(file);
        // find the next field in the document named id. 
        // If recurse is specified, then subjects will be searched. 
        // Otherwise, only objects on this level of the hierarchy are considered.
        // Once we find it, read what comes right after it to get the value
        if (jsonReader.skipToField("id", recurse) && jsonReader.read()) {
                Serial.println((int32_t)jsonReader.numericValue(), DEC); // get the value as a number
        }
        // always close the file
        file.close();
}
void dumpShowName() {
        File file = SD.open("/data.json", FILE_READ);
        if (!file) {
                Serial.println(F("/data.json not found or could not be opened"));
                while (true); // halt
        }
        jsonReader.begin(file);
        // look for the field named "name" on this level of the hierarchy.
        // then read what comes right after it.
        if (jsonReader.skipToField("name") && jsonReader.read()) {
                jsonReader.undecorate(); // deescape the string
                Serial.println(jsonReader.value());
        }
        // close the file
        file.close();
}
void setup() {
        Serial.begin(115200);
        // initialize SD on default SPI bus and CS/SS
        if (!SD.begin()) {
                Serial.println(F("SD card mount failed"));
                while (true); // halt
        }
        //dumpJsonFile();
        dumpShowName();
        dumpId(true);
        dumpId(false);
}

void loop() {
        if (Serial.available()) {
                LexContext<1024> lc;
                lc.begin(Serial);
                while (LexContext<1024>::EndOfInput != lc.advance() && isdigit((char)lc.current())) {
                        Serial.print((char)lc.current());
                }
                Serial.println();
        }
}