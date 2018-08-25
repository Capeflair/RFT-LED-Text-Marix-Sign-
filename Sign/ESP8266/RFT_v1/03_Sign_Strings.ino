void Load_Current_Sign_String(){
  matrix.fillScreen(matrix.Color(0, 0, 0)); //all background leds brightness
  matrix.setTextColor(matrix.Color(scroll_items[show_scroll_item].green,scroll_items[show_scroll_item].red,scroll_items[show_scroll_item].blue));
  matrix.setCursor(cursor_position, 0);
  matrix.setTextSize(1);
  matrix.print(scroll_items[show_scroll_item].scroll_txt);
}


void RunSignTextScroll(){
    Load_Current_Sign_String();
    int signMsgLength = -scroll_items[show_scroll_item].scroll_txt.length()*6;
    if(--cursor_position >= signMsgLength - 1) {  //each character is 6 pixels,
      matrix.show();
    } else {
      Load_Next_String();
    }  
}


void Reset_String_Cursor_Position(){
  matrix.fillScreen(matrix.Color(0, 0, 0)); //all background leds brightness
  Load_Current_Sign_String();
  cursor_position = matrix.width();
  Run_Sign_String();
}


void Setup_Sign_Strings(){
  Clear_Sign_Strings();
  Load_Default_Sign_Strings();
}

void Setup_Matrix(){
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(255);
  matrix.setTextColor(matrix.Color(10, 20, 0));
  Serial.println("Matrix Setup Complete");  
}

void Clear_Sign_Strings(){
  long current_millis = millis();
  for (int i = 0; i < MAX_SCROLL_ITEMS; i++) {
    scroll_items[i].scroll_txt = "";
    scroll_items[i].animation = "";
    scroll_items[i].delay = 0;
    scroll_items[i].prev_millis = current_millis;
    scroll_items[i].init_millis = current_millis;
    scroll_items[i].total_millis = -1;
    scroll_items[i].red = 0;    
    scroll_items[i].green = 0;    
    scroll_items[i].blue = 0;    
    scroll_items[i].cycles = 1;
  }
  show_scroll_item = -1;
  total_scroll_items = 0;
  cursor_position = 0;
}










