bool isAnimation(){
  bool ans = true;
  if (scroll_items[show_scroll_item].animation=="String"){ans=false;}
  return ans;
}

void Reset_Animation_Variables(){
  //strip.clear();
  animation_int_1 = 0;
  animation_int_2 = 0;
  animation_int16_1 = 0;
  animation_int16_2 = 0;
}

void RunAnimation(){

  if (scroll_items[show_scroll_item].animation == "FourLetterScrollUp") { FourLetterScrollUp(); }

  if (scroll_items[show_scroll_item].animation == "StaticString") { StaticString(); }
  if (scroll_items[show_scroll_item].animation == "ScrollUpString") { ScrollUpString(); }

  if (scroll_items[show_scroll_item].animation == "ShowTime") { ShowTime(); }
  if (scroll_items[show_scroll_item].animation == "ShowTimeIsh") { ShowTimeIsh(); }
  
  
  if (scroll_items[show_scroll_item].animation == "RainbowString") { RainbowString(); }
  if (scroll_items[show_scroll_item].animation == "RainbowString2") { RainbowString2(); }
  if (scroll_items[show_scroll_item].animation == "NegativeString") { NegativeString(); }

  if (scroll_items[show_scroll_item].animation == "RainbowCycle") { RainbowCycle(); }
  if (scroll_items[show_scroll_item].animation == "RainbowCycle_MovingLeft") { RainbowCycle_MovingLeft(); }
  if (scroll_items[show_scroll_item].animation == "TheaterChase") { TheaterChase(); }  
  if (scroll_items[show_scroll_item].animation == "ColorWipe") { ColorWipe(); } 
  if (scroll_items[show_scroll_item].animation == "ColorWipe_Rainbow") { ColorWipe_Rainbow(); } 
}




void ShowTime(){
    matrix.fillScreen(matrix.Color(0,0,0));
    matrix.setTextSize(1);
    matrix.setTextColor(matrix.Color(scroll_items[show_scroll_item].green,scroll_items[show_scroll_item].red,scroll_items[show_scroll_item].blue));
    
    if (timeIsSet) {
      matrix.setCursor(10, 0);
      matrix.print(":"); 
      matrix.setCursor(0, 0); 
      matrix.print(hour()); 
      matrix.setCursor(15, 0); 
      matrix.print(minute()); 
    } else {
      matrix.setCursor(-1, 0); 
      matrix.print("Time?"); 
    }
    
    if(animation_int_1 <= 0) {
      matrix.show();
      animation_int_1++;
    } else {
      Load_Next_String();
    }    
}


void ShowTimeIsh(){
    matrix.fillScreen(matrix.Color(0,0,0));
    matrix.setTextSize(1);
    matrix.setTextColor(matrix.Color(scroll_items[show_scroll_item].green,scroll_items[show_scroll_item].red,scroll_items[show_scroll_item].blue));
    
    if (timeIsSet) {
      int hourint = hour()%12;
      if (hourint==0) {hourint = 12;}
      if (hourint>=10){
        matrix.setCursor(12, 0);
        matrix.print("ish"); 
        matrix.setCursor(1, 0); 
        matrix.print(hourint); 
      } else {
        matrix.setCursor(10, 0);
        matrix.print("ish"); 
        matrix.setCursor(3, 0); 
        matrix.print(hourint); 
      }
    } else {
      matrix.setCursor(-1, 0); 
      matrix.print("?????"); 
    }
    
    if(animation_int_1 <= 0) {
      matrix.show();
      animation_int_1++;
    } else {
      Load_Next_String();
    }    
}


void StaticString(){
    matrix.fillScreen(matrix.Color(0, 0, 0));
    matrix.setTextWrap(false); // add text wrap 
    matrix.setCursor(2, 0);
    matrix.setTextSize(1);
    matrix.setTextColor(matrix.Color(scroll_items[show_scroll_item].green,scroll_items[show_scroll_item].red,scroll_items[show_scroll_item].blue));
    matrix.print(scroll_items[show_scroll_item].scroll_txt); 
    matrix.setTextWrap(false);
         
    if(animation_int_1 <= 0) {
      matrix.show();
      animation_int_1++;
    } else {
      Load_Next_String();
    }    
}


void FourLetterScrollUp(){
    matrix.fillScreen(matrix.Color(0,0,0));
    matrix.setTextWrap(false);
    int new_pos = 2 * matrix.height() + animation_int_1;
    matrix.setCursor(2, new_pos);
    matrix.setTextSize(1);
    // RANDOM COLOUR & RANDOM STRING
    if (animation_int_2==0) {
      animation_int_2 = random(NUMITEMS(fourletterwords))+1;
      animation_int16_1 = random(256);
    }
    matrix.setTextColor(Wheel(animation_int16_1));
    matrix.print(fourletterwords[animation_int_2-1]); 
    matrix.setTextWrap(false);
    
    int signMsgHeight = -matrix.height(); 
    animation_int_1--;
    if(--new_pos >= signMsgHeight - 1) { 
      matrix.show();
    } else {
      Load_Next_String();
    }      
}


void ScrollUpString(){
    matrix.fillScreen(matrix.Color(0,0,0));
    matrix.setTextWrap(false);
    int new_pos = 2 * matrix.height() + animation_int_1;
    matrix.setCursor(2, new_pos);
    matrix.setTextSize(1);
    matrix.setTextColor(matrix.Color(scroll_items[show_scroll_item].green,scroll_items[show_scroll_item].red,scroll_items[show_scroll_item].blue));
    matrix.print(scroll_items[show_scroll_item].scroll_txt); 
    matrix.setTextWrap(false);
    
    int signMsgHeight = -matrix.height(); //Should work out how to do multiple lines
    animation_int_1--;
    if(--new_pos >= signMsgHeight - 1) {  //each character is 6 pixels,
      matrix.show();
    } else {
      Load_Next_String();
    }    
}



void NegativeString(){
    matrix.fillScreen(matrix.Color(scroll_items[show_scroll_item].green,scroll_items[show_scroll_item].red,scroll_items[show_scroll_item].blue));
    int new_pos = matrix.width() + animation_int_1;
    matrix.setCursor(new_pos, 0);
    matrix.setTextSize(1);
    matrix.setTextColor(matrix.Color(0,0,0));
    matrix.print(scroll_items[show_scroll_item].scroll_txt); 
    
    int signMsgLength = -scroll_items[show_scroll_item].scroll_txt.length()*6;
    animation_int_1--;
    if(--new_pos >= signMsgLength - 1) {  //each character is 6 pixels,
      matrix.show();
    } else {
      Load_Next_String();
    }    
}


void RainbowString(){
    matrix.fillScreen(matrix.Color(0, 0, 0)); //all background leds brightness
    int new_pos = matrix.width() + animation_int_1;
    matrix.setCursor(new_pos, 0);
    matrix.setTextSize(1);
    String s = scroll_items[show_scroll_item].scroll_txt;
    for (int x = 0; x < s.length(); x++){
        matrix.setTextColor(matrixWheel( (x * 256 / s.length() ) & 255));
        matrix.print(s[x]); 
    }
    
    int signMsgLength = -scroll_items[show_scroll_item].scroll_txt.length()*6;
    animation_int_1--;
    if(--new_pos >= signMsgLength - 1) {  //each character is 6 pixels,
      matrix.show();
    } else {
      Load_Next_String();
    }    
}


void RainbowString2(){
    matrix.fillScreen(matrix.Color(0, 0, 0)); //all background leds brightness
    int new_pos = matrix.width() + animation_int_1;
    matrix.setCursor(new_pos, 0);
    matrix.setTextSize(1);
    String s = scroll_items[show_scroll_item].scroll_txt;
    for (int x = 0; x < s.length(); x++){
        matrix.setTextColor(matrixWheel( (x * 6 * 256 / matrix.width() ) & 255));
        matrix.print(s[x]); 
    }
    
    int signMsgLength = -scroll_items[show_scroll_item].scroll_txt.length()*6;
    animation_int_1--;
    if(--new_pos >= signMsgLength - 1) {  //each character is 6 pixels,
      matrix.show();
    } else {
      Load_Next_String();
    }    
}


void RainbowCycle(){
  uint16_t i;
  if (animation_int16_1 >= 256*scroll_items[show_scroll_item].cycles) { // cycles of all colors on wheel
    //animation is finished 
    Load_Next_String();
  } else {
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + animation_int16_1) & 255));
    }
    strip.show();
    animation_int16_1++;
  }
}

void RainbowCycle_MovingLeft(){
  uint16_t i;
  if (animation_int16_1 >= 256*scroll_items[show_scroll_item].cycles) { // cycles of all colors on wheel
    //animation is finished 
    Load_Next_String();
  } else {
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) - animation_int16_1) & 255));
    }
    strip.show();
    animation_int16_1++;
  }
}


void ColorWipe() {
  if (animation_int16_1 >= strip.numPixels()) {
    //animation is finished 
    Load_Next_String();
  } else {
    strip.setPixelColor(animation_int16_1, strip.Color(scroll_items[show_scroll_item].red,scroll_items[show_scroll_item].green,scroll_items[show_scroll_item].blue));
    strip.show();
    animation_int16_1++;
  }
}

void ColorWipe_Rainbow() {
  if (animation_int16_1 >= strip.numPixels()) {
    //animation is finished 
    Load_Next_String();
  } else {
    strip.setPixelColor(animation_int16_1, Wheel(((animation_int16_1 * 256 / strip.numPixels()) ) & 255));    
    strip.show();
    animation_int16_1++;
  }
}


void TheaterChase() {
  if (animation_int_1>=3){
    animation_int_1=0;
    animation_int_2++; // count number of cycles
  }
  if (animation_int_2>=scroll_items[show_scroll_item].cycles) {
    //animation is finished 
    Load_Next_String();    
  } else {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+animation_int_1, strip.Color(scroll_items[show_scroll_item].red,scroll_items[show_scroll_item].green,scroll_items[show_scroll_item].blue));    //turn every third pixel on
      }
      for (uint16_t i=1; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+animation_int_1, 0);        //turn every third pixel off
      }
      strip.show();
      animation_int_1++; // move starting light by 1 each time  
  }
}



uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}


uint32_t matrixWheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return matrix.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return matrix.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return matrix.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}











