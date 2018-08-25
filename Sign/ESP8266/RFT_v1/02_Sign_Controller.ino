void Run_Sign_String(){
  if (isAnimation()) {
    RunAnimation();
  } else {
    RunSignTextScroll();
  }
}

void Load_Next_String(){
  Serial.print(show_scroll_item);
  Serial.print(" -> ");
  show_scroll_item++;
  if (show_scroll_item >= total_scroll_items) {
    show_scroll_item = 0;
  }
  Serial.println(show_scroll_item);
  if (isAnimation()) {
    Reset_Animation_Variables();
  } else {
    Reset_String_Cursor_Position();
  }
}


void Change_Brightness(int newVal){
  matrix.setBrightness(newVal);
  strip.setBrightness(newVal);
}

void Load_New_Strings_From_JSON(const String& _json){
  int new_total_string_count = 0;
  const size_t bufferSize = JSON_ARRAY_SIZE(MAX_SCROLL_ITEMS) + MAX_SCROLL_ITEMS*JSON_OBJECT_SIZE(8) + MAX_SCROLL_ITEMS*200;
  DynamicJsonBuffer jsonBuffer(bufferSize);
  JsonArray& root = jsonBuffer.parseArray(_json);

  JsonArray& root_ = root;
  
  long current_millis = millis();  


  for (int i = 0; i < MAX_SCROLL_ITEMS; i++) {
    JsonObject& root_to_use = root_[i];

    const char* cc_scroll_txt;
    const char* cc_animation;
    const char* cc_delay;
    const char* cc_red;
    const char* cc_green;
    const char* cc_blue;
    const char* cc_cycles;

    if (root_to_use.containsKey("scroll_txt")) { cc_scroll_txt = root_to_use["scroll_txt"]; } else { cc_scroll_txt = ""; }
    if (root_to_use.containsKey("animation")) { cc_animation = root_to_use["animation"]; } else { cc_animation = ""; }
    if (root_to_use.containsKey("delay")) { cc_delay = root_to_use["delay"]; } else { cc_delay = "0"; }
    if (root_to_use.containsKey("red")) { cc_red = root_to_use["red"]; } else { cc_red = "0"; }
    if (root_to_use.containsKey("green")) { cc_green = root_to_use["green"]; } else { cc_green = "0"; }
    if (root_to_use.containsKey("blue")) { cc_blue = root_to_use["blue"]; } else { cc_blue = "0"; }
    if (root_to_use.containsKey("cycles")) { cc_cycles = root_to_use["cycles"]; } else { cc_cycles = "0"; }


    Serial.print(i);
    Serial.print(" : ");
    Serial.print(cc_scroll_txt);
    Serial.print(" : ");

    scroll_items[i].scroll_txt = (String)cc_scroll_txt;
    scroll_items[i].animation = (String)cc_animation;
    Serial.println(cc_animation);
    if (strlen(cc_animation)>0){ new_total_string_count++; }

    scroll_items[i].delay = (uint16_t)atoi(cc_delay);

    scroll_items[i].red = (uint8_t)atoi(cc_red);
    scroll_items[i].green = (uint8_t)atoi(cc_green);
    scroll_items[i].blue = (uint8_t)atoi(cc_blue);
    scroll_items[i].cycles = (uint8_t)atoi(cc_cycles);

    scroll_items[i].init_millis = current_millis;
    
    if (i==0){
      // reset sign, so nothing weird is shown.
      show_scroll_item = 0;
      total_scroll_items = 1;
      if (isAnimation()) {
        Reset_Animation_Variables();
      } else {
        Reset_String_Cursor_Position();
      }
    }
    total_scroll_items = new_total_string_count;
  }
  Serial.println(total_scroll_items);
}
